// Parsing time (ms): 0.976
 // - #: 2
 // - #: 2
 // - #: 3
// Total # of fused stmts: 7
static I horse_main(V *h_rtn);
static I q10_autofusion_11(V z, V *x);
static I q10_autofusion_8(V z, V *x);
static I q10_patternindex_1(V *z, V *x, V y);
static I q10_patternindex_2(V *z, V *x, V y);
static I q10_patterncompress_12(V *z, V x, V *y);
static I q10_patternindex_3(V *z, V *x, V y);
static I q10_patternindex_4(V *z, V *x, V y);
static I q10_autofusion_10(V z, V *x);
static I q10_patternindex_5(V *z, V *x, V y);
static I q10_peephole_fp1_0(V z, V x, V y);
static I q10_patternindex_6(V *z, V *x, V y);

static I q10_autofusion_11(V z, V *x){
    V x0=x[0]; // t10
    L r0=vn(x0);
    /* Fusion: kind E */
    initV(z, H_B, r0);
    DOP(r0, vB(z,i)=AND(GEQ(vD(x0,i),19931001),LT(vD(x0,i),19940101))) R 0;
}
static I q10_autofusion_8(V z, V *x){
    V x0=x[0]; // t6
    V x1=x[1]; // t17
    /* Fusion: special index for where */
    L lenZ = 0, parZ[H_CORE], offset[H_CORE];
    DOI(H_CORE, parZ[i]=offset[i]=0)
    CHECKE(getNumOfNonZero(x1,parZ));
    DOI(H_CORE, lenZ += parZ[i])
    DOIa(H_CORE, offset[i]=parZ[i-1]+offset[i-1])
    initV(z, H_I, lenZ);
    DOT(vn(x1), if(vB(x1,i)){L c=offset[tid]++;\
        vI(z,c) = vI(x0,i);})
    R 0;
}

static I q10_patternindex_1(V *z, V *x, V y){
    V z0 = z[0]; // t48
    V z1 = z[1]; // t49
    V z2 = z[2]; // t50
    V z3 = z[3]; // t52
    V z4 = z[4]; // t53
    V z5 = z[5]; // t54
    V z6 = z[6]; // t56
    V x0 = x[0]; // t28
    V x1 = x[1]; // t29
    V x2 = x[2]; // t30
    V x3 = x[3]; // t51
    V x4 = x[4]; // t32
    V x5 = x[5]; // t33
    V x6 = x[6]; // t35
    initV(z0, H_I, vn(y));
    initV(z1, H_Q, vn(y));
    initV(z2, H_S, vn(y));
    initV(z3, H_I, vn(y));
    initV(z4, H_S, vn(y));
    initV(z5, H_E, vn(y));
    initV(z6, H_S, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vQ(z1,i) = vQ(x1, vL(y,i));
        vS(z2,i) = vS(x2, vL(y,i));
        vI(z3,i) = vI(x3, vL(y,i));
        vS(z4,i) = vS(x4, vL(y,i));
        vE(z5,i) = vE(x5, vL(y,i));
        vS(z6,i) = vS(x6, vL(y,i));
    })
    R 0;
}

static I q10_patternindex_2(V *z, V *x, V y){
    V z0 = z[0]; // t65
    V z1 = z[1]; // t75
    V z2 = z[2]; // t76
    V z3 = z[3]; // t77
    V z4 = z[4]; // t79
    V z5 = z[5]; // t80
    V z6 = z[6]; // t82
    V x0 = x[0]; // t39
    V x1 = x[1]; // t48
    V x2 = x[2]; // t49
    V x3 = x[3]; // t50
    V x4 = x[4]; // t53
    V x5 = x[5]; // t54
    V x6 = x[6]; // t56
    initV(z0, H_I, vn(y));
    initV(z1, H_I, vn(y));
    initV(z2, H_Q, vn(y));
    initV(z3, H_S, vn(y));
    initV(z4, H_S, vn(y));
    initV(z5, H_E, vn(y));
    initV(z6, H_S, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vI(z1,i) = vI(x1, vL(y,i));
        vQ(z2,i) = vQ(x2, vL(y,i));
        vS(z3,i) = vS(x3, vL(y,i));
        vS(z4,i) = vS(x4, vL(y,i));
        vE(z5,i) = vE(x5, vL(y,i));
        vS(z6,i) = vS(x6, vL(y,i));
    })
    R 0;
}

static I q10_patterncompress_12(V *z, V x, V *y){
    V z0 = z[0]; // t117
    V z1 = z[1]; // t106
    V z2 = z[2]; // t107
    V y0 = y[0]; // t101
    V y1 = y[1]; // t89
    V y2 = y[2]; // t90
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

static I q10_patternindex_3(V *z, V *x, V y){
    V z0 = z[0]; // t122
    V z1 = z[1]; // t134
    V z2 = z[2]; // t135
    V z3 = z[3]; // t136
    V z4 = z[4]; // t138
    V z5 = z[5]; // t139
    V z6 = z[6]; // t141
    V x0 = x[0]; // t61
    V x1 = x[1]; // t75
    V x2 = x[2]; // t76
    V x3 = x[3]; // t77
    V x4 = x[4]; // t79
    V x5 = x[5]; // t80
    V x6 = x[6]; // t82
    initV(z0, H_Q, vn(y));
    initV(z1, H_I, vn(y));
    initV(z2, H_Q, vn(y));
    initV(z3, H_S, vn(y));
    initV(z4, H_S, vn(y));
    initV(z5, H_E, vn(y));
    initV(z6, H_S, vn(y));
    DOP(vn(z0), {
        vQ(z0,i) = vQ(x0, vL(y,i));
        vI(z1,i) = vI(x1, vL(y,i));
        vQ(z2,i) = vQ(x2, vL(y,i));
        vS(z3,i) = vS(x3, vL(y,i));
        vS(z4,i) = vS(x4, vL(y,i));
        vE(z5,i) = vE(x5, vL(y,i));
        vS(z6,i) = vS(x6, vL(y,i));
    })
    R 0;
}

static I q10_patternindex_4(V *z, V *x, V y){
    V z0 = z[0]; // t147
    V z1 = z[1]; // t148
    V x0 = x[0]; // t106
    V x1 = x[1]; // t107
    initV(z0, H_E, vn(y));
    initV(z1, H_E, vn(y));
    DOP(vn(z0), {
        vE(z0,i) = vE(x0, vL(y,i));
        vE(z1,i) = vE(x1, vL(y,i));
    })
    R 0;
}

static I q10_autofusion_10(V z, V *x){
    V x0=x[0]; // t147
    V x1=x[1]; // t148
    L r0=vn(x0);
    /* Fusion: kind E */
    initV(z, H_E, r0);
    DOP(r0, vE(z,i)=MUL(vE(x0,i),MINUS(1,vE(x1,i)))) R 0;
}
static I q10_patternindex_5(V *z, V *x, V y){
    V z0 = z[0]; // t164
    V z1 = z[1]; // t165
    V z2 = z[2]; // t166
    V z3 = z[3]; // t167
    V z4 = z[4]; // t168
    V z5 = z[5]; // t169
    V z6 = z[6]; // t170
    V x0 = x[0]; // t134
    V x1 = x[1]; // t135
    V x2 = x[2]; // t139
    V x3 = x[3]; // t138
    V x4 = x[4]; // t122
    V x5 = x[5]; // t136
    V x6 = x[6]; // t141
    initV(z0, H_I, vn(y));
    initV(z1, H_Q, vn(y));
    initV(z2, H_E, vn(y));
    initV(z3, H_S, vn(y));
    initV(z4, H_Q, vn(y));
    initV(z5, H_S, vn(y));
    initV(z6, H_S, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vQ(z1,i) = vQ(x1, vL(y,i));
        vE(z2,i) = vE(x2, vL(y,i));
        vS(z3,i) = vS(x3, vL(y,i));
        vQ(z4,i) = vQ(x4, vL(y,i));
        vS(z5,i) = vS(x5, vL(y,i));
        vS(z6,i) = vS(x6, vL(y,i));
    })
    R 0;
}

static I q10_peephole_fp1_0(V z, V x, V y){
    // z -> t173
    initV(z, H_E, vn(y));
    DOP(vn(y), {E a=0; V t=vV(y,i); DOJ(vn(t), a+=vE(x,vL(t,j))) vE(z,i)=a;}) R 0;
}

static I q10_patternindex_6(V *z, V *x, V y){
    V z0 = z[0]; // t176
    V z1 = z[1]; // t177
    V z2 = z[2]; // t178
    V z3 = z[3]; // t179
    V z4 = z[4]; // t180
    V z5 = z[5]; // t181
    V z6 = z[6]; // t182
    V z7 = z[7]; // t183
    V x0 = x[0]; // t164
    V x1 = x[1]; // t165
    V x2 = x[2]; // t173
    V x3 = x[3]; // t166
    V x4 = x[4]; // t168
    V x5 = x[5]; // t169
    V x6 = x[6]; // t167
    V x7 = x[7]; // t170
    initV(z0, H_I, vn(y));
    initV(z1, H_Q, vn(y));
    initV(z2, H_E, vn(y));
    initV(z3, H_E, vn(y));
    initV(z4, H_Q, vn(y));
    initV(z5, H_S, vn(y));
    initV(z6, H_S, vn(y));
    initV(z7, H_S, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vQ(z1,i) = vQ(x1, vL(y,i));
        vE(z2,i) = vE(x2, vL(y,i));
        vE(z3,i) = vE(x3, vL(y,i));
        vQ(z4,i) = vQ(x4, vL(y,i));
        vS(z5,i) = vS(x5, vL(y,i));
        vS(z6,i) = vS(x6, vL(y,i));
        vS(z7,i) = vS(x7, vL(y,i));
    })
    R 0;
}


static I horse_main(V *h_rtn){
    V t100 = incV(); V t101 = incV(); V t120 = incV(); V t122 = incV(); 
    V t106 = incV(); V t107 = incV(); V t141 = incV(); V t117 = incV(); 
    V t134 = incV(); V t118 = incV(); V t135 = incV(); V t119 = incV(); 
    V t160 = incV(); V t136 = incV(); V t161 = incV(); V t170 = incV(); 
    V t162 = incV(); V t138 = incV(); V t171 = incV(); V t163 = incV(); 
    V t147 = incV(); V t139 = incV(); V t180 = incV(); V t172 = incV(); 
    V t164 = incV(); V t148 = incV(); V t181 = incV(); V t173 = incV(); 
    V t165 = incV(); V t182 = incV(); V t174 = incV(); V t166 = incV(); 
    V t158 = incV(); V t183 = incV(); V t175 = incV(); V t167 = incV(); 
    V t159 = incV(); V t184 = incV(); V t176 = incV(); V t168 = incV(); 
    V t185 = incV(); V t177 = incV(); V t169 = incV(); V t186 = incV(); 
    V t178 = incV(); V t179 = incV(); V t0 = incV(); V t1 = incV(); 
    V t2 = incV(); V t5 = incV(); V t6 = incV(); V t7 = incV(); 
    V t10 = incV(); V t30 = incV(); V t31 = incV(); V t15 = incV(); 
    V t32 = incV(); V t16 = incV(); V t33 = incV(); V t17 = incV(); 
    V t50 = incV(); V t51 = incV(); V t35 = incV(); V t27 = incV(); 
    V t52 = incV(); V t36 = incV(); V t28 = incV(); V t61 = incV(); 
    V t53 = incV(); V t37 = incV(); V t29 = incV(); V t54 = incV(); 
    V t38 = incV(); V t39 = incV(); V t80 = incV(); V t56 = incV(); 
    V t48 = incV(); V t65 = incV(); V t57 = incV(); V t49 = incV(); 
    V t90 = incV(); V t82 = incV(); V t58 = incV(); V t83 = incV(); 
    V t75 = incV(); V t59 = incV(); V t92 = incV(); V t84 = incV(); 
    V t76 = incV(); V t77 = incV(); V t79 = incV(); V t89 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("nation")));
    PROFILE(5, pfnColumnValue(t1, t0, LiteralSymbol("n_nationkey")));
    PROFILE(6, pfnColumnValue(t2, t0, LiteralSymbol("n_name")));
    PROFILE(7, pfnLoadTable(t5, LiteralSymbol("orders")));
    PROFILE(8, pfnColumnValue(t6, t5, LiteralSymbol("o_orderkey")));
    PROFILE(9, pfnColumnValue(t7, t5, LiteralSymbol("o_custkey")));
    PROFILE(10, pfnColumnValue(t10, t5, LiteralSymbol("o_orderdate")));
    PROFILE(13, q10_autofusion_11(t17, (V[]){t10}));
    PROFILE(14, pfnLoadTable(t27, LiteralSymbol("customer")));
    PROFILE(15, pfnColumnValue(t28, t27, LiteralSymbol("c_custkey")));
    PROFILE(16, pfnColumnValue(t29, t27, LiteralSymbol("c_name")));
    PROFILE(17, pfnColumnValue(t30, t27, LiteralSymbol("c_address")));
    PROFILE(18, pfnColumnValue(t31, t27, LiteralSymbol("c_nationkey")));
    PROFILE(19, pfnColumnValue(t32, t27, LiteralSymbol("c_phone")));
    PROFILE(20, pfnColumnValue(t33, t27, LiteralSymbol("c_acctbal")));
    PROFILE(21, pfnColumnValue(t35, t27, LiteralSymbol("c_comment")));
    PROFILE(22, pfnValues(t36, t7));
    PROFILE(23, pfnCompress(t37, t17, t36));
    PROFILE(25, q10_autofusion_8(t39, (V[]){t6,t17}));
    PROFILE(29, pfnFetch(t51, t31));
    PROFILE(33, q10_patternindex_1((V []){t48, t49, t50, t52, t53, t54, t56}, (V []){t28, t29, t30, t51, t32, t33, t35}, t37));
    PROFILE(34, pfnJoinIndex(t57, t1, t52, LiteralSymbol((S)"eq")));
    PROFILE(35, pfnIndex(t58, t57, LiteralI64(0)));
    PROFILE(36, pfnIndex(t59, t57, LiteralI64(1)));
    PROFILE(37, pfnIndex(t61, t2, t58));
    PROFILE(44, q10_patternindex_2((V []){t65, t75, t76, t77, t79, t80, t82}, (V []){t39, t48, t49, t50, t53, t54, t56}, t59));
    PROFILE(45, pfnLoadTable(t83, LiteralSymbol("lineitem")));
    PROFILE(46, pfnColumnValue(t84, t83, LiteralSymbol("l_orderkey")));
    PROFILE(47, pfnColumnValue(t89, t83, LiteralSymbol("l_extendedprice")));
    PROFILE(48, pfnColumnValue(t90, t83, LiteralSymbol("l_discount")));
    PROFILE(49, pfnColumnValue(t92, t83, LiteralSymbol("l_returnflag")));
    PROFILE(50, pfnEq(t100, t92, LiteralChar('R')));
    PROFILE(51, pfnFetch(t101, t84));
    PROFILE(55, q10_patterncompress_12((V []){t117, t106, t107}, t100, (V []){t101, t89, t90}));
    PROFILE(57, pfnJoinIndex(t118, t65, t117, LiteralSymbol((S)"eq")));
    PROFILE(58, pfnIndex(t119, t118, LiteralI64(0)));
    PROFILE(59, pfnIndex(t120, t118, LiteralI64(1)));
    PROFILE(66, q10_patternindex_3((V []){t122, t134, t135, t136, t138, t139, t141}, (V []){t61, t75, t76, t77, t79, t80, t82}, t119));
    PROFILE(68, q10_patternindex_4((V []){t147, t148}, (V []){t106, t107}, t120));
    PROFILE(70, q10_autofusion_10(t159, (V[]){t147,t148}));
    PROFILE(71, pfnList(t160, 7, (V []){t134, t135, t139, t138, t122, t136, t141}));
    PROFILE(72, pfnGroup(t161, t160));
    PROFILE(73, pfnKeys(t162, t161));
    PROFILE(74, pfnValues(t163, t161));
    PROFILE(81, q10_patternindex_5((V []){t164, t165, t166, t167, t168, t169, t170}, (V []){t134, t135, t139, t138, t122, t136, t141}, t162));
    PROFILE(84, q10_peephole_fp1_0(t173,t159,t163));
    PROFILE(85, pfnList(t174, 1, (V []){t173}));
    PROFILE(86, pfnOrderBy(t175, t174, LiteralBool(0)));
    PROFILE(94, q10_patternindex_6((V []){t176, t177, t178, t179, t180, t181, t182, t183}, (V []){t164, t165, t173, t166, t168, t169, t167, t170}, t175));
    PROFILE(95, copyV(t184,LiteralVectorSymbol(8, (S []){"c_custkey", "c_name", "revenue", "c_acctbal", "n_name", "c_address", "c_phone", "c_comment"})));
    PROFILE(96, pfnList(t185, 8, (V []){t176, t177, t178, t179, t180, t181, t182, t183}));
    PROFILE(97, pfnTable(t186, t184, t185));
    h_rtn[0] = t186;
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

// Compiling time (ms): 2.556
