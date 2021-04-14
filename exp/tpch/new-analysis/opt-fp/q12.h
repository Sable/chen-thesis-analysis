// Parsing time (ms): 0.604
static I horse_main(V *h_rtn);
static I q12_peephole_fp1_0(V z, V x, V y);
static I q12_peephole_fp1_1(V z, V x, V y);

static I q12_peephole_fp1_0(V z, V x, V y){
    // z -> t104
    initV(z, H_L, vn(y));
    DOP(vn(y), {I a=0; V t=vV(y,i); DOJ(vn(t), a+=vI(x,vL(t,j))) vL(z,i)=a;}) R 0;
}

static I q12_peephole_fp1_1(V z, V x, V y){
    // z -> t107
    initV(z, H_L, vn(y));
    DOP(vn(y), {I a=0; V t=vV(y,i); DOJ(vn(t), a+=vI(x,vL(t,j))) vL(z,i)=a;}) R 0;
}


static I horse_main(V *h_rtn){
    V t100 = incV(); V t98 = incV(); V t101 = incV(); V t99 = incV(); 
    V t110 = incV(); V t102 = incV(); V t111 = incV(); V t103 = incV(); 
    V t112 = incV(); V t104 = incV(); V t113 = incV(); V t105 = incV(); 
    V t114 = incV(); V t106 = incV(); V t115 = incV(); V t107 = incV(); 
    V t108 = incV(); V t109 = incV(); V t0 = incV(); V t1 = incV(); 
    V t20 = incV(); V t12 = incV(); V t21 = incV(); V t13 = incV(); 
    V t22 = incV(); V t14 = incV(); V t23 = incV(); V t24 = incV(); 
    V t16 = incV(); V t25 = incV(); V t26 = incV(); V t18 = incV(); 
    V t51 = incV(); V t27 = incV(); V t19 = incV(); V t44 = incV(); 
    V t55 = incV(); V t72 = incV(); V t56 = incV(); V t57 = incV(); 
    V t90 = incV(); V t91 = incV(); V t83 = incV(); V t92 = incV(); 
    V t84 = incV(); V t93 = incV(); V t85 = incV(); V t94 = incV(); 
    V t86 = incV(); V t95 = incV(); V t87 = incV(); V t79 = incV(); 
    V t96 = incV(); V t88 = incV(); V t97 = incV(); V t89 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("lineitem")));
    PROFILE(5, pfnColumnValue(t1, t0, LiteralSymbol("l_orderkey")));
    PROFILE(6, pfnColumnValue(t12, t0, LiteralSymbol("l_shipdate")));
    PROFILE(7, pfnColumnValue(t13, t0, LiteralSymbol("l_commitdate")));
    PROFILE(8, pfnColumnValue(t14, t0, LiteralSymbol("l_receiptdate")));
    PROFILE(9, pfnColumnValue(t16, t0, LiteralSymbol("l_shipmode")));
    PROFILE(10, copyV(t18,LiteralVectorSymbol(2, (S []){"MAIL", "SHIP"})));
    PROFILE(11, pfnMember(t19, t16, t18));
    PROFILE(12, pfnLt(t20, t13, t14));
    PROFILE(13, pfnLt(t21, t12, t13));
    PROFILE(14, pfnAnd(t22, t19, t20));
    PROFILE(15, pfnAnd(t23, t22, t21));
    PROFILE(16, pfnGeq(t24, t14, LiteralDate(19940101)));
    PROFILE(17, pfnLt(t25, t14, LiteralDate(19950101)));
    PROFILE(18, pfnAnd(t26, t24, t25));
    PROFILE(19, pfnAnd(t27, t26, t23));
    PROFILE(20, pfnLoadTable(t44, LiteralSymbol("orders")));
    PROFILE(21, pfnColumnValue(t51, t44, LiteralSymbol("o_orderpriority")));
    PROFILE(22, pfnValues(t55, t1));
    PROFILE(23, pfnCompress(t56, t27, t55));
    PROFILE(24, pfnWhere(t57, t27));
    PROFILE(25, pfnIndex(t72, t16, t57));
    PROFILE(26, pfnIndex(t79, t51, t56));
    PROFILE(27, pfnEq(t83, t79, LiteralSymbol("1-URGENT")));
    PROFILE(28, pfnEq(t84, t79, LiteralSymbol("2-HIGH")));
    PROFILE(29, pfnOr(t85, t83, t84));
    PROFILE(30, pfnMul(t86, t85, LiteralI32(1)));
    PROFILE(31, pfnNot(t87, t85));
    PROFILE(32, pfnMul(t88, t87, LiteralI32(0)));
    PROFILE(33, pfnPlus(t89, t86, t88));
    PROFILE(34, pfnNeq(t90, t79, LiteralSymbol("1-URGENT")));
    PROFILE(35, pfnNeq(t91, t79, LiteralSymbol("2-HIGH")));
    PROFILE(36, pfnAnd(t92, t90, t91));
    PROFILE(37, pfnMul(t93, t92, LiteralI32(1)));
    PROFILE(38, pfnNot(t94, t92));
    PROFILE(39, pfnMul(t95, t94, LiteralI32(0)));
    PROFILE(40, pfnPlus(t96, t93, t95));
    PROFILE(41, pfnList(t97, 1, (V []){t72}));
    PROFILE(42, pfnGroup(t98, t97));
    PROFILE(43, pfnKeys(t99, t98));
    PROFILE(44, pfnValues(t100, t98));
    PROFILE(45, pfnIndex(t101, t72, t99));
    PROFILE(48, q12_peephole_fp1_0(t104,t89,t100));
    PROFILE(51, q12_peephole_fp1_1(t107,t96,t100));
    PROFILE(52, pfnList(t108, 1, (V []){t101}));
    PROFILE(53, pfnOrderBy(t109, t108, LiteralBool(1)));
    PROFILE(54, pfnIndex(t110, t101, t109));
    PROFILE(55, pfnIndex(t111, t104, t109));
    PROFILE(56, pfnIndex(t112, t107, t109));
    PROFILE(57, copyV(t113,LiteralVectorSymbol(3, (S []){"l_shipmode", "high_line_count", "low_line_count"})));
    PROFILE(58, pfnList(t114, 3, (V []){t110, t111, t112}));
    PROFILE(59, pfnTable(t115, t113, t114));
    h_rtn[0] = t115;
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

// Compiling time (ms): 0.868
