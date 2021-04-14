// Parsing time (ms): 0.771
// Total # of fused stmts: 0
static I horse_main(V *h_rtn);


static I horse_main(V *h_rtn){
    V t100 = incV(); V t101 = incV(); V t110 = incV(); V t111 = incV(); 
    V t103 = incV(); V t200 = incV(); V t120 = incV(); V t201 = incV(); 
    V t122 = incV(); V t300 = incV(); V t301 = incV(); V t213 = incV(); 
    V t310 = incV(); V t302 = incV(); V t134 = incV(); V t311 = incV(); 
    V t303 = incV(); V t215 = incV(); V t207 = incV(); V t304 = incV(); 
    V t160 = incV(); V t136 = incV(); V t128 = incV(); V t305 = incV(); 
    V t241 = incV(); V t161 = incV(); V t306 = incV(); V t307 = incV(); 
    V t163 = incV(); V t308 = incV(); V t260 = incV(); V t180 = incV(); 
    V t172 = incV(); V t309 = incV(); V t261 = incV(); V t173 = incV(); 
    V t238 = incV(); V t255 = incV(); V t239 = incV(); V t256 = incV(); 
    V t257 = incV(); V t177 = incV(); V t258 = incV(); V t194 = incV(); 
    V t178 = incV(); V t267 = incV(); V t259 = incV(); V t195 = incV(); 
    V t196 = incV(); V t197 = incV(); V t198 = incV(); V t199 = incV(); 
    V t298 = incV(); V t299 = incV(); V t0 = incV(); V t2 = incV(); 
    V t5 = incV(); V t10 = incV(); V t11 = incV(); V t12 = incV(); 
    V t21 = incV(); V t14 = incV(); V t34 = incV(); V t26 = incV(); 
    V t18 = incV(); V t51 = incV(); V t35 = incV(); V t27 = incV(); 
    V t19 = incV(); V t52 = incV(); V t37 = incV(); V t70 = incV(); 
    V t54 = incV(); V t46 = incV(); V t47 = incV(); V t83 = incV(); 
    V t84 = incV(); V t68 = incV(); V t77 = incV(); V t69 = incV(); 
    V t86 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("nation")));
    PROFILE(5, pfnColumnValue(t2, t0, LiteralSymbol("n_name")));
    PROFILE(6, pfnEq(t5, t2, LiteralSymbol("SAUDI ARABIA")));
    PROFILE(7, pfnLoadTable(t10, LiteralSymbol("supplier")));
    PROFILE(8, pfnColumnValue(t11, t10, LiteralSymbol("s_suppkey")));
    PROFILE(9, pfnColumnValue(t12, t10, LiteralSymbol("s_name")));
    PROFILE(10, pfnColumnValue(t14, t10, LiteralSymbol("s_nationkey")));
    PROFILE(11, pfnValues(t18, t14));
    PROFILE(12, pfnIndex(t19, t5, t18));
    PROFILE(13, pfnWhere(t21, t19));
    PROFILE(14, pfnIndex(t26, t11, t21));
    PROFILE(15, pfnIndex(t27, t12, t21));
    PROFILE(16, pfnLoadTable(t34, LiteralSymbol("lineitem")));
    PROFILE(17, pfnColumnValue(t35, t34, LiteralSymbol("l_orderkey")));
    PROFILE(18, pfnColumnValue(t37, t34, LiteralSymbol("l_suppkey")));
    PROFILE(19, pfnColumnValue(t46, t34, LiteralSymbol("l_commitdate")));
    PROFILE(20, pfnColumnValue(t47, t34, LiteralSymbol("l_receiptdate")));
    PROFILE(21, pfnGt(t51, t47, t46));
    PROFILE(22, pfnFetch(t52, t35));
    PROFILE(23, pfnCompress(t83, t51, t52));
    PROFILE(25, pfnCompress(t54, t51, t37));
    PROFILE(26, pfnJoinIndex(t68, t26, t54, LiteralSymbol((S)"eq")));
    PROFILE(27, pfnIndex(t69, t68, LiteralI64(0)));
    PROFILE(28, pfnIndex(t70, t68, LiteralI64(1)));
    PROFILE(29, pfnIndex(t77, t27, t69));
    PROFILE(31, pfnIndex(t84, t83, t70));
    PROFILE(32, pfnIndex(t86, t54, t70));
    PROFILE(33, pfnLoadTable(t100, LiteralSymbol("orders")));
    PROFILE(34, pfnColumnValue(t101, t100, LiteralSymbol("o_orderkey")));
    PROFILE(35, pfnColumnValue(t103, t100, LiteralSymbol("o_orderstatus")));
    PROFILE(36, pfnEq(t110, t103, LiteralChar('F')));
    PROFILE(37, pfnCompress(t111, t110, t101));
    PROFILE(38, pfnJoinIndex(t120, t111, t84, LiteralSymbol((S)"eq")));
    PROFILE(39, pfnIndex(t122, t120, LiteralI64(1)));
    PROFILE(40, pfnIndex(t128, t77, t122));
    PROFILE(41, pfnIndex(t134, t84, t122));
    PROFILE(42, pfnIndex(t136, t86, t122));
    PROFILE(43, pfnLoadTable(t160, LiteralSymbol("lineitem")));
    PROFILE(44, pfnColumnValue(t161, t160, LiteralSymbol("l_orderkey")));
    PROFILE(45, pfnColumnValue(t163, t160, LiteralSymbol("l_suppkey")));
    PROFILE(46, pfnColumnValue(t172, t160, LiteralSymbol("l_commitdate")));
    PROFILE(47, pfnColumnValue(t173, t160, LiteralSymbol("l_receiptdate")));
    PROFILE(48, pfnGt(t177, t173, t172));
    PROFILE(49, pfnFetch(t178, t161));
    PROFILE(50, pfnCompress(t194, t177, t178));
    PROFILE(52, pfnCompress(t180, t177, t163));
    PROFILE(54, pfnList(t195, 2, (V []){t134, t136}));
    PROFILE(55, pfnList(t196, 2, (V []){t194, t180}));
    PROFILE(56, pfnJoinIndex(t197, t195, t196, LiteralVectorSymbol(2, (S []){"eq", "neq"})));
    PROFILE(57, pfnIndex(t198, t197, LiteralI64(0)));
    PROFILE(58, pfnLen(t199, t134));
    PROFILE(59, pfnVector(t200, t199, LiteralBool(1)));
    PROFILE(60, pfnIndexA(t201, t200, t198, LiteralBool(0)));
    PROFILE(61, pfnCompress(t207, t201, t128));
    PROFILE(62, pfnCompress(t213, t201, t134));
    PROFILE(63, pfnCompress(t215, t201, t136));
    PROFILE(64, pfnLoadTable(t238, LiteralSymbol("lineitem")));
    PROFILE(65, pfnColumnValue(t239, t238, LiteralSymbol("l_orderkey")));
    PROFILE(66, pfnColumnValue(t241, t238, LiteralSymbol("l_suppkey")));
    PROFILE(67, pfnFetch(t255, t239));
    PROFILE(68, pfnList(t256, 2, (V []){t215, t213}));
    PROFILE(69, pfnList(t257, 2, (V []){t241, t255}));
    PROFILE(70, pfnJoinIndex(t258, t256, t257, LiteralVectorSymbol(2, (S []){"neq", "eq"})));
    PROFILE(71, pfnIndex(t259, t258, LiteralI64(0)));
    PROFILE(72, pfnUnique(t260, t259));
    PROFILE(73, pfnIndex(t261, t259, t260));
    PROFILE(74, pfnIndex(t267, t207, t261));
    PROFILE(75, pfnList(t298, 1, (V []){t267}));
    PROFILE(76, pfnGroup(t299, t298));
    PROFILE(77, pfnKeys(t300, t299));
    PROFILE(78, pfnValues(t301, t299));
    PROFILE(79, pfnIndex(t302, t267, t300));
    PROFILE(80, pfnEach(t303, t301, pfnLen));
    PROFILE(81, pfnRaze(t304, t303));
    PROFILE(82, pfnList(t305, 2, (V []){t304, t302}));
    PROFILE(83, pfnOrderBy(t306, t305, LiteralVectorBool(2, (B []){0, 1})));
    PROFILE(84, pfnIndex(t307, t302, t306));
    PROFILE(85, pfnIndex(t308, t304, t306));
    PROFILE(86, copyV(t309,LiteralVectorSymbol(2, (S []){"s_name", "numwait"})));
    PROFILE(87, pfnList(t310, 2, (V []){t307, t308}));
    PROFILE(88, pfnTable(t311, t309, t310));
    h_rtn[0] = t311;
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

// Compiling time (ms): 1.878
