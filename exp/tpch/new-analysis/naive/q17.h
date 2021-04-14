// Parsing time (ms): 0.589
static I horse_main(V *h_rtn);


static I horse_main(V *h_rtn){
    V t100 = incV(); V t101 = incV(); V t99 = incV(); V t110 = incV(); 
    V t111 = incV(); V t103 = incV(); V t112 = incV(); V t104 = incV(); 
    V t113 = incV(); V t105 = incV(); V t114 = incV(); V t106 = incV(); 
    V t131 = incV(); V t115 = incV(); V t107 = incV(); V t108 = incV(); 
    V t109 = incV(); V t150 = incV(); V t151 = incV(); V t147 = incV(); 
    V t148 = incV(); V t149 = incV(); V t0 = incV(); V t1 = incV(); 
    V t4 = incV(); V t7 = incV(); V t10 = incV(); V t11 = incV(); 
    V t12 = incV(); V t13 = incV(); V t22 = incV(); V t40 = incV(); 
    V t24 = incV(); V t41 = incV(); V t42 = incV(); V t27 = incV(); 
    V t28 = incV(); V t70 = incV(); V t71 = incV(); V t39 = incV(); 
    V t72 = incV(); V t56 = incV(); V t73 = incV(); V t57 = incV(); 
    V t90 = incV(); V t91 = incV(); V t75 = incV(); V t92 = incV(); 
    V t68 = incV(); V t93 = incV(); V t69 = incV(); V t94 = incV(); 
    V t78 = incV(); V t95 = incV(); V t96 = incV(); V t97 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("part")));
    PROFILE(5, pfnColumnValue(t1, t0, LiteralSymbol("p_partkey")));
    PROFILE(6, pfnColumnValue(t4, t0, LiteralSymbol("p_brand")));
    PROFILE(7, pfnColumnValue(t7, t0, LiteralSymbol("p_container")));
    PROFILE(8, pfnEq(t10, t7, LiteralSymbol("MED BOX")));
    PROFILE(9, pfnEq(t11, t4, LiteralSymbol("Brand#23")));
    PROFILE(10, pfnAnd(t12, t10, t11));
    PROFILE(11, pfnCompress(t13, t12, t1));
    PROFILE(12, pfnLoadTable(t22, LiteralSymbol("lineitem")));
    PROFILE(13, pfnColumnValue(t24, t22, LiteralSymbol("l_partkey")));
    PROFILE(14, pfnColumnValue(t27, t22, LiteralSymbol("l_quantity")));
    PROFILE(15, pfnColumnValue(t28, t22, LiteralSymbol("l_extendedprice")));
    PROFILE(16, pfnJoinIndex(t39, t13, t24, LiteralSymbol((S)"eq")));
    PROFILE(17, pfnIndex(t40, t39, LiteralI64(0)));
    PROFILE(18, pfnIndex(t41, t39, LiteralI64(1)));
    PROFILE(19, pfnIndex(t42, t13, t40));
    PROFILE(20, pfnIndex(t56, t27, t41));
    PROFILE(21, pfnIndex(t57, t28, t41));
    PROFILE(22, pfnList(t68, 1, (V []){t42}));
    PROFILE(23, pfnGroup(t69, t68));
    PROFILE(24, pfnKeys(t70, t69));
    PROFILE(25, pfnValues(t71, t69));
    PROFILE(26, pfnIndex(t72, t42, t70));
    PROFILE(27, pfnLoadTable(t73, LiteralSymbol("lineitem")));
    PROFILE(28, pfnColumnValue(t75, t73, LiteralSymbol("l_partkey")));
    PROFILE(29, pfnColumnValue(t78, t73, LiteralSymbol("l_quantity")));
    PROFILE(30, pfnJoinIndex(t90, t72, t75, LiteralSymbol((S)"eq")));
    PROFILE(31, pfnIndex(t91, t90, LiteralI64(0)));
    PROFILE(32, pfnIndex(t92, t90, LiteralI64(1)));
    PROFILE(33, pfnGroup(t93, t91));
    PROFILE(34, pfnKeys(t94, t93));
    PROFILE(35, pfnValues(t95, t93));
    PROFILE(36, pfnIndex(t96, t91, t94));
    PROFILE(37, pfnEachRight(t97, t92, t95, pfnIndex));
    PROFILE(38, pfnEach(t99, t71, pfnLen));
    PROFILE(39, pfnRaze(t100, t99));
    PROFILE(40, pfnIndex(t101, t100, t96));
    PROFILE(41, pfnEachRight(t103, t78, t97, pfnIndex));
    PROFILE(42, pfnEach(t104, t103, pfnSum));
    PROFILE(43, pfnRaze(t105, t104));
    PROFILE(44, pfnMul(t106, t101, t105));
    PROFILE(45, pfnEach(t107, t103, pfnLen));
    PROFILE(46, pfnRaze(t108, t107));
    PROFILE(47, pfnMul(t109, t101, t108));
    PROFILE(48, pfnDiv(t110, t106, t109));
    PROFILE(49, pfnMul(t111, LiteralF64(0.2), t110));
    PROFILE(50, pfnList(t112, 2, (V []){t56, t42}));
    PROFILE(51, pfnList(t113, 2, (V []){t111, t72}));
    PROFILE(52, pfnJoinIndex(t114, t112, t113, LiteralVectorSymbol(2, (S []){"lt", "eq"})));
    PROFILE(53, pfnIndex(t115, t114, LiteralI64(0)));
    PROFILE(54, pfnIndex(t131, t57, t115));
    PROFILE(55, pfnSum(t147, t131));
    PROFILE(56, pfnDiv(t148, t147, LiteralF64(7)));
    PROFILE(57, copyV(t149,LiteralSymbol("avg_yearly")));
    PROFILE(58, pfnList(t150, 1, (V []){t148}));
    PROFILE(59, pfnTable(t151, t149, t150));
    h_rtn[0] = t151;
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

// Compiling time (ms): 0.321
