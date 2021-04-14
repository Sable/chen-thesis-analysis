// Parsing time (ms): 0.262
static I horse_main(V *h_rtn);
static I q6_patterncompress_0(V *z, V x, V *y);

static I q6_patterncompress_0(V *z, V x, V *y){
    V z0 = z[0]; // t32
    V z1 = z[1]; // t33
    V y0 = y[0]; // t7
    V y1 = y[1]; // t8
    L len = vn(x), k = 0;
    L lenZ = 0, parZ[H_CORE], offset[H_CORE];
    DOI(H_CORE, parZ[i]=offset[i]=0)
    CHECKE(getNumOfNonZero(x,parZ));
    DOI(H_CORE, lenZ += parZ[i])
    DOIa(H_CORE, offset[i]=parZ[i-1]+offset[i-1])
    initV(z0,H_E,lenZ);
    initV(z1,H_E,lenZ);
    DOT(len, if(vB(x,i)){L c=offset[tid]++;\
        vE(z0,c) = vE(y0,i);\
        vE(z1,c) = vE(y1,i);\
    })
    R 0;
}


static I horse_main(V *h_rtn){
    V t0 = incV(); V t6 = incV(); V t7 = incV(); V t8 = incV(); 
    V t20 = incV(); V t12 = incV(); V t21 = incV(); V t22 = incV(); 
    V t23 = incV(); V t32 = incV(); V t24 = incV(); V t33 = incV(); 
    V t25 = incV(); V t26 = incV(); V t18 = incV(); V t43 = incV(); 
    V t19 = incV(); V t44 = incV(); V t45 = incV(); V t46 = incV(); 
    V t47 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("lineitem")));
    PROFILE(5, pfnColumnValue(t6, t0, LiteralSymbol("l_quantity")));
    PROFILE(6, pfnColumnValue(t7, t0, LiteralSymbol("l_extendedprice")));
    PROFILE(7, pfnColumnValue(t8, t0, LiteralSymbol("l_discount")));
    PROFILE(8, pfnColumnValue(t12, t0, LiteralSymbol("l_shipdate")));
    PROFILE(9, pfnGeq(t18, t12, LiteralDate(19940101)));
    PROFILE(10, pfnLt(t19, t12, LiteralDate(19950101)));
    PROFILE(11, pfnAnd(t20, t18, t19));
    PROFILE(12, pfnLt(t21, t6, LiteralF64(24)));
    PROFILE(13, pfnGeq(t22, t8, LiteralF64(0.05)));
    PROFILE(14, pfnLeq(t23, t8, LiteralF64(0.07)));
    PROFILE(15, pfnAnd(t24, t22, t23));
    PROFILE(16, pfnAnd(t25, t20, t21));
    PROFILE(17, pfnAnd(t26, t25, t24));
    PROFILE(19, q6_patterncompress_0((V []){t32, t33}, t26, (V []){t7, t8}));
    PROFILE(20, pfnMul(t43, t32, t33));
    PROFILE(21, pfnSum(t44, t43));
    PROFILE(22, copyV(t45,LiteralSymbol("revenue")));
    PROFILE(23, pfnList(t46, 1, (V []){t44}));
    PROFILE(24, pfnTable(t47, t45, t46));
    h_rtn[0] = t47;
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

// Compiling time (ms): 0.37
