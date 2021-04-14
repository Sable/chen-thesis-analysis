// Parsing time (ms): 0.287
static I horse_main(V *h_rtn);


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
    PROFILE(18, pfnCompress(t32, t26, t7));
    PROFILE(19, pfnCompress(t33, t26, t8));
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

// Compiling time (ms): 0.151
