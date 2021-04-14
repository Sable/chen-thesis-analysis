// Parsing time (ms): 0.628
 // - #: 2
 // - #: 2
// Total # of fused stmts: 4
static I horse_main(V *h_rtn);
static I q3_autofusion_6(V z, V *x);
static I q3_patternindex_1(V *z, V *x, V y);
static I q3_patterncompress_8(V *z, V x, V *y);
static I q3_patternindex_2(V *z, V *x, V y);
static I q3_autofusion_7(V z, V *x);
static I q3_peephole_fp1_0(V z, V x, V y);
static I q3_patternindex_3(V *z, V *x, V y);
static I q3_patternindex_4(V *z, V *x, V y);

static I q3_autofusion_6(V z, V *x){
    V x0=x[0]; // t9
    V x1=x[1]; // t29
    V x2=x[2]; // t40
    /* Fusion: special index for compress */
    L lenZ = 0, parZ[H_CORE], offset[H_CORE];
    DOI(H_CORE, parZ[i]=offset[i]=0)
    CHECKE(getNumOfNonZero(x1,parZ));
    DOI(H_CORE, lenZ += parZ[i])
    DOIa(H_CORE, offset[i]=parZ[i-1]+offset[i-1])
    initV(z, H_B, lenZ);
    DOT(vn(x1), if(vB(x1,i)){L c=offset[tid]++;\
        vB(z,c) = vB(x0,vL(x2,i));})
    R 0;
}

static I q3_patternindex_1(V *z, V *x, V y){
    V z0 = z[0]; // t54
    V z1 = z[1]; // t58
    V z2 = z[2]; // t61
    V x0 = x[0]; // t20
    V x1 = x[1]; // t24
    V x2 = x[2]; // t27
    initV(z0, H_I, vn(y));
    initV(z1, H_D, vn(y));
    initV(z2, H_I, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vD(z1,i) = vD(x1, vL(y,i));
        vI(z2,i) = vI(x2, vL(y,i));
    })
    R 0;
}

static I q3_patterncompress_8(V *z, V x, V *y){
    V z0 = z[0]; // t82
    V z1 = z[1]; // t87
    V z2 = z[2]; // t88
    V y0 = y[0]; // t81
    V y1 = y[1]; // t69
    V y2 = y[2]; // t70
    L len = vn(x), k = 0;
    L lenZ = 0, parZ[H_CORE], offset[H_CORE];
    DOI(H_CORE, parZ[i]=offset[i]=0)
    CHECKE(getNumOfNonZero(x,parZ));
    DOI(H_CORE, lenZ += parZ[i])
    DOIa(H_CORE, offset[i]=parZ[i-1]+offset[i-1])
    initV(z0,H_I,lenZ);
    initV(z1,H_E,lenZ);
    initV(z2,H_E,lenZ);
    DOT(len, if(vB(x,i)){L c=offset[tid]++;\
        vI(z0,c) = vI(y0,i);\
        vE(z1,c) = vE(y1,i);\
        vE(z2,c) = vE(y2,i);\
    })
    R 0;
}

static I q3_patternindex_2(V *z, V *x, V y){
    V z0 = z[0]; // t104
    V z1 = z[1]; // t105
    V z2 = z[2]; // t106
    V x0 = x[0]; // t54
    V x1 = x[1]; // t58
    V x2 = x[2]; // t61
    initV(z0, H_I, vn(y));
    initV(z1, H_D, vn(y));
    initV(z2, H_I, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vD(z1,i) = vD(x1, vL(y,i));
        vI(z2,i) = vI(x2, vL(y,i));
    })
    R 0;
}

static I q3_autofusion_7(V z, V *x){
    V x0=x[0]; // t87
    V x1=x[1]; // t88
    L r0=vn(x0);
    /* Fusion: kind E */
    initV(z, H_E, r0);
    DOP(r0, vE(z,i)=MUL(vE(x0,i),MINUS(1,vE(x1,i)))) R 0;
}
static I q3_peephole_fp1_0(V z, V x, V y){
    // z -> t117
    initV(z, H_E, vn(y));
    DOP(vn(y), {E a=0; V t=vV(y,i); DOJ(vn(t), a+=vE(x,vL(t,j))) vE(z,i)=a;}) R 0;
}

static I q3_patternindex_3(V *z, V *x, V y){
    V z0 = z[0]; // t124
    V z1 = z[1]; // t125
    V z2 = z[2]; // t126
    V z3 = z[3]; // t127
    V x0 = x[0]; // t108
    V x1 = x[1]; // t104
    V x2 = x[2]; // t105
    V x3 = x[3]; // t106
    initV(z0, H_L, vn(y));
    initV(z1, H_I, vn(y));
    initV(z2, H_D, vn(y));
    initV(z3, H_I, vn(y));
    DOP(vn(z0), {
        vL(z0,i) = vL(x0, vL(y,i));
        vI(z1,i) = vI(x1, vL(y,i));
        vD(z2,i) = vD(x2, vL(y,i));
        vI(z3,i) = vI(x3, vL(y,i));
    })
    R 0;
}

static I q3_patternindex_4(V *z, V *x, V y){
    V z0 = z[0]; // t136
    V z1 = z[1]; // t137
    V z2 = z[2]; // t138
    V z3 = z[3]; // t139
    V x0 = x[0]; // t125
    V x1 = x[1]; // t133
    V x2 = x[2]; // t126
    V x3 = x[3]; // t127
    initV(z0, H_I, vn(y));
    initV(z1, H_E, vn(y));
    initV(z2, H_D, vn(y));
    initV(z3, H_I, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vE(z1,i) = vE(x1, vL(y,i));
        vD(z2,i) = vD(x2, vL(y,i));
        vI(z3,i) = vI(x3, vL(y,i));
    })
    R 0;
}


static I horse_main(V *h_rtn){
    V t100 = incV(); V t101 = incV(); V t110 = incV(); V t102 = incV(); 
    V t111 = incV(); V t103 = incV(); V t120 = incV(); V t112 = incV(); 
    V t104 = incV(); V t121 = incV(); V t113 = incV(); V t105 = incV(); 
    V t122 = incV(); V t114 = incV(); V t106 = incV(); V t123 = incV(); 
    V t115 = incV(); V t107 = incV(); V t140 = incV(); V t124 = incV(); 
    V t116 = incV(); V t108 = incV(); V t141 = incV(); V t133 = incV(); 
    V t125 = incV(); V t117 = incV(); V t109 = incV(); V t142 = incV(); 
    V t134 = incV(); V t126 = incV(); V t135 = incV(); V t127 = incV(); 
    V t136 = incV(); V t137 = incV(); V t129 = incV(); V t138 = incV(); 
    V t139 = incV(); V t0 = incV(); V t7 = incV(); V t9 = incV(); 
    V t20 = incV(); V t21 = incV(); V t40 = incV(); V t24 = incV(); 
    V t41 = incV(); V t42 = incV(); V t27 = incV(); V t19 = incV(); 
    V t44 = incV(); V t61 = incV(); V t45 = incV(); V t29 = incV(); 
    V t70 = incV(); V t54 = incV(); V t63 = incV(); V t80 = incV(); 
    V t64 = incV(); V t81 = incV(); V t82 = incV(); V t74 = incV(); 
    V t58 = incV(); V t69 = incV(); V t87 = incV(); V t88 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("customer")));
    PROFILE(5, pfnColumnValue(t7, t0, LiteralSymbol("c_mktsegment")));
    PROFILE(6, pfnEq(t9, t7, LiteralSymbol("BUILDING")));
    PROFILE(7, pfnLoadTable(t19, LiteralSymbol("orders")));
    PROFILE(8, pfnColumnValue(t20, t19, LiteralSymbol("o_orderkey")));
    PROFILE(9, pfnColumnValue(t21, t19, LiteralSymbol("o_custkey")));
    PROFILE(10, pfnColumnValue(t24, t19, LiteralSymbol("o_orderdate")));
    PROFILE(11, pfnColumnValue(t27, t19, LiteralSymbol("o_shippriority")));
    PROFILE(12, pfnLt(t29, t24, LiteralDate(19950315)));
    PROFILE(13, pfnValues(t40, t21));
    PROFILE(15, q3_autofusion_6(t42, (V[]){t9,t29,t40}));
    PROFILE(16, pfnWhere(t44, t29));
    PROFILE(17, pfnCompress(t45, t42, t44));
    PROFILE(20, q3_patternindex_1((V []){t54, t58, t61}, (V []){t20, t24, t27}, t45));
    PROFILE(21, pfnLoadTable(t63, LiteralSymbol("lineitem")));
    PROFILE(22, pfnColumnValue(t64, t63, LiteralSymbol("l_orderkey")));
    PROFILE(23, pfnColumnValue(t69, t63, LiteralSymbol("l_extendedprice")));
    PROFILE(24, pfnColumnValue(t70, t63, LiteralSymbol("l_discount")));
    PROFILE(25, pfnColumnValue(t74, t63, LiteralSymbol("l_shipdate")));
    PROFILE(26, pfnGt(t80, t74, LiteralDate(19950315)));
    PROFILE(27, pfnFetch(t81, t64));
    PROFILE(30, q3_patterncompress_8((V []){t82, t87, t88}, t80, (V []){t81, t69, t70}));
    PROFILE(31, pfnList(t100, 3, (V []){t54, t58, t61}));
    PROFILE(32, pfnGroup(t101, t100));
    PROFILE(33, pfnKeys(t102, t101));
    PROFILE(34, pfnValues(t103, t101));
    PROFILE(37, q3_patternindex_2((V []){t104, t105, t106}, (V []){t54, t58, t61}, t102));
    PROFILE(38, pfnEach(t107, t103, pfnLen));
    PROFILE(39, pfnRaze(t108, t107));
    PROFILE(41, q3_autofusion_7(t110, (V[]){t87,t88}));
    PROFILE(42, pfnList(t111, 1, (V []){t82}));
    PROFILE(43, pfnGroup(t112, t111));
    PROFILE(44, pfnKeys(t113, t112));
    PROFILE(45, pfnValues(t114, t112));
    PROFILE(48, q3_peephole_fp1_0(t117,t110,t114));
    PROFILE(49, pfnIndex(t120, t82, t113));
    PROFILE(50, pfnJoinIndex(t121, t104, t120, LiteralSymbol((S)"eq")));
    PROFILE(51, pfnIndex(t122, t121, LiteralI64(0)));
    PROFILE(52, pfnIndex(t123, t121, LiteralI64(1)));
    PROFILE(56, q3_patternindex_3((V []){t124, t125, t126, t127}, (V []){t108, t104, t105, t106}, t122));
    PROFILE(57, pfnIndex(t129, t117, t123));
    PROFILE(58, pfnMul(t133, t129, t124));
    PROFILE(59, pfnList(t134, 2, (V []){t133, t126}));
    PROFILE(60, pfnOrderBy(t135, t134, LiteralVectorBool(2, (B []){0, 1})));
    PROFILE(64, q3_patternindex_4((V []){t136, t137, t138, t139}, (V []){t125, t133, t126, t127}, t135));
    PROFILE(65, copyV(t140,LiteralVectorSymbol(4, (S []){"l_orderkey", "revenue", "o_orderdate", "o_shippriority"})));
    PROFILE(66, pfnList(t141, 4, (V []){t136, t137, t138, t139}));
    PROFILE(67, pfnTable(t142, t140, t141));
    h_rtn[0] = t142;
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

// Compiling time (ms): 1.619
