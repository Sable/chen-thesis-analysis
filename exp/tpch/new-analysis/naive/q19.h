// Parsing time (ms): 0.686
static I horse_main(V *h_rtn);


static I horse_main(V *h_rtn){
    V t120 = incV(); V t121 = incV(); V t122 = incV(); V t106 = incV(); 
    V t107 = incV(); V t117 = incV(); V t118 = incV(); V t119 = incV(); 
    V t0 = incV(); V t1 = incV(); V t4 = incV(); V t6 = incV(); 
    V t7 = incV(); V t10 = incV(); V t13 = incV(); V t30 = incV(); 
    V t31 = incV(); V t16 = incV(); V t33 = incV(); V t25 = incV(); 
    V t17 = incV(); V t50 = incV(); V t26 = incV(); V t18 = incV(); 
    V t51 = incV(); V t60 = incV(); V t52 = incV(); V t36 = incV(); 
    V t28 = incV(); V t61 = incV(); V t53 = incV(); V t37 = incV(); 
    V t29 = incV(); V t70 = incV(); V t62 = incV(); V t54 = incV(); 
    V t38 = incV(); V t71 = incV(); V t63 = incV(); V t55 = incV(); 
    V t80 = incV(); V t72 = incV(); V t64 = incV(); V t56 = incV(); 
    V t48 = incV(); V t81 = incV(); V t73 = incV(); V t65 = incV(); 
    V t57 = incV(); V t49 = incV(); V t90 = incV(); V t82 = incV(); 
    V t74 = incV(); V t66 = incV(); V t58 = incV(); V t91 = incV(); 
    V t83 = incV(); V t75 = incV(); V t67 = incV(); V t59 = incV(); 
    V t84 = incV(); V t76 = incV(); V t68 = incV(); V t85 = incV(); 
    V t77 = incV(); V t69 = incV(); V t86 = incV(); V t78 = incV(); 
    V t87 = incV(); V t79 = incV(); V t88 = incV(); V t89 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("part")));
    PROFILE(5, pfnColumnValue(t1, t0, LiteralSymbol("p_partkey")));
    PROFILE(6, pfnColumnValue(t4, t0, LiteralSymbol("p_brand")));
    PROFILE(7, pfnColumnValue(t6, t0, LiteralSymbol("p_size")));
    PROFILE(8, pfnColumnValue(t7, t0, LiteralSymbol("p_container")));
    PROFILE(9, pfnLoadTable(t10, LiteralSymbol("lineitem")));
    PROFILE(10, pfnColumnValue(t13, t10, LiteralSymbol("l_partkey")));
    PROFILE(11, pfnColumnValue(t16, t10, LiteralSymbol("l_quantity")));
    PROFILE(12, pfnColumnValue(t17, t10, LiteralSymbol("l_extendedprice")));
    PROFILE(13, pfnColumnValue(t18, t10, LiteralSymbol("l_discount")));
    PROFILE(14, pfnColumnValue(t25, t10, LiteralSymbol("l_shipinstruct")));
    PROFILE(15, pfnColumnValue(t26, t10, LiteralSymbol("l_shipmode")));
    PROFILE(16, copyV(t28,LiteralVectorSymbol(2, (S []){"AIR", "AIR REG"})));
    PROFILE(17, pfnMember(t29, t26, t28));
    PROFILE(18, pfnEq(t30, t25, LiteralSymbol("DELIVER IN PERSON")));
    PROFILE(19, pfnAnd(t31, t30, t29));
    PROFILE(20, pfnCompress(t33, t31, t13));
    PROFILE(21, pfnCompress(t36, t31, t16));
    PROFILE(22, pfnCompress(t37, t31, t17));
    PROFILE(23, pfnCompress(t38, t31, t18));
    PROFILE(24, pfnGeq(t48, t6, LiteralI32(1)));
    PROFILE(25, pfnLeq(t49, t6, LiteralI32(5)));
    PROFILE(26, pfnAnd(t50, t48, t49));
    PROFILE(27, pfnEq(t51, t4, LiteralSymbol("Brand#12")));
    PROFILE(28, copyV(t52,LiteralVectorSymbol(4, (S []){"SM CASE", "SM BOX", "SM PACK", "SM PKG"})));
    PROFILE(29, pfnMember(t53, t7, t52));
    PROFILE(30, pfnGeq(t54, t36, LiteralF64(1)));
    PROFILE(31, pfnLeq(t55, t36, LiteralF64(11)));
    PROFILE(32, pfnAnd(t56, t50, t51));
    PROFILE(33, pfnAnd(t57, t56, t53));
    PROFILE(34, pfnAnd(t58, t54, t55));
    PROFILE(35, pfnGeq(t59, t6, LiteralI32(1)));
    PROFILE(36, pfnLeq(t60, t6, LiteralI32(10)));
    PROFILE(37, pfnAnd(t61, t59, t60));
    PROFILE(38, pfnEq(t62, t4, LiteralSymbol("Brand#23")));
    PROFILE(39, copyV(t63,LiteralVectorSymbol(4, (S []){"MED BAG", "MED BOX", "MED PKG", "MED PACK"})));
    PROFILE(40, pfnMember(t64, t7, t63));
    PROFILE(41, pfnGeq(t65, t36, LiteralF64(10)));
    PROFILE(42, pfnLeq(t66, t36, LiteralF64(20)));
    PROFILE(43, pfnAnd(t67, t61, t62));
    PROFILE(44, pfnAnd(t68, t67, t64));
    PROFILE(45, pfnAnd(t69, t65, t66));
    PROFILE(46, pfnGeq(t70, t6, LiteralI32(1)));
    PROFILE(47, pfnLeq(t71, t6, LiteralI32(15)));
    PROFILE(48, pfnAnd(t72, t70, t71));
    PROFILE(49, pfnEq(t73, t4, LiteralSymbol("Brand#34")));
    PROFILE(50, copyV(t74,LiteralVectorSymbol(4, (S []){"LG CASE", "LG BOX", "LG PACK", "LG PKG"})));
    PROFILE(51, pfnMember(t75, t7, t74));
    PROFILE(52, pfnGeq(t76, t36, LiteralF64(20)));
    PROFILE(53, pfnLeq(t77, t36, LiteralF64(30)));
    PROFILE(54, pfnAnd(t78, t72, t73));
    PROFILE(55, pfnAnd(t79, t78, t75));
    PROFILE(56, pfnAnd(t80, t76, t77));
    PROFILE(57, pfnCompress(t81, t57, t1));
    PROFILE(58, pfnCompress(t82, t68, t1));
    PROFILE(59, pfnCompress(t83, t79, t1));
    PROFILE(60, pfnMember(t84, t33, t81));
    PROFILE(61, pfnMember(t85, t33, t82));
    PROFILE(62, pfnMember(t86, t33, t83));
    PROFILE(63, pfnAnd(t87, t84, t58));
    PROFILE(64, pfnAnd(t88, t85, t69));
    PROFILE(65, pfnAnd(t89, t86, t80));
    PROFILE(66, pfnOr(t90, t87, t88));
    PROFILE(67, pfnOr(t91, t90, t89));
    PROFILE(68, pfnCompress(t106, t91, t37));
    PROFILE(69, pfnCompress(t107, t91, t38));
    PROFILE(70, pfnMinus(t117, LiteralI32(1), t107));
    PROFILE(71, pfnMul(t118, t106, t117));
    PROFILE(72, pfnSum(t119, t118));
    PROFILE(73, copyV(t120,LiteralSymbol("revenue")));
    PROFILE(74, pfnList(t121, 1, (V []){t119}));
    PROFILE(75, pfnTable(t122, t120, t121));
    h_rtn[0] = t122;
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
