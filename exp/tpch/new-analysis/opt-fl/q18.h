// Parsing time (ms): 0.714
// Total # of fused stmts: 0
static I horse_main(V *h_rtn);


static I horse_main(V *h_rtn){
    V t100 = incV(); V t98 = incV(); V t101 = incV(); V t99 = incV(); 
    V t110 = incV(); V t102 = incV(); V t103 = incV(); V t113 = incV(); 
    V t114 = incV(); V t123 = incV(); V t140 = incV(); V t141 = incV(); 
    V t150 = incV(); V t142 = incV(); V t151 = incV(); V t143 = incV(); 
    V t135 = incV(); V t152 = incV(); V t144 = incV(); V t136 = incV(); 
    V t153 = incV(); V t145 = incV(); V t137 = incV(); V t154 = incV(); 
    V t146 = incV(); V t138 = incV(); V t155 = incV(); V t147 = incV(); 
    V t139 = incV(); V t156 = incV(); V t148 = incV(); V t157 = incV(); 
    V t149 = incV(); V t0 = incV(); V t1 = incV(); V t2 = incV(); 
    V t9 = incV(); V t10 = incV(); V t30 = incV(); V t14 = incV(); 
    V t31 = incV(); V t40 = incV(); V t32 = incV(); V t41 = incV(); 
    V t33 = incV(); V t50 = incV(); V t34 = incV(); V t26 = incV(); 
    V t51 = incV(); V t43 = incV(); V t35 = incV(); V t27 = incV(); 
    V t60 = incV(); V t52 = incV(); V t44 = incV(); V t36 = incV(); 
    V t28 = incV(); V t61 = incV(); V t29 = incV(); V t62 = incV(); 
    V t54 = incV(); V t63 = incV(); V t55 = incV(); V t39 = incV(); 
    V t72 = incV(); V t64 = incV(); V t81 = incV(); V t49 = incV(); 
    V t82 = incV(); V t75 = incV(); V t76 = incV(); V t86 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("customer")));
    PROFILE(5, pfnColumnValue(t1, t0, LiteralSymbol("c_custkey")));
    PROFILE(6, pfnColumnValue(t2, t0, LiteralSymbol("c_name")));
    PROFILE(7, pfnLoadTable(t9, LiteralSymbol("lineitem")));
    PROFILE(8, pfnColumnValue(t10, t9, LiteralSymbol("l_orderkey")));
    PROFILE(9, pfnColumnValue(t14, t9, LiteralSymbol("l_quantity")));
    PROFILE(10, pfnFetch(t26, t10));
    PROFILE(11, pfnList(t27, 1, (V []){t26}));
    PROFILE(12, pfnGroup(t28, t27));
    PROFILE(13, pfnKeys(t29, t28));
    PROFILE(14, pfnValues(t30, t28));
    PROFILE(15, pfnIndex(t31, t26, t29));
    PROFILE(16, pfnEachRight(t32, t14, t30, pfnIndex));
    PROFILE(17, pfnEach(t33, t32, pfnSum));
    PROFILE(18, pfnRaze(t34, t33));
    PROFILE(19, pfnGt(t35, t34, LiteralF64(300)));
    PROFILE(20, pfnCompress(t36, t35, t31));
    PROFILE(21, pfnLoadTable(t39, LiteralSymbol("orders")));
    PROFILE(22, pfnColumnValue(t40, t39, LiteralSymbol("o_orderkey")));
    PROFILE(23, pfnColumnValue(t41, t39, LiteralSymbol("o_custkey")));
    PROFILE(24, pfnColumnValue(t43, t39, LiteralSymbol("o_totalprice")));
    PROFILE(25, pfnColumnValue(t44, t39, LiteralSymbol("o_orderdate")));
    PROFILE(26, pfnMember(t49, t40, t36));
    PROFILE(27, pfnCompress(t50, t49, t40));
    PROFILE(28, pfnFetch(t51, t41));
    PROFILE(29, pfnCompress(t52, t49, t51));
    PROFILE(30, pfnCompress(t54, t49, t43));
    PROFILE(31, pfnCompress(t55, t49, t44));
    PROFILE(32, pfnJoinIndex(t60, t1, t52, LiteralSymbol((S)"eq")));
    PROFILE(33, pfnIndex(t61, t60, LiteralI64(0)));
    PROFILE(34, pfnIndex(t62, t60, LiteralI64(1)));
    PROFILE(35, pfnIndex(t63, t1, t61));
    PROFILE(36, pfnIndex(t64, t2, t61));
    PROFILE(37, pfnIndex(t72, t50, t62));
    PROFILE(38, pfnIndex(t75, t54, t62));
    PROFILE(39, pfnIndex(t76, t55, t62));
    PROFILE(40, pfnLoadTable(t81, LiteralSymbol("lineitem")));
    PROFILE(41, pfnColumnValue(t82, t81, LiteralSymbol("l_orderkey")));
    PROFILE(42, pfnColumnValue(t86, t81, LiteralSymbol("l_quantity")));
    PROFILE(43, pfnFetch(t98, t82));
    PROFILE(44, pfnJoinIndex(t99, t72, t98, LiteralSymbol((S)"eq")));
    PROFILE(45, pfnIndex(t100, t99, LiteralI64(0)));
    PROFILE(46, pfnIndex(t101, t99, LiteralI64(1)));
    PROFILE(47, pfnIndex(t102, t63, t100));
    PROFILE(48, pfnIndex(t103, t64, t100));
    PROFILE(49, pfnIndex(t110, t72, t100));
    PROFILE(50, pfnIndex(t113, t75, t100));
    PROFILE(51, pfnIndex(t114, t76, t100));
    PROFILE(52, pfnIndex(t123, t86, t101));
    PROFILE(53, pfnList(t135, 5, (V []){t103, t102, t110, t114, t113}));
    PROFILE(54, pfnGroup(t136, t135));
    PROFILE(55, pfnKeys(t137, t136));
    PROFILE(56, pfnValues(t138, t136));
    PROFILE(57, pfnIndex(t139, t103, t137));
    PROFILE(58, pfnIndex(t140, t102, t137));
    PROFILE(59, pfnIndex(t141, t110, t137));
    PROFILE(60, pfnIndex(t142, t114, t137));
    PROFILE(61, pfnIndex(t143, t113, t137));
    PROFILE(62, pfnEachRight(t144, t123, t138, pfnIndex));
    PROFILE(63, pfnEach(t145, t144, pfnSum));
    PROFILE(64, pfnRaze(t146, t145));
    PROFILE(65, pfnList(t147, 2, (V []){t143, t142}));
    PROFILE(66, pfnOrderBy(t148, t147, LiteralVectorBool(2, (B []){0, 1})));
    PROFILE(67, pfnIndex(t149, t139, t148));
    PROFILE(68, pfnIndex(t150, t140, t148));
    PROFILE(69, pfnIndex(t151, t141, t148));
    PROFILE(70, pfnIndex(t152, t142, t148));
    PROFILE(71, pfnIndex(t153, t143, t148));
    PROFILE(72, pfnIndex(t154, t146, t148));
    PROFILE(73, copyV(t155,LiteralVectorSymbol(6, (S []){"c_name", "c_custkey", "o_orderkey", "o_orderdate", "o_totalprice", "sum"})));
    PROFILE(74, pfnList(t156, 6, (V []){t149, t150, t151, t152, t153, t154}));
    PROFILE(75, pfnTable(t157, t155, t156));
    h_rtn[0] = t157;
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

// Compiling time (ms): 1.573
