// Parsing time (ms): 0.289
static I horse_main(V *h_rtn);
static I horse_morgan(V *h_rtn, V n, V x, V y);
static I horse_msum(V *h_rtn, V n, V a);

static B isNaive = false;
// static B isNaive = true;

static E horse_entry(){
    V rtns[99];
    tic();
    HORSE_UDF(0, horse_main(rtns), {});
    E elapsed = calc_toc();
    P("The elapsed time (ms): %g\n", elapsed);
    P("Output:\n");
    DOI(1, printV2(rtns[i],10))
    return elapsed;
}

static I horse_main(V *h_rtn){
    V mg = incV(); V result = incV(); V column_x = incV(); V column_y = incV(); 
    V n = incV(); V rtn_name = incV(); V rtn = incV(); V rtn_value = incV(); 
    V tempV[10];
    PROFILE(45, pfnLoadTable(mg, initLiteralSym("morgan")));
    PROFILE(46, copyV(n,initLiteralI64(1000)));
    PROFILE(47, pfnColumnValue(column_x, mg, initLiteralSym("x")));
    PROFILE(48, pfnColumnValue(column_y, mg, initLiteralSym("y")));
    HORSE_UDF(49, horse_morgan(tempV, n, column_x, column_y), *rtn=*tempV[0]);
    PROFILE(50, copyV(rtn_name,initLiteralSym("result")));
    PROFILE(51, pfnList(rtn_value, 1, (V []){rtn}));
    PROFILE(52, pfnTable(result, rtn_name, rtn_value));
    h_rtn[0] = result;
    return 0;
}

static I horse_morgan(V *h_rtn, V n, V x, V y){
    V result = incV(); V mc_t0 = incV(); V mc_t1 = incV(); V mc_t2 = incV(); 
    V mc_t3 = incV(); V mc_t4 = incV(); V mc_t5 = incV(); V mc_t6 = incV(); 
    V mc_t7 = incV(); V sx = incV(); V mc_t8 = incV(); V sy = incV(); 
    V mc_t9 = incV(); V mc_t10 = incV(); V mc_t11 = incV(); V mc_t20 = incV(); 
    V mc_t12 = incV(); V mc_t21 = incV(); V mc_t13 = incV(); V mc_t14 = incV(); 
    V mc_t22 = incV(); V mc_t15 = incV(); V mc_t23 = incV(); V mc_t16 = incV(); 
    V mc_t24 = incV(); V mc_t17 = incV(); V mc_t25 = incV(); V mc_t18 = incV(); 
    V mc_t26 = incV(); V mc_t19 = incV(); V mc_t27 = incV(); V mc_t28 = incV(); 
    V sx2 = incV(); V sy2 = incV(); V part1 = incV(); V part2 = incV(); 
    V part3 = incV(); V sxy = incV(); 
    V tempV[10]; // temporary return vars
    if(isNaive){
        HORSE_UDF(4, horse_msum(tempV,n,x), *sx=*tempV[0]);
    }
    else
    {
        V in1_t = incV(), in1_t3 = incV(), in1_t6 = incV();
        PROFILE(1, pfnCumsum(in1_t, x));
        L in1_len = vn(x);
        L in1_size1 = in1_len-vl(n);
        initV(in1_t3, H_E, in1_size1);
        DOP(in1_size1, vE(in1_t3,i)=vE(in1_t,i+vl(n)))
        L in1_size2 = in1_len-vl(n);
        initV(in1_t6, H_E, in1_size2);
        DOP(in1_size2, vE(in1_t6,i)=vE(in1_t,i))
        pfnMinus(sx, in1_t3, in1_t6);
    }
    if(isNaive){
        HORSE_UDF(5, horse_msum(tempV,n,y), *sy=*tempV[0]);
    }
    else
    {
        V in2_t = incV(), in2_t3 = incV(), in2_t6 = incV();
        PROFILE(1, pfnCumsum(in2_t, y));
        L in2_len = vn(y);
        L in2_size1 = in2_len-vl(n);
        initV(in2_t3, H_E, in2_size1);
        DOP(in2_size1, vE(in2_t3,i)=vE(in2_t,i+vl(n)))
        L in2_size2 = in2_len-vl(n);
        initV(in2_t6, H_E, in2_size2);
        DOP(in2_size2, vE(in2_t6,i)=vE(in2_t,i))
        pfnMinus(sy, in2_t3, in2_t6);
    }
    PROFILE(6, copyV(mc_t0,n));
    PROFILE(7, copyV(mc_t22,initLiteralF64(2)));
    PROFILE(8, pfnPower(mc_t1, x, mc_t22));
    if(isNaive){
        HORSE_UDF(9, horse_msum(tempV,mc_t0, mc_t1), *sx2=*tempV[0]);
    }
    else
    {
        V in3_t = incV(), in3_t3 = incV(), in3_t6 = incV();
        PROFILE(1, pfnCumsum(in3_t, mc_t1));
        L in3_len = vn(mc_t1);
        L in3_size1 = in3_len-vl(n);
        initV(in3_t3, H_E, in3_size1);
        DOP(in3_size1, vE(in3_t3,i)=vE(in3_t,i+vl(n)))
        L in3_size2 = in3_len-vl(n);
        initV(in3_t6, H_E, in3_size2);
        DOP(in3_size2, vE(in3_t6,i)=vE(in3_t,i))
        pfnMinus(sx2, in3_t3, in3_t6);
    }
    PROFILE(10, copyV(mc_t2,n));
    PROFILE(11, copyV(mc_t23,initLiteralF64(2)));
    PROFILE(12, pfnPower(mc_t3, y, mc_t23));
    if(isNaive){
        HORSE_UDF(13, horse_msum(tempV,mc_t2, mc_t3), *sy2=*tempV[0]);
    }
    else
    {
        V in4_t = incV(), in4_t3 = incV(), in4_t6 = incV();
        PROFILE(1, pfnCumsum(in4_t, mc_t3));
        L in4_len = vn(mc_t3);
        L in4_size1 = in4_len-vl(n);
        initV(in4_t3, H_E, in4_size1);
        DOP(in4_size1, vE(in4_t3,i)=vE(in4_t,i+vl(n)))
        L in4_size2 = in4_len-vl(n);
        initV(in4_t6, H_E, in4_size2);
        DOP(in4_size2, vE(in4_t6,i)=vE(in4_t,i))
        pfnMinus(sy2, in4_t3, in4_t6);
    }
    PROFILE(14, copyV(mc_t4,n));
    PROFILE(15, pfnMul(mc_t5, x, y));
    if(isNaive){
        HORSE_UDF(16, horse_msum(tempV,mc_t4, mc_t5), *sxy=*tempV[0]);
    }
    else
    {
        V in5_t = incV(), in5_t3 = incV(), in5_t6 = incV();
        PROFILE(1, pfnCumsum(in5_t, mc_t5));
        L in5_len = vn(mc_t5);
        L in5_size1 = in5_len-vl(n);
        initV(in5_t3, H_E, in5_size1);
        DOP(in5_size1, vE(in5_t3,i)=vE(in5_t,i+vl(n)))
        L in5_size2 = in5_len-vl(n);
        initV(in5_t6, H_E, in5_size2);
        DOP(in5_size2, vE(in5_t6,i)=vE(in5_t,i))
        pfnMinus(sxy, in5_t3, in5_t6);
    }
    if(isNaive){
        PROFILE(17, pfnDiv(mc_t8, sy2, n));
        PROFILE(18, pfnDiv(mc_t10, sy, n));
        PROFILE(19, copyV(mc_t24,initLiteralF64(2)));
        PROFILE(20, pfnPower(mc_t9, mc_t10, mc_t24));
        PROFILE(21, pfnMinus(mc_t7, mc_t8, mc_t9));
        PROFILE(22, pfnAbs(mc_t6, mc_t7));
        PROFILE(23, copyV(mc_t25,initLiteralF64(0.5)));
        PROFILE(24, pfnPower(part3, mc_t6, mc_t25));
        PROFILE(25, pfnDiv(mc_t13, sx2, n));
        PROFILE(26, pfnDiv(mc_t15, sx, n));
        PROFILE(27, copyV(mc_t26,initLiteralF64(2)));
        PROFILE(28, pfnPower(mc_t14, mc_t15, mc_t26));
        PROFILE(29, pfnPlus(mc_t12, mc_t13, mc_t14));
        PROFILE(30, pfnAbs(mc_t11, mc_t12));
        PROFILE(31, copyV(mc_t27,initLiteralF64(0.5)));
        PROFILE(32, pfnPower(part2, mc_t11, mc_t27));
        PROFILE(33, pfnDiv(mc_t16, sxy, n));
        PROFILE(34, pfnMul(mc_t18, sx, sy));
        PROFILE(35, copyV(mc_t28,initLiteralF64(2)));
        PROFILE(36, pfnPower(mc_t19, n, mc_t28));
        PROFILE(37, pfnDiv(mc_t17, mc_t18, mc_t19));
        PROFILE(38, pfnMinus(part1, mc_t16, mc_t17));
        PROFILE(39, copyV(mc_t20,part1));
        PROFILE(40, pfnMul(mc_t21, part2, part3));
        PROFILE(41, pfnDiv(result, mc_t20, mc_t21));
    }
    else {
        L r0 = vn(sx);
        L n0 = vl(n);
        initV(result, H_E, r0);
        DOP(r0, vE(result,i)=(vE(sxy,i)/n0-vE(sx,i)*vE(sy,i)/pow(n0,2))/(
                             sqrt(fabs(vE(sx2,i)/n0+pow(vE(sx,i)/n0,2)))*
                             sqrt(fabs(vE(sy2,i)/n0-pow(vE(sy,i)/n0,2)))
                             )
           )
    }
    h_rtn[0] = result;
    return 0;
}

static I horse_msum(V *h_rtn, V n, V a){
    V t = incV(); V t_len= incV();
    V t0= incV(); V t1 = incV(); V t2= incV(); V t3 = incV(); 
    V t4= incV(); V t5 = incV(); V t6= incV(); V result = incV(); 
    PROFILE(1, pfnCumsum(t, a));
    PROFILE(2, pfnLen(t_len, a));
    PROFILE(3, pfnMinus(t0, t_len, n));
    PROFILE(4, pfnRange(t1, t0));
    PROFILE(5, pfnPlus(t2, t1, n));
    PROFILE(6, pfnIndex(t3, t, t2));
    PROFILE(7, pfnMinus(t4, t_len, n));
    PROFILE(8, pfnRange(t5, t4));
    PROFILE(9, pfnIndex(t6, t, t5));
    PROFILE(10, pfnMinus(result, t3, t6));
    h_rtn[0] = result;
    return 0;
}

