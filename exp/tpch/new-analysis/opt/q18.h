// Parsing time (ms): 0.772
// Total # of fused stmts: 0
static I horse_main(V *h_rtn);
static I q18_peephole_fp1_0(V z, V x, V y);
static I q18_patterncompress_7(V *z, V x, V *y);
static I q18_patternindex_2(V *z, V *x, V y);
static I q18_patternindex_3(V *z, V *x, V y);
static I q18_patternindex_4(V *z, V *x, V y);
static I q18_patternindex_5(V *z, V *x, V y);
static I q18_peephole_fp1_1(V z, V x, V y);
static I q18_patternindex_6(V *z, V *x, V y);

static I q18_peephole_fp1_0(V z, V x, V y){
    // z -> t34
    initV(z, H_E, vn(y));
    DOP(vn(y), {E a=0; V t=vV(y,i); DOJ(vn(t), a+=vE(x,vL(t,j))) vE(z,i)=a;}) R 0;
}

static I q18_patterncompress_7(V *z, V x, V *y){
    V z0 = z[0]; // t50
    V z1 = z[1]; // t52
    V z2 = z[2]; // t54
    V z3 = z[3]; // t55
    V y0 = y[0]; // t40
    V y1 = y[1]; // t51
    V y2 = y[2]; // t43
    V y3 = y[3]; // t44
    L len = vn(x), k = 0;
    L lenZ = 0, parZ[H_CORE], offset[H_CORE];
    DOI(H_CORE, parZ[i]=offset[i]=0)
    CHECKE(getNumOfNonZero(x,parZ));
    DOI(H_CORE, lenZ += parZ[i])
    DOIa(H_CORE, offset[i]=parZ[i-1]+offset[i-1])
    initV(z0,H_I,lenZ);
    initV(z1,H_I,lenZ);
    initV(z2,H_E,lenZ);
    initV(z3,H_D,lenZ);
    DOT(len, if(vB(x,i)){L c=offset[tid]++;\
        vI(z0,c) = vI(y0,i);\
        vI(z1,c) = vI(y1,i);\
        vE(z2,c) = vE(y2,i);\
        vD(z3,c) = vD(y3,i);\
    })
    R 0;
}

static I q18_patternindex_2(V *z, V *x, V y){
    V z0 = z[0]; // t63
    V z1 = z[1]; // t64
    V x0 = x[0]; // t1
    V x1 = x[1]; // t2
    initV(z0, H_I, vn(y));
    initV(z1, H_Q, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vQ(z1,i) = vQ(x1, vL(y,i));
    })
    R 0;
}

static I q18_patternindex_3(V *z, V *x, V y){
    V z0 = z[0]; // t72
    V z1 = z[1]; // t75
    V z2 = z[2]; // t76
    V x0 = x[0]; // t50
    V x1 = x[1]; // t54
    V x2 = x[2]; // t55
    initV(z0, H_I, vn(y));
    initV(z1, H_E, vn(y));
    initV(z2, H_D, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vE(z1,i) = vE(x1, vL(y,i));
        vD(z2,i) = vD(x2, vL(y,i));
    })
    R 0;
}

static I q18_patternindex_4(V *z, V *x, V y){
    V z0 = z[0]; // t102
    V z1 = z[1]; // t103
    V z2 = z[2]; // t110
    V z3 = z[3]; // t113
    V z4 = z[4]; // t114
    V x0 = x[0]; // t63
    V x1 = x[1]; // t64
    V x2 = x[2]; // t72
    V x3 = x[3]; // t75
    V x4 = x[4]; // t76
    initV(z0, H_I, vn(y));
    initV(z1, H_Q, vn(y));
    initV(z2, H_I, vn(y));
    initV(z3, H_E, vn(y));
    initV(z4, H_D, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vQ(z1,i) = vQ(x1, vL(y,i));
        vI(z2,i) = vI(x2, vL(y,i));
        vE(z3,i) = vE(x3, vL(y,i));
        vD(z4,i) = vD(x4, vL(y,i));
    })
    R 0;
}

static I q18_patternindex_5(V *z, V *x, V y){
    V z0 = z[0]; // t139
    V z1 = z[1]; // t140
    V z2 = z[2]; // t141
    V z3 = z[3]; // t142
    V z4 = z[4]; // t143
    V x0 = x[0]; // t103
    V x1 = x[1]; // t102
    V x2 = x[2]; // t110
    V x3 = x[3]; // t114
    V x4 = x[4]; // t113
    initV(z0, H_Q, vn(y));
    initV(z1, H_I, vn(y));
    initV(z2, H_I, vn(y));
    initV(z3, H_D, vn(y));
    initV(z4, H_E, vn(y));
    DOP(vn(z0), {
        vQ(z0,i) = vQ(x0, vL(y,i));
        vI(z1,i) = vI(x1, vL(y,i));
        vI(z2,i) = vI(x2, vL(y,i));
        vD(z3,i) = vD(x3, vL(y,i));
        vE(z4,i) = vE(x4, vL(y,i));
    })
    R 0;
}

static I q18_peephole_fp1_1(V z, V x, V y){
    // z -> t146
    initV(z, H_E, vn(y));
    DOP(vn(y), {E a=0; V t=vV(y,i); DOJ(vn(t), a+=vE(x,vL(t,j))) vE(z,i)=a;}) R 0;
}

static I q18_patternindex_6(V *z, V *x, V y){
    V z0 = z[0]; // t149
    V z1 = z[1]; // t150
    V z2 = z[2]; // t151
    V z3 = z[3]; // t152
    V z4 = z[4]; // t153
    V z5 = z[5]; // t154
    V x0 = x[0]; // t139
    V x1 = x[1]; // t140
    V x2 = x[2]; // t141
    V x3 = x[3]; // t142
    V x4 = x[4]; // t143
    V x5 = x[5]; // t146
    initV(z0, H_Q, vn(y));
    initV(z1, H_I, vn(y));
    initV(z2, H_I, vn(y));
    initV(z3, H_D, vn(y));
    initV(z4, H_E, vn(y));
    initV(z5, H_E, vn(y));
    DOP(vn(z0), {
        vQ(z0,i) = vQ(x0, vL(y,i));
        vI(z1,i) = vI(x1, vL(y,i));
        vI(z2,i) = vI(x2, vL(y,i));
        vD(z3,i) = vD(x3, vL(y,i));
        vE(z4,i) = vE(x4, vL(y,i));
        vE(z5,i) = vE(x5, vL(y,i));
    })
    R 0;
}


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
    PROFILE(18, q18_peephole_fp1_0(t34,t14,t30));
    PROFILE(19, pfnGt(t35, t34, LiteralF64(300)));
    PROFILE(20, pfnCompress(t36, t35, t31));
    PROFILE(21, pfnLoadTable(t39, LiteralSymbol("orders")));
    PROFILE(22, pfnColumnValue(t40, t39, LiteralSymbol("o_orderkey")));
    PROFILE(23, pfnColumnValue(t41, t39, LiteralSymbol("o_custkey")));
    PROFILE(24, pfnColumnValue(t43, t39, LiteralSymbol("o_totalprice")));
    PROFILE(25, pfnColumnValue(t44, t39, LiteralSymbol("o_orderdate")));
    PROFILE(26, pfnMember(t49, t40, t36));
    PROFILE(28, pfnFetch(t51, t41));
    PROFILE(31, q18_patterncompress_7((V []){t50, t52, t54, t55}, t49, (V []){t40, t51, t43, t44}));
    PROFILE(32, pfnJoinIndex(t60, t1, t52, LiteralSymbol((S)"eq")));
    PROFILE(33, pfnIndex(t61, t60, LiteralI64(0)));
    PROFILE(34, pfnIndex(t62, t60, LiteralI64(1)));
    PROFILE(36, q18_patternindex_2((V []){t63, t64}, (V []){t1, t2}, t61));
    PROFILE(39, q18_patternindex_3((V []){t72, t75, t76}, (V []){t50, t54, t55}, t62));
    PROFILE(40, pfnLoadTable(t81, LiteralSymbol("lineitem")));
    PROFILE(41, pfnColumnValue(t82, t81, LiteralSymbol("l_orderkey")));
    PROFILE(42, pfnColumnValue(t86, t81, LiteralSymbol("l_quantity")));
    PROFILE(43, pfnFetch(t98, t82));
    PROFILE(44, pfnJoinIndex(t99, t72, t98, LiteralSymbol((S)"eq")));
    PROFILE(45, pfnIndex(t100, t99, LiteralI64(0)));
    PROFILE(46, pfnIndex(t101, t99, LiteralI64(1)));
    PROFILE(51, q18_patternindex_4((V []){t102, t103, t110, t113, t114}, (V []){t63, t64, t72, t75, t76}, t100));
    PROFILE(52, pfnIndex(t123, t86, t101));
    PROFILE(53, pfnList(t135, 5, (V []){t103, t102, t110, t114, t113}));
    PROFILE(54, pfnGroup(t136, t135));
    PROFILE(55, pfnKeys(t137, t136));
    PROFILE(56, pfnValues(t138, t136));
    PROFILE(61, q18_patternindex_5((V []){t139, t140, t141, t142, t143}, (V []){t103, t102, t110, t114, t113}, t137));
    PROFILE(64, q18_peephole_fp1_1(t146,t123,t138));
    PROFILE(65, pfnList(t147, 2, (V []){t143, t142}));
    PROFILE(66, pfnOrderBy(t148, t147, LiteralVectorBool(2, (B []){0, 1})));
    PROFILE(72, q18_patternindex_6((V []){t149, t150, t151, t152, t153, t154}, (V []){t139, t140, t141, t142, t143, t146}, t148));
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

// Compiling time (ms): 1.749
