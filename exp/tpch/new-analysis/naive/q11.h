// Parsing time (ms): 0.656
static I horse_main(V *h_rtn);


static I horse_main(V *h_rtn){
    V t100 = incV(); V t101 = incV(); V t99 = incV(); V t102 = incV(); 
    V t103 = incV(); V t121 = incV(); V t105 = incV(); V t130 = incV(); 
    V t122 = incV(); V t106 = incV(); V t131 = incV(); V t132 = incV(); 
    V t124 = incV(); V t108 = incV(); V t141 = incV(); V t133 = incV(); 
    V t125 = incV(); V t150 = incV(); V t142 = incV(); V t134 = incV(); 
    V t135 = incV(); V t127 = incV(); V t144 = incV(); V t136 = incV(); 
    V t128 = incV(); V t145 = incV(); V t129 = incV(); V t146 = incV(); 
    V t147 = incV(); V t148 = incV(); V t149 = incV(); V t0 = incV(); 
    V t2 = incV(); V t5 = incV(); V t10 = incV(); V t11 = incV(); 
    V t21 = incV(); V t14 = incV(); V t40 = incV(); V t41 = incV(); 
    V t34 = incV(); V t26 = incV(); V t18 = incV(); V t43 = incV(); 
    V t19 = incV(); V t60 = incV(); V t36 = incV(); V t37 = incV(); 
    V t70 = incV(); V t62 = incV(); V t38 = incV(); V t63 = incV(); 
    V t64 = incV(); V t65 = incV(); V t91 = incV(); V t83 = incV(); 
    V t75 = incV(); V t67 = incV(); V t59 = incV(); V t84 = incV(); 
    V t76 = incV(); V t86 = incV(); V t79 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("nation")));
    PROFILE(5, pfnColumnValue(t2, t0, LiteralSymbol("n_name")));
    PROFILE(6, pfnEq(t5, t2, LiteralSymbol("GERMANY")));
    PROFILE(7, pfnLoadTable(t10, LiteralSymbol("supplier")));
    PROFILE(8, pfnColumnValue(t11, t10, LiteralSymbol("s_suppkey")));
    PROFILE(9, pfnColumnValue(t14, t10, LiteralSymbol("s_nationkey")));
    PROFILE(10, pfnValues(t18, t14));
    PROFILE(11, pfnIndex(t19, t5, t18));
    PROFILE(12, pfnWhere(t21, t19));
    PROFILE(13, pfnIndex(t26, t11, t21));
    PROFILE(14, pfnLoadTable(t34, LiteralSymbol("partsupp")));
    PROFILE(15, pfnColumnValue(t36, t34, LiteralSymbol("ps_suppkey")));
    PROFILE(16, pfnColumnValue(t37, t34, LiteralSymbol("ps_availqty")));
    PROFILE(17, pfnColumnValue(t38, t34, LiteralSymbol("ps_supplycost")));
    PROFILE(18, pfnFetch(t40, t36));
    PROFILE(19, pfnJoinIndex(t41, t26, t40, LiteralSymbol((S)"eq")));
    PROFILE(20, pfnIndex(t43, t41, LiteralI64(1)));
    PROFILE(21, pfnIndex(t59, t37, t43));
    PROFILE(22, pfnIndex(t60, t38, t43));
    PROFILE(23, pfnMul(t62, t60, t59));
    PROFILE(24, pfnSum(t63, t62));
    PROFILE(25, pfnMul(t64, t63, LiteralF64(0.0001)));
    PROFILE(26, pfnLoadTable(t65, LiteralSymbol("nation")));
    PROFILE(27, pfnColumnValue(t67, t65, LiteralSymbol("n_name")));
    PROFILE(28, pfnEq(t70, t67, LiteralSymbol("GERMANY")));
    PROFILE(29, pfnLoadTable(t75, LiteralSymbol("supplier")));
    PROFILE(30, pfnColumnValue(t76, t75, LiteralSymbol("s_suppkey")));
    PROFILE(31, pfnColumnValue(t79, t75, LiteralSymbol("s_nationkey")));
    PROFILE(32, pfnValues(t83, t79));
    PROFILE(33, pfnIndex(t84, t70, t83));
    PROFILE(34, pfnWhere(t86, t84));
    PROFILE(35, pfnIndex(t91, t76, t86));
    PROFILE(36, pfnLoadTable(t99, LiteralSymbol("partsupp")));
    PROFILE(37, pfnColumnValue(t100, t99, LiteralSymbol("ps_partkey")));
    PROFILE(38, pfnColumnValue(t101, t99, LiteralSymbol("ps_suppkey")));
    PROFILE(39, pfnColumnValue(t102, t99, LiteralSymbol("ps_availqty")));
    PROFILE(40, pfnColumnValue(t103, t99, LiteralSymbol("ps_supplycost")));
    PROFILE(41, pfnFetch(t105, t101));
    PROFILE(42, pfnJoinIndex(t106, t91, t105, LiteralSymbol((S)"eq")));
    PROFILE(43, pfnIndex(t108, t106, LiteralI64(1)));
    PROFILE(44, pfnFetch(t121, t100));
    PROFILE(45, pfnIndex(t122, t121, t108));
    PROFILE(46, pfnIndex(t124, t102, t108));
    PROFILE(47, pfnIndex(t125, t103, t108));
    PROFILE(48, pfnMul(t127, t125, t124));
    PROFILE(49, pfnList(t128, 1, (V []){t122}));
    PROFILE(50, pfnGroup(t129, t128));
    PROFILE(51, pfnKeys(t130, t129));
    PROFILE(52, pfnValues(t131, t129));
    PROFILE(53, pfnIndex(t132, t122, t130));
    PROFILE(54, pfnEachRight(t133, t127, t131, pfnIndex));
    PROFILE(55, pfnEach(t134, t133, pfnSum));
    PROFILE(56, pfnRaze(t135, t134));
    PROFILE(57, pfnLt(t136, t64, t135));
    PROFILE(58, pfnCompress(t141, t136, t132));
    PROFILE(59, pfnCompress(t142, t136, t135));
    PROFILE(60, pfnList(t144, 1, (V []){t142}));
    PROFILE(61, pfnOrderBy(t145, t144, LiteralBool(0)));
    PROFILE(62, pfnIndex(t146, t141, t145));
    PROFILE(63, pfnIndex(t147, t142, t145));
    PROFILE(64, copyV(t148,LiteralVectorSymbol(2, (S []){"ps_partkey", "value"})));
    PROFILE(65, pfnList(t149, 2, (V []){t146, t147}));
    PROFILE(66, pfnTable(t150, t148, t149));
    h_rtn[0] = t150;
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

// Compiling time (ms): 0.332
