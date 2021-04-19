static I horse_main(V *h_rtn);
//#define myfabs(x) ((x)>=0?(x):-(x))
// exp, fabs, sqrt

#ifdef LINUX_ASSEMBLY
    #include <Math.h>
    // flt64_t --> double
    #define myexp(x) Math_Exp_flt64(x) // faster
    #define mylog(x) Math_Log_flt64(x) // faster
#else
    #define myexp(x) exp(x)
    #define mylog(x) log(x)
#endif

static I horse_CNDF_opt(V *rtn, V *args){
    V InputX   = args[0];
    V invs2xPI = args[1];
    V OutputX = incV();
    L r0 = vn(InputX);
    initV(OutputX, H_E, r0);
    if(!isGPU){
        tic();
        DOP(r0, {
                E xK2 = 1.0 / (1.0 + 0.2316419 * fabs(vE(InputX,i)));
                E xK2_2 = xK2 * xK2;
                E xK2_3 = xK2 * xK2_2;
                E xK2_4 = xK2 * xK2_3;
                E xLocal=1.0-ve(invs2xPI)*myexp(-0.5*vE(InputX,i)*vE(InputX,i))*((xK2_2 * -0.356563782) + (xK2_3 * 1.781477937) + (xK2_4 * -1.821255978) + xK2 * xK2_4 * 1.330274429 + xK2 * 0.319381530);
                vE(OutputX,i)=(vE(InputX,i)<0?(1.0-xLocal):xLocal);
                })
        total_key += calc_toc();
    }
    else {
        E *x0 = sE(InputX);
        E  x1 = ve(invs2xPI);
        E *z0 = sE(OutputX);
        E time_kernel = 0;
        tic();
#pragma acc data copyin(x0[0:r0]) copyout(z0[0:r0])
        {
            tic();
#pragma acc parallel loop
            for(L i=0; i<r0; i++){
                E xK2 = 1.0 / (1.0 + 0.2316419 * fabs(x0[i]));
                E xK2_2 = xK2 * xK2;
                E xK2_3 = xK2 * xK2_2;
                E xK2_4 = xK2 * xK2_3;
                E xLocal=1.0-x1*myexp(-0.5*x0[i]*x0[i])*((xK2_2 * -0.356563782) + (xK2_3 * 1.781477937) + (xK2_4 * -1.821255978) + xK2 * xK2_4 * 1.330274429 + xK2 * 0.319381530);
                z0[i]=(x0[i]<0?(1.0-xLocal):xLocal);
            }
            time_kernel = calc_toc();
            P("Kernel execution time (ms): %g\n", time_kernel);
        }
        E time_gpu = calc_toc();
        total_kernel += time_kernel;
        total_data   += time_gpu - time_kernel;
    }
    rtn[0] = OutputX;
    R 0;
}

static I horse_BlkSchls_opt(V *rtn, V *args){
	V sptprice   = args[0];
	V strike     = args[1];
	V rate       = args[2];
	V divq       = args[3];
	V volatility = args[4];
	V time       = args[5];
	V otype      = args[6];
	V divs       = args[7];
	V dfrefval   = args[8];
    L r0 = vn(sptprice);
    V xD1        = incV();
    V xD2        = incV();
    V NofXd1     = incV();
    V NofXd2     = incV();
    V invs2xPI   = incV();
    V OptionPrice= incV();
    V tempV[10]; // temporary return vars
    initV(xD1, H_E, r0);
    initV(xD2, H_E, r0);
    if(!isGPU){
        tic();
        DOP(r0, { E xDen = vE(volatility,i) * sqrt(vE(time,i));
                vE(xD1,i)=((vE(rate,i)+vE(volatility,i)*vE(volatility,i)*0.5)*vE(time,i) + mylog(vE(sptprice,i)/vE(strike,i)))/xDen;
                vE(xD2,i)=vE(xD1,i)-xDen; })
            PROFILE(15, copyV(invs2xPI, LiteralF64(0.39894228040143270286)));
        total_key += calc_toc();
    }
    else {
        E time_kernel = 0;
        E *x0 = sE(volatility);
        E *x1 = sE(sptprice);
        E *x2 = sE(time);
        E *x3 = sE(rate);
        E *x4 = sE(strike);
        E *z0 = sE(xD1);
        E *z1 = sE(xD2);
        tic();
#pragma acc data copyin(x0[0:r0],x1[0:r0],x2[0:r0],x3[0:r0],x4[0:r0]) copyout(z0[0:r0],z1[0:r0])
        {
            tic();
#pragma acc parallel loop
            for(L i=0; i<r0; i++){
                E xDen = x0[i] * sqrt(x2[i]);
                z0[i]=((x3[i]+x0[i]*x0[i]*0.5)*x2[i] + mylog(x1[i]/x4[i]))/xDen;
                z1[i]=z0[i]-xDen;
            }
            time_kernel = calc_toc();
            P("Kernel execution time (ms): %g\n", time_kernel);
        }
        E time_gpu = calc_toc();
        total_kernel += time_kernel;
        total_data   += time_gpu - time_kernel;
    }
    PROFILE(15, copyV(invs2xPI, LiteralF64(0.39894228040143270286)));
    // tic();
    HORSE_UDF(16, horse_CNDF_opt(tempV, (V []){xD1, invs2xPI}), *NofXd1 = *tempV[0]);
    HORSE_UDF(17, horse_CNDF_opt(tempV, (V []){xD2, invs2xPI}), *NofXd2 = *tempV[0]);
    // horse_CNDF_opt(tempV, (V []){xD1, invs2xPI}); NofXd1 = tempV[0];
    // horse_CNDF_opt(tempV, (V []){xD2, invs2xPI}); NofXd2 = tempV[0];
    // toc(); // matlab: 33.5 ms
    initV(OptionPrice, H_E, r0);
    //tic();
    //DOP(r0, vE(OptionPrice,i)=vE(strike,i) * myexp(-1*vE(rate,i)*vE(time,i)))
    //toc(); getchar();
    if(!isGPU){
        tic();
        DOP(r0, {
                E FutureValueX = vE(strike,i) * myexp(-1*vE(rate,i)*vE(time,i));
                vE(OptionPrice,i)=vB(otype,i)?(FutureValueX * (1.0-vE(NofXd2,i))-vE(sptprice,i) * (1.0-vE(NofXd1,i))):(vE(sptprice,i)*vE(NofXd1,i) - FutureValueX * vE(NofXd2,i)); })
        total_key += calc_toc();
    }
    else {
        E time_kernel = 0;
        E *x0 = sE(strike);
        B *x1 = sB(otype);
        E *x2 = sE(rate);
        E *x3 = sE(time);
        E *x4 = sE(NofXd1);
        E *x5 = sE(NofXd2);
        E *x6 = sE(sptprice);
        E *z0 = sE(OptionPrice);
        tic();
#pragma acc data copyin(x0[0:r0],x1[0:r0],x2[0:r0],x3[0:r0],x4[0:r0],x4[0:r0]) copyout(z0[0:r0])
        {
            tic();
#pragma acc parallel loop
            for(L i=0; i<r0; i++){
                E FutureValueX = x0[i] * myexp(-1*x2[i]*x3[i]);
                z0[i]=x1[i]?(FutureValueX * (1.0-x5[i])-x6[i] * (1.0-x4[i])):(x6[i]*x4[i] - FutureValueX * x5[i]);
            }
            time_kernel = calc_toc();
            P("Kernel execution time (ms): %g\n", time_kernel);
        }
        E time_gpu = calc_toc();
        total_kernel += time_kernel;
        total_data   += time_gpu - time_kernel;
    }
    //WP("option price: %lld\n", vn(OptionPrice));
    //printV2(OptionPrice, 20); getchar();
    rtn[0] = OptionPrice;
    R 0;
}


static I horse_main(V *h_rtn){
    V t0 = incV(); V t6 = incV(); V t7 = incV(); V t8 = incV();
    V t20 = incV(); V t12 = incV(); V t21 = incV(); V t22 = incV();
    V t23 = incV(); V t32 = incV(); V t24 = incV(); V t33 = incV();
    V t25 = incV(); V t26 = incV(); V t18 = incV(); V t43 = incV();
    V t19 = incV(); V t44 = incV(); V t45 = incV(); V t46 = incV();
    V t47 = incV();
    V sptprice   = incV();
    V strike     = incV();
    V rate       = incV();
    V divq       = incV();
    V volatility = incV();
    V time       = incV();
    V optiontype = incV();
    V divs       = incV();
    V dgrefval   = incV();
    V columnname = incV();
    V columnvalue= incV();
    V optionprice= incV();
    V otype      = incV();
    V result     = incV();
    V tempV[10]; // temporary return vars
    PROFILE(1 , pfnLoadTable(t0, LiteralSymbol("blackscholes")));
    PROFILE(2 , pfnColumnValue(sptprice  , t0, LiteralSymbol("sptprice")));
    PROFILE(3 , pfnColumnValue(strike    , t0, LiteralSymbol("strike")));
    PROFILE(4 , pfnColumnValue(rate      , t0, LiteralSymbol("rate")));
    PROFILE(5 , pfnColumnValue(divq      , t0, LiteralSymbol("divq")));
    PROFILE(6 , pfnColumnValue(volatility, t0, LiteralSymbol("volatility")));
    PROFILE(7 , pfnColumnValue(time      , t0, LiteralSymbol("time")));
    PROFILE(8 , pfnColumnValue(optiontype, t0, LiteralSymbol("optiontype")));
    PROFILE(9 , pfnColumnValue(divs      , t0, LiteralSymbol("divs")));
    PROFILE(10, pfnColumnValue(dgrefval  , t0, LiteralSymbol("dgrefval")));
    PROFILE(11, pfnEq(otype, optiontype, LiteralChar('P')));
    HORSE_UDF(99, horse_BlkSchls_opt(tempV, (V []){sptprice,strike,rate,divq,volatility,time,otype,divs,dgrefval}), *optionprice = *tempV[0]);
    PROFILE(11, copyV(columnname, LiteralVectorSymbol(3, (S []){"optiontype", "sptprice", "optionprice"})));
    PROFILE(12, pfnList(columnvalue, 3, (V []){optiontype,sptprice,optionprice}));
    PROFILE(13, pfnTable(result, columnname, columnvalue));
    h_rtn[0] = result;
    return 0;
}

E horse_entry(){
    V rtns[99];
    tic();
    HORSE_UDF(0, horse_main(rtns), {});
    E elapsed = calc_toc();
    P("The elapsed time (ms): %g\n", elapsed);
    P("Output:\n");
    DOI(1, printV2(rtns[i],20))
    return elapsed;
}
