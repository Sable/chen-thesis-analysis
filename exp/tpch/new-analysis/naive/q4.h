// Parsing time (ms): 0.398
static I horse_main(V *h_rtn);


static I horse_main(V *h_rtn){
    V t0 = incV(); V t6 = incV(); V t7 = incV(); V t11 = incV(); 
    V t12 = incV(); V t13 = incV(); V t23 = incV(); V t24 = incV(); 
    V t41 = incV(); V t60 = incV(); V t36 = incV(); V t61 = incV(); 
    V t37 = incV(); V t70 = incV(); V t62 = incV(); V t63 = incV(); 
    V t80 = incV(); V t64 = incV(); V t81 = incV(); V t82 = incV(); 
    V t74 = incV(); V t58 = incV(); V t83 = incV(); V t75 = incV(); 
    V t59 = incV(); V t84 = incV(); V t76 = incV(); V t85 = incV(); 
    V t77 = incV(); V t86 = incV(); V t78 = incV(); V t87 = incV(); 
    V t79 = incV(); V t88 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("orders")));
    PROFILE(5, pfnColumnValue(t6, t0, LiteralSymbol("o_orderdate")));
    PROFILE(6, pfnColumnValue(t7, t0, LiteralSymbol("o_orderpriority")));
    PROFILE(7, pfnGeq(t11, t6, LiteralDate(19930701)));
    PROFILE(8, pfnLt(t12, t6, LiteralDate(19931001)));
    PROFILE(9, pfnAnd(t13, t11, t12));
    PROFILE(10, pfnLoadTable(t23, LiteralSymbol("lineitem")));
    PROFILE(11, pfnColumnValue(t24, t23, LiteralSymbol("l_orderkey")));
    PROFILE(12, pfnColumnValue(t36, t23, LiteralSymbol("l_commitdate")));
    PROFILE(13, pfnColumnValue(t37, t23, LiteralSymbol("l_receiptdate")));
    PROFILE(14, pfnLt(t41, t36, t37));
    PROFILE(15, pfnValues(t58, t24));
    PROFILE(16, pfnKeys(t59, t24));
    PROFILE(17, pfnCompress(t60, t41, t58));
    PROFILE(18, pfnLen(t61, t59));
    PROFILE(19, pfnVector(t62, t61, LiteralBool(0)));
    PROFILE(20, pfnIndexA(t63, t62, t60, LiteralBool(1)));
    PROFILE(21, pfnAnd(t64, t13, t63));
    PROFILE(22, pfnCompress(t70, t64, t7));
    PROFILE(23, pfnList(t74, 1, (V []){t70}));
    PROFILE(24, pfnGroup(t75, t74));
    PROFILE(25, pfnKeys(t76, t75));
    PROFILE(26, pfnValues(t77, t75));
    PROFILE(27, pfnIndex(t78, t70, t76));
    PROFILE(28, pfnEachRight(t79, t70, t77, pfnIndex));
    PROFILE(29, pfnEach(t80, t79, pfnLen));
    PROFILE(30, pfnRaze(t81, t80));
    PROFILE(31, pfnList(t82, 1, (V []){t78}));
    PROFILE(32, pfnOrderBy(t83, t82, LiteralBool(1)));
    PROFILE(33, pfnIndex(t84, t78, t83));
    PROFILE(34, pfnIndex(t85, t81, t83));
    PROFILE(35, copyV(t86,LiteralVectorSymbol(2, (S []){"o_orderpriority", "order_count"})));
    PROFILE(36, pfnList(t87, 2, (V []){t84, t85}));
    PROFILE(37, pfnTable(t88, t86, t87));
    h_rtn[0] = t88;
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

// Compiling time (ms): 0.21
