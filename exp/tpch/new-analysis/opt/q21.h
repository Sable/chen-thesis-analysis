// Parsing time (ms): 0.783
// Total # of fused stmts: 0
static I horse_main(V *h_rtn);
static I q21_patternindex_0(V *z, V *x, V y);
static I q21_patterncompress_4(V *z, V x, V *y);
static I q21_patternindex_1(V *z, V *x, V y);
static I q21_patternindex_2(V *z, V *x, V y);
static I q21_patterncompress_5(V *z, V x, V *y);
static I q21_patterncompress_6(V *z, V x, V *y);
static I q21_patternindex_3(V *z, V *x, V y);

static I q21_patternindex_0(V *z, V *x, V y){
    V z0 = z[0]; // t26
    V z1 = z[1]; // t27
    V x0 = x[0]; // t11
    V x1 = x[1]; // t12
    initV(z0, H_I, vn(y));
    initV(z1, H_S, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vS(z1,i) = vS(x1, vL(y,i));
    })
    R 0;
}

static I q21_patterncompress_4(V *z, V x, V *y){
    V z0 = z[0]; // t83
    V z1 = z[1]; // t54
    V y0 = y[0]; // t52
    V y1 = y[1]; // t37
    L len = vn(x), k = 0;
    L lenZ = 0, parZ[H_CORE], offset[H_CORE];
    DOI(H_CORE, parZ[i]=offset[i]=0)
    CHECKE(getNumOfNonZero(x,parZ));
    DOI(H_CORE, lenZ += parZ[i])
    DOIa(H_CORE, offset[i]=parZ[i-1]+offset[i-1])
    initV(z0,H_I,lenZ);
    initV(z1,H_I,lenZ);
    DOT(len, if(vB(x,i)){L c=offset[tid]++;\
        vI(z0,c) = vI(y0,i);\
        vI(z1,c) = vI(y1,i);\
    })
    R 0;
}

static I q21_patternindex_1(V *z, V *x, V y){
    V z0 = z[0]; // t84
    V z1 = z[1]; // t86
    V x0 = x[0]; // t83
    V x1 = x[1]; // t54
    initV(z0, H_I, vn(y));
    initV(z1, H_I, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vI(z1,i) = vI(x1, vL(y,i));
    })
    R 0;
}

static I q21_patternindex_2(V *z, V *x, V y){
    V z0 = z[0]; // t128
    V z1 = z[1]; // t134
    V z2 = z[2]; // t136
    V x0 = x[0]; // t77
    V x1 = x[1]; // t84
    V x2 = x[2]; // t86
    initV(z0, H_S, vn(y));
    initV(z1, H_I, vn(y));
    initV(z2, H_I, vn(y));
    DOP(vn(z0), {
        vS(z0,i) = vS(x0, vL(y,i));
        vI(z1,i) = vI(x1, vL(y,i));
        vI(z2,i) = vI(x2, vL(y,i));
    })
    R 0;
}

static I q21_patterncompress_5(V *z, V x, V *y){
    V z0 = z[0]; // t194
    V z1 = z[1]; // t180
    V y0 = y[0]; // t178
    V y1 = y[1]; // t163
    L len = vn(x), k = 0;
    L lenZ = 0, parZ[H_CORE], offset[H_CORE];
    DOI(H_CORE, parZ[i]=offset[i]=0)
    CHECKE(getNumOfNonZero(x,parZ));
    DOI(H_CORE, lenZ += parZ[i])
    DOIa(H_CORE, offset[i]=parZ[i-1]+offset[i-1])
    initV(z0,H_I,lenZ);
    initV(z1,H_I,lenZ);
    DOT(len, if(vB(x,i)){L c=offset[tid]++;\
        vI(z0,c) = vI(y0,i);\
        vI(z1,c) = vI(y1,i);\
    })
    R 0;
}

static I q21_patterncompress_6(V *z, V x, V *y){
    V z0 = z[0]; // t207
    V z1 = z[1]; // t213
    V z2 = z[2]; // t215
    V y0 = y[0]; // t128
    V y1 = y[1]; // t134
    V y2 = y[2]; // t136
    L len = vn(x), k = 0;
    L lenZ = 0, parZ[H_CORE], offset[H_CORE];
    DOI(H_CORE, parZ[i]=offset[i]=0)
    CHECKE(getNumOfNonZero(x,parZ));
    DOI(H_CORE, lenZ += parZ[i])
    DOIa(H_CORE, offset[i]=parZ[i-1]+offset[i-1])
    initV(z0,H_S,lenZ);
    initV(z1,H_I,lenZ);
    initV(z2,H_I,lenZ);
    DOT(len, if(vB(x,i)){L c=offset[tid]++;\
        vS(z0,c) = vS(y0,i);\
        vI(z1,c) = vI(y1,i);\
        vI(z2,c) = vI(y2,i);\
    })
    R 0;
}

static I q21_patternindex_3(V *z, V *x, V y){
    V z0 = z[0]; // t307
    V z1 = z[1]; // t308
    V x0 = x[0]; // t302
    V x1 = x[1]; // t304
    initV(z0, H_S, vn(y));
    initV(z1, H_L, vn(y));
    DOP(vn(z0), {
        vS(z0,i) = vS(x0, vL(y,i));
        vL(z1,i) = vL(x1, vL(y,i));
    })
    R 0;
}


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
    PROFILE(15, q21_patternindex_0((V []){t26, t27}, (V []){t11, t12}, t21));
    PROFILE(16, pfnLoadTable(t34, LiteralSymbol("lineitem")));
    PROFILE(17, pfnColumnValue(t35, t34, LiteralSymbol("l_orderkey")));
    PROFILE(18, pfnColumnValue(t37, t34, LiteralSymbol("l_suppkey")));
    PROFILE(19, pfnColumnValue(t46, t34, LiteralSymbol("l_commitdate")));
    PROFILE(20, pfnColumnValue(t47, t34, LiteralSymbol("l_receiptdate")));
    PROFILE(21, pfnGt(t51, t47, t46));
    PROFILE(22, pfnFetch(t52, t35));
    PROFILE(25, q21_patterncompress_4((V []){t83, t54}, t51, (V []){t52, t37}));
    PROFILE(26, pfnJoinIndex(t68, t26, t54, LiteralSymbol((S)"eq")));
    PROFILE(27, pfnIndex(t69, t68, LiteralI64(0)));
    PROFILE(28, pfnIndex(t70, t68, LiteralI64(1)));
    PROFILE(29, pfnIndex(t77, t27, t69));
    PROFILE(32, q21_patternindex_1((V []){t84, t86}, (V []){t83, t54}, t70));
    PROFILE(33, pfnLoadTable(t100, LiteralSymbol("orders")));
    PROFILE(34, pfnColumnValue(t101, t100, LiteralSymbol("o_orderkey")));
    PROFILE(35, pfnColumnValue(t103, t100, LiteralSymbol("o_orderstatus")));
    PROFILE(36, pfnEq(t110, t103, LiteralChar('F')));
    PROFILE(37, pfnCompress(t111, t110, t101));
    PROFILE(38, pfnJoinIndex(t120, t111, t84, LiteralSymbol((S)"eq")));
    PROFILE(39, pfnIndex(t122, t120, LiteralI64(1)));
    PROFILE(42, q21_patternindex_2((V []){t128, t134, t136}, (V []){t77, t84, t86}, t122));
    PROFILE(43, pfnLoadTable(t160, LiteralSymbol("lineitem")));
    PROFILE(44, pfnColumnValue(t161, t160, LiteralSymbol("l_orderkey")));
    PROFILE(45, pfnColumnValue(t163, t160, LiteralSymbol("l_suppkey")));
    PROFILE(46, pfnColumnValue(t172, t160, LiteralSymbol("l_commitdate")));
    PROFILE(47, pfnColumnValue(t173, t160, LiteralSymbol("l_receiptdate")));
    PROFILE(48, pfnGt(t177, t173, t172));
    PROFILE(49, pfnFetch(t178, t161));
    PROFILE(52, q21_patterncompress_5((V []){t194, t180}, t177, (V []){t178, t163}));
    PROFILE(54, pfnList(t195, 2, (V []){t134, t136}));
    PROFILE(55, pfnList(t196, 2, (V []){t194, t180}));
    PROFILE(56, pfnJoinIndex(t197, t195, t196, LiteralVectorSymbol(2, (S []){"eq", "neq"})));
    PROFILE(57, pfnIndex(t198, t197, LiteralI64(0)));
    PROFILE(58, pfnLen(t199, t134));
    PROFILE(59, pfnVector(t200, t199, LiteralBool(1)));
    PROFILE(60, pfnIndexA(t201, t200, t198, LiteralBool(0)));
    PROFILE(63, q21_patterncompress_6((V []){t207, t213, t215}, t201, (V []){t128, t134, t136}));
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
    PROFILE(85, q21_patternindex_3((V []){t307, t308}, (V []){t302, t304}, t306));
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

// Compiling time (ms): 2.033
