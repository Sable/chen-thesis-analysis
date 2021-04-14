// Parsing time (ms): 0.991
static I horse_main(V *h_rtn);
static I q8_patterncompress_2(V *z, V x, V *y);
static I q8_peephole_fp1_0(V z, V x, V y);
static I q8_peephole_fp1_1(V z, V x, V y);

static I q8_patterncompress_2(V *z, V x, V *y){
    V z0 = z[0]; // t109
    V z1 = z[1]; // t147
    V z2 = z[2]; // t113
    V y0 = y[0]; // t97
    V y1 = y[1]; // t110
    V y2 = y[2]; // t101
    L len = vn(x), k = 0;
    L lenZ = 0, parZ[H_CORE], offset[H_CORE];
    DOI(H_CORE, parZ[i]=offset[i]=0)
    CHECKE(getNumOfNonZero(x,parZ));
    DOI(H_CORE, lenZ += parZ[i])
    DOIa(H_CORE, offset[i]=parZ[i-1]+offset[i-1])
    initV(z0,H_I,lenZ);
    initV(z1,H_I,lenZ);
    initV(z2,H_D,lenZ);
    DOT(len, if(vB(x,i)){L c=offset[tid]++;\
        vI(z0,c) = vI(y0,i);\
        vI(z1,c) = vI(y1,i);\
        vD(z2,c) = vD(y2,i);\
    })
    R 0;
}

static I q8_peephole_fp1_0(V z, V x, V y){
    // z -> t410
    initV(z, H_E, vn(y));
    DOP(vn(y), {E a=0; V t=vV(y,i); DOJ(vn(t), a+=vE(x,vL(t,j))) vE(z,i)=a;}) R 0;
}

static I q8_peephole_fp1_1(V z, V x, V y){
    // z -> t413
    initV(z, H_E, vn(y));
    DOP(vn(y), {E a=0; V t=vV(y,i); DOJ(vn(t), a+=vE(x,vL(t,j))) vE(z,i)=a;}) R 0;
}


static I horse_main(V *h_rtn){
    V t98 = incV(); V t101 = incV(); V t110 = incV(); V t120 = incV(); 
    V t113 = incV(); V t106 = incV(); V t211 = incV(); V t107 = incV(); 
    V t132 = incV(); V t108 = incV(); V t213 = incV(); V t205 = incV(); 
    V t109 = incV(); V t310 = incV(); V t206 = incV(); V t118 = incV(); 
    V t151 = incV(); V t135 = incV(); V t119 = incV(); V t400 = incV(); 
    V t232 = incV(); V t160 = incV(); V t136 = incV(); V t401 = incV(); 
    V t410 = incV(); V t402 = incV(); V t250 = incV(); V t411 = incV(); 
    V t403 = incV(); V t331 = incV(); V t235 = incV(); V t147 = incV(); 
    V t420 = incV(); V t412 = incV(); V t404 = incV(); V t332 = incV(); 
    V t236 = incV(); V t156 = incV(); V t148 = incV(); V t421 = incV(); 
    V t413 = incV(); V t405 = incV(); V t333 = incV(); V t165 = incV(); 
    V t157 = incV(); V t414 = incV(); V t406 = incV(); V t326 = incV(); 
    V t182 = incV(); V t166 = incV(); V t415 = incV(); V t407 = incV(); 
    V t335 = incV(); V t327 = incV(); V t271 = incV(); V t263 = incV(); 
    V t183 = incV(); V t167 = incV(); V t416 = incV(); V t408 = incV(); 
    V t360 = incV(); V t272 = incV(); V t264 = incV(); V t417 = incV(); 
    V t409 = incV(); V t361 = incV(); V t273 = incV(); V t418 = incV(); 
    V t419 = incV(); V t267 = incV(); V t179 = incV(); V t197 = incV(); 
    V t375 = incV(); V t295 = incV(); V t296 = incV(); V t395 = incV(); 
    V t396 = incV(); V t397 = incV(); V t398 = incV(); V t399 = incV(); 
    V t0 = incV(); V t1 = incV(); V t2 = incV(); V t5 = incV(); 
    V t7 = incV(); V t9 = incV(); V t21 = incV(); V t13 = incV(); 
    V t30 = incV(); V t14 = incV(); V t31 = incV(); V t40 = incV(); 
    V t16 = incV(); V t41 = incV(); V t25 = incV(); V t50 = incV(); 
    V t18 = incV(); V t51 = incV(); V t35 = incV(); V t19 = incV(); 
    V t52 = incV(); V t53 = incV(); V t80 = incV(); V t56 = incV(); 
    V t57 = incV(); V t82 = incV(); V t67 = incV(); V t85 = incV(); 
    V t69 = incV(); V t86 = incV(); V t79 = incV(); V t96 = incV(); 
    V t97 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("nation")));
    PROFILE(5, pfnColumnValue(t1, t0, LiteralSymbol("n_nationkey")));
    PROFILE(6, pfnColumnValue(t2, t0, LiteralSymbol("n_name")));
    PROFILE(7, pfnLoadTable(t5, LiteralSymbol("region")));
    PROFILE(8, pfnColumnValue(t7, t5, LiteralSymbol("r_name")));
    PROFILE(9, pfnEq(t9, t7, LiteralSymbol("AMERICA")));
    PROFILE(10, pfnLoadTable(t13, LiteralSymbol("nation")));
    PROFILE(11, pfnColumnValue(t14, t13, LiteralSymbol("n_nationkey")));
    PROFILE(12, pfnColumnValue(t16, t13, LiteralSymbol("n_regionkey")));
    PROFILE(13, pfnValues(t18, t16));
    PROFILE(14, pfnIndex(t19, t9, t18));
    PROFILE(15, pfnWhere(t21, t19));
    PROFILE(16, pfnIndex(t25, t14, t21));
    PROFILE(17, pfnLoadTable(t30, LiteralSymbol("part")));
    PROFILE(18, pfnColumnValue(t31, t30, LiteralSymbol("p_partkey")));
    PROFILE(19, pfnColumnValue(t35, t30, LiteralSymbol("p_type")));
    PROFILE(20, pfnEq(t40, t35, LiteralSymbol("ECONOMY ANODIZED STEEL")));
    PROFILE(21, pfnCompress(t41, t40, t31));
    PROFILE(22, pfnLoadTable(t50, LiteralSymbol("lineitem")));
    PROFILE(23, pfnColumnValue(t51, t50, LiteralSymbol("l_orderkey")));
    PROFILE(24, pfnColumnValue(t52, t50, LiteralSymbol("l_partkey")));
    PROFILE(25, pfnColumnValue(t53, t50, LiteralSymbol("l_suppkey")));
    PROFILE(26, pfnColumnValue(t56, t50, LiteralSymbol("l_extendedprice")));
    PROFILE(27, pfnColumnValue(t57, t50, LiteralSymbol("l_discount")));
    PROFILE(28, pfnJoinIndex(t67, t41, t52, LiteralSymbol((S)"eq")));
    PROFILE(29, pfnIndex(t69, t67, LiteralI64(1)));
    PROFILE(30, pfnFetch(t79, t51));
    PROFILE(31, pfnIndex(t80, t79, t69));
    PROFILE(32, pfnIndex(t82, t53, t69));
    PROFILE(33, pfnIndex(t85, t56, t69));
    PROFILE(34, pfnIndex(t86, t57, t69));
    PROFILE(35, pfnLoadTable(t96, LiteralSymbol("orders")));
    PROFILE(36, pfnColumnValue(t97, t96, LiteralSymbol("o_orderkey")));
    PROFILE(37, pfnColumnValue(t98, t96, LiteralSymbol("o_custkey")));
    PROFILE(38, pfnColumnValue(t101, t96, LiteralSymbol("o_orderdate")));
    PROFILE(39, pfnGeq(t106, t101, LiteralDate(19950101)));
    PROFILE(40, pfnLeq(t107, t101, LiteralDate(19961231)));
    PROFILE(41, pfnAnd(t108, t106, t107));
    PROFILE(43, pfnFetch(t110, t98));
    PROFILE(46, q8_patterncompress_2((V []){t109, t147, t113}, t108, (V []){t97, t110, t101}));
    PROFILE(47, pfnJoinIndex(t118, t109, t80, LiteralSymbol((S)"eq")));
    PROFILE(48, pfnIndex(t119, t118, LiteralI64(0)));
    PROFILE(49, pfnIndex(t120, t118, LiteralI64(1)));
    PROFILE(50, pfnIndex(t132, t82, t120));
    PROFILE(51, pfnIndex(t135, t85, t120));
    PROFILE(52, pfnIndex(t136, t86, t120));
    PROFILE(54, pfnIndex(t148, t147, t119));
    PROFILE(55, pfnIndex(t151, t113, t119));
    PROFILE(56, pfnLoadTable(t156, LiteralSymbol("customer")));
    PROFILE(57, pfnColumnValue(t157, t156, LiteralSymbol("c_custkey")));
    PROFILE(58, pfnColumnValue(t160, t156, LiteralSymbol("c_nationkey")));
    PROFILE(59, pfnJoinIndex(t165, t157, t148, LiteralSymbol((S)"eq")));
    PROFILE(60, pfnIndex(t166, t165, LiteralI64(0)));
    PROFILE(61, pfnIndex(t167, t165, LiteralI64(1)));
    PROFILE(62, pfnIndex(t179, t132, t167));
    PROFILE(63, pfnIndex(t182, t135, t167));
    PROFILE(64, pfnIndex(t183, t136, t167));
    PROFILE(65, pfnIndex(t197, t151, t167));
    PROFILE(66, pfnFetch(t205, t160));
    PROFILE(67, pfnIndex(t206, t205, t166));
    PROFILE(68, pfnJoinIndex(t211, t25, t206, LiteralSymbol((S)"eq")));
    PROFILE(69, pfnIndex(t213, t211, LiteralI64(1)));
    PROFILE(70, pfnIndex(t232, t179, t213));
    PROFILE(71, pfnIndex(t235, t182, t213));
    PROFILE(72, pfnIndex(t236, t183, t213));
    PROFILE(73, pfnIndex(t250, t197, t213));
    PROFILE(74, pfnLoadTable(t263, LiteralSymbol("supplier")));
    PROFILE(75, pfnColumnValue(t264, t263, LiteralSymbol("s_suppkey")));
    PROFILE(76, pfnColumnValue(t267, t263, LiteralSymbol("s_nationkey")));
    PROFILE(77, pfnJoinIndex(t271, t264, t232, LiteralSymbol((S)"eq")));
    PROFILE(78, pfnIndex(t272, t271, LiteralI64(0)));
    PROFILE(79, pfnIndex(t273, t271, LiteralI64(1)));
    PROFILE(80, pfnIndex(t295, t235, t273));
    PROFILE(81, pfnIndex(t296, t236, t273));
    PROFILE(82, pfnIndex(t310, t250, t273));
    PROFILE(83, pfnFetch(t326, t267));
    PROFILE(84, pfnIndex(t327, t326, t272));
    PROFILE(85, pfnJoinIndex(t331, t1, t327, LiteralSymbol((S)"eq")));
    PROFILE(86, pfnIndex(t332, t331, LiteralI64(0)));
    PROFILE(87, pfnIndex(t333, t331, LiteralI64(1)));
    PROFILE(88, pfnIndex(t335, t2, t332));
    PROFILE(89, pfnIndex(t360, t295, t333));
    PROFILE(90, pfnIndex(t361, t296, t333));
    PROFILE(91, pfnIndex(t375, t310, t333));
    PROFILE(92, pfnDateYear(t395, t375));
    PROFILE(93, pfnMinus(t396, LiteralI32(1), t361));
    PROFILE(94, pfnMul(t397, t360, t396));
    PROFILE(95, pfnEq(t398, t335, LiteralSymbol("BRAZIL")));
    PROFILE(96, pfnMul(t399, t398, t397));
    PROFILE(97, pfnNot(t400, t398));
    PROFILE(98, pfnMul(t401, t400, LiteralF64(0)));
    PROFILE(99, pfnPlus(t402, t399, t401));
    PROFILE(100, pfnList(t403, 1, (V []){t395}));
    PROFILE(101, pfnGroup(t404, t403));
    PROFILE(102, pfnKeys(t405, t404));
    PROFILE(103, pfnValues(t406, t404));
    PROFILE(104, pfnIndex(t407, t395, t405));
    PROFILE(107, q8_peephole_fp1_0(t410,t402,t406));
    PROFILE(110, q8_peephole_fp1_1(t413,t397,t406));
    PROFILE(111, pfnDiv(t414, t410, t413));
    PROFILE(112, pfnList(t415, 1, (V []){t407}));
    PROFILE(113, pfnOrderBy(t416, t415, LiteralBool(1)));
    PROFILE(114, pfnIndex(t417, t407, t416));
    PROFILE(115, pfnIndex(t418, t414, t416));
    PROFILE(116, copyV(t419,LiteralVectorSymbol(2, (S []){"o_year", "mkt_share"})));
    PROFILE(117, pfnList(t420, 2, (V []){t417, t418}));
    PROFILE(118, pfnTable(t421, t419, t420));
    h_rtn[0] = t421;
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

// Compiling time (ms): 2.137
