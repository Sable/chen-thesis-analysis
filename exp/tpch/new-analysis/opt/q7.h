// Parsing time (ms): 0.977
 // - #: 2
 // - #: 3
// Total # of fused stmts: 5
static I horse_main(V *h_rtn);
static I q7_patternindex_1(V *z, V *x, V y);
static I q7_patternindex_2(V *z, V *x, V y);
static I q7_patternindex_3(V *z, V *x, V y);
static I q7_patternindex_4(V *z, V *x, V y);
static I q7_autofusion_13(V z, V *x);
static I q7_patterncompress_14(V *z, V x, V *y);
static I q7_patternindex_5(V *z, V *x, V y);
static I q7_patternindex_6(V *z, V *x, V y);
static I q7_patternindex_7(V *z, V *x, V y);
static I q7_autofusion_12(V z, V *x);
static I q7_patternindex_8(V *z, V *x, V y);
static I q7_peephole_fp1_0(V z, V x, V y);
static I q7_patternindex_9(V *z, V *x, V y);

static I q7_patternindex_1(V *z, V *x, V y){
    V z0 = z[0]; // t36
    V z1 = z[1]; // t37
    V x0 = x[0]; // t9
    V x1 = x[1]; // t10
    initV(z0, H_I, vn(y));
    initV(z1, H_Q, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vQ(z1,i) = vQ(x1, vL(y,i));
    })
    R 0;
}

static I q7_patternindex_2(V *z, V *x, V y){
    V z0 = z[0]; // t41
    V z1 = z[1]; // t42
    V x0 = x[0]; // t14
    V x1 = x[1]; // t15
    initV(z0, H_I, vn(y));
    initV(z1, H_Q, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vQ(z1,i) = vQ(x1, vL(y,i));
    })
    R 0;
}

static I q7_patternindex_3(V *z, V *x, V y){
    V z0 = z[0]; // t60
    V z1 = z[1]; // t63
    V z2 = z[2]; // t64
    V x0 = x[0]; // t37
    V x1 = x[1]; // t41
    V x2 = x[2]; // t42
    initV(z0, H_Q, vn(y));
    initV(z1, H_I, vn(y));
    initV(z2, H_Q, vn(y));
    DOP(vn(z0), {
        vQ(z0,i) = vQ(x0, vL(y,i));
        vI(z1,i) = vI(x1, vL(y,i));
        vQ(z2,i) = vQ(x2, vL(y,i));
    })
    R 0;
}

static I q7_patternindex_4(V *z, V *x, V y){
    V z0 = z[0]; // t90
    V z1 = z[1]; // t93
    V z2 = z[2]; // t94
    V x0 = x[0]; // t60
    V x1 = x[1]; // t63
    V x2 = x[2]; // t64
    initV(z0, H_Q, vn(y));
    initV(z1, H_I, vn(y));
    initV(z2, H_Q, vn(y));
    DOP(vn(z0), {
        vQ(z0,i) = vQ(x0, vL(y,i));
        vI(z1,i) = vI(x1, vL(y,i));
        vQ(z2,i) = vQ(x2, vL(y,i));
    })
    R 0;
}

static I q7_autofusion_13(V z, V *x){
    V x0=x[0]; // t125
    L r0=vn(x0);
    /* Fusion: kind E */
    initV(z, H_B, r0);
    DOP(r0, vB(z,i)=AND(GEQ(vD(x0,i),19950101),LEQ(vD(x0,i),19961231))) R 0;
}
static I q7_patterncompress_14(V *z, V x, V *y){
    V z0 = z[0]; // t150
    V z1 = z[1]; // t136
    V z2 = z[2]; // t139
    V z3 = z[3]; // t140
    V z4 = z[4]; // t144
    V y0 = y[0]; // t134
    V y1 = y[1]; // t117
    V y2 = y[2]; // t120
    V y3 = y[3]; // t121
    V y4 = y[4]; // t125
    L len = vn(x), k = 0;
    L lenZ = 0, parZ[H_CORE], offset[H_CORE];
    DOI(H_CORE, parZ[i]=offset[i]=0)
    CHECKE(getNumOfNonZero(x,parZ));
    DOI(H_CORE, lenZ += parZ[i])
    DOIa(H_CORE, offset[i]=parZ[i-1]+offset[i-1])
    initV(z0,H_I,lenZ);
    initV(z1,H_I,lenZ);
    initV(z2,H_E,lenZ);
    initV(z3,H_E,lenZ);
    initV(z4,H_D,lenZ);
    DOT(len, if(vB(x,i)){L c=offset[tid]++;\
        vI(z0,c) = vI(y0,i);\
        vI(z1,c) = vI(y1,i);\
        vE(z2,c) = vE(y2,i);\
        vE(z3,c) = vE(y3,i);\
        vD(z4,c) = vD(y4,i);\
    })
    R 0;
}

static I q7_patternindex_5(V *z, V *x, V y){
    V z0 = z[0]; // t155
    V z1 = z[1]; // t158
    V z2 = z[2]; // t159
    V x0 = x[0]; // t90
    V x1 = x[1]; // t93
    V x2 = x[2]; // t94
    initV(z0, H_Q, vn(y));
    initV(z1, H_I, vn(y));
    initV(z2, H_Q, vn(y));
    DOP(vn(z0), {
        vQ(z0,i) = vQ(x0, vL(y,i));
        vI(z1,i) = vI(x1, vL(y,i));
        vQ(z2,i) = vQ(x2, vL(y,i));
    })
    R 0;
}

static I q7_patternindex_6(V *z, V *x, V y){
    V z0 = z[0]; // t181
    V z1 = z[1]; // t184
    V z2 = z[2]; // t185
    V z3 = z[3]; // t189
    V x0 = x[0]; // t136
    V x1 = x[1]; // t139
    V x2 = x[2]; // t140
    V x3 = x[3]; // t144
    initV(z0, H_I, vn(y));
    initV(z1, H_E, vn(y));
    initV(z2, H_E, vn(y));
    initV(z3, H_D, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vE(z1,i) = vE(x1, vL(y,i));
        vE(z2,i) = vE(x2, vL(y,i));
        vD(z3,i) = vD(x3, vL(y,i));
    })
    R 0;
}

static I q7_patternindex_7(V *z, V *x, V y){
    V z0 = z[0]; // t209
    V z1 = z[1]; // t213
    V z2 = z[2]; // t238
    V z3 = z[3]; // t239
    V z4 = z[4]; // t243
    V x0 = x[0]; // t155
    V x1 = x[1]; // t159
    V x2 = x[2]; // t184
    V x3 = x[3]; // t185
    V x4 = x[4]; // t189
    initV(z0, H_Q, vn(y));
    initV(z1, H_Q, vn(y));
    initV(z2, H_E, vn(y));
    initV(z3, H_E, vn(y));
    initV(z4, H_D, vn(y));
    DOP(vn(z0), {
        vQ(z0,i) = vQ(x0, vL(y,i));
        vQ(z1,i) = vQ(x1, vL(y,i));
        vE(z2,i) = vE(x2, vL(y,i));
        vE(z3,i) = vE(x3, vL(y,i));
        vD(z4,i) = vD(x4, vL(y,i));
    })
    R 0;
}

static I q7_autofusion_12(V z, V *x){
    V x0=x[0]; // t238
    V x1=x[1]; // t239
    L r0=vn(x0);
    /* Fusion: kind E */
    initV(z, H_E, r0);
    DOP(r0, vE(z,i)=MUL(vE(x0,i),MINUS(1,vE(x1,i)))) R 0;
}
static I q7_patternindex_8(V *z, V *x, V y){
    V z0 = z[0]; // t256
    V z1 = z[1]; // t257
    V z2 = z[2]; // t258
    V x0 = x[0]; // t213
    V x1 = x[1]; // t209
    V x2 = x[2]; // t249
    initV(z0, H_Q, vn(y));
    initV(z1, H_Q, vn(y));
    initV(z2, H_H, vn(y));
    DOP(vn(z0), {
        vQ(z0,i) = vQ(x0, vL(y,i));
        vQ(z1,i) = vQ(x1, vL(y,i));
        vH(z2,i) = vH(x2, vL(y,i));
    })
    R 0;
}

static I q7_peephole_fp1_0(V z, V x, V y){
    // z -> t261
    initV(z, H_E, vn(y));
    DOP(vn(y), {E a=0; V t=vV(y,i); DOJ(vn(t), a+=vE(x,vL(t,j))) vE(z,i)=a;}) R 0;
}

static I q7_patternindex_9(V *z, V *x, V y){
    V z0 = z[0]; // t264
    V z1 = z[1]; // t265
    V z2 = z[2]; // t266
    V z3 = z[3]; // t267
    V x0 = x[0]; // t256
    V x1 = x[1]; // t257
    V x2 = x[2]; // t258
    V x3 = x[3]; // t261
    initV(z0, H_Q, vn(y));
    initV(z1, H_Q, vn(y));
    initV(z2, H_H, vn(y));
    initV(z3, H_E, vn(y));
    DOP(vn(z0), {
        vQ(z0,i) = vQ(x0, vL(y,i));
        vQ(z1,i) = vQ(x1, vL(y,i));
        vH(z2,i) = vH(x2, vL(y,i));
        vE(z3,i) = vE(x3, vL(y,i));
    })
    R 0;
}


static I horse_main(V *h_rtn){
    V t200 = incV(); V t120 = incV(); V t121 = incV(); V t105 = incV(); 
    V t114 = incV(); V t131 = incV(); V t115 = incV(); V t140 = incV(); 
    V t132 = incV(); V t213 = incV(); V t133 = incV(); V t125 = incV(); 
    V t117 = incV(); V t150 = incV(); V t134 = incV(); V t151 = incV(); 
    V t152 = incV(); V t144 = incV(); V t136 = incV(); V t209 = incV(); 
    V t153 = incV(); V t250 = incV(); V t251 = incV(); V t243 = incV(); 
    V t155 = incV(); V t139 = incV(); V t260 = incV(); V t252 = incV(); 
    V t261 = incV(); V t253 = incV(); V t181 = incV(); V t270 = incV(); 
    V t262 = incV(); V t254 = incV(); V t238 = incV(); V t158 = incV(); 
    V t263 = incV(); V t255 = incV(); V t239 = incV(); V t159 = incV(); 
    V t264 = incV(); V t256 = incV(); V t184 = incV(); V t265 = incV(); 
    V t257 = incV(); V t249 = incV(); V t185 = incV(); V t266 = incV(); 
    V t258 = incV(); V t267 = incV(); V t259 = incV(); V t195 = incV(); 
    V t268 = incV(); V t196 = incV(); V t269 = incV(); V t197 = incV(); 
    V t189 = incV(); V t198 = incV(); V t0 = incV(); V t1 = incV(); 
    V t4 = incV(); V t8 = incV(); V t9 = incV(); V t10 = incV(); 
    V t20 = incV(); V t21 = incV(); V t13 = incV(); V t30 = incV(); 
    V t22 = incV(); V t14 = incV(); V t31 = incV(); V t23 = incV(); 
    V t15 = incV(); V t32 = incV(); V t24 = incV(); V t41 = incV(); 
    V t33 = incV(); V t25 = incV(); V t50 = incV(); V t42 = incV(); 
    V t34 = incV(); V t26 = incV(); V t18 = incV(); V t35 = incV(); 
    V t27 = incV(); V t19 = incV(); V t60 = incV(); V t36 = incV(); 
    V t28 = incV(); V t37 = incV(); V t29 = incV(); V t46 = incV(); 
    V t63 = incV(); V t55 = incV(); V t47 = incV(); V t64 = incV(); 
    V t56 = incV(); V t57 = incV(); V t90 = incV(); V t58 = incV(); 
    V t75 = incV(); V t67 = incV(); V t76 = incV(); V t93 = incV(); 
    V t85 = incV(); V t77 = incV(); V t94 = incV(); V t86 = incV(); 
    V t87 = incV(); V t88 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("supplier")));
    PROFILE(5, pfnColumnValue(t1, t0, LiteralSymbol("s_suppkey")));
    PROFILE(6, pfnColumnValue(t4, t0, LiteralSymbol("s_nationkey")));
    PROFILE(7, pfnLoadTable(t8, LiteralSymbol("nation")));
    PROFILE(8, pfnColumnValue(t9, t8, LiteralSymbol("n_nationkey")));
    PROFILE(9, pfnColumnValue(t10, t8, LiteralSymbol("n_name")));
    PROFILE(10, pfnLoadTable(t13, LiteralSymbol("nation")));
    PROFILE(11, pfnColumnValue(t14, t13, LiteralSymbol("n_nationkey")));
    PROFILE(12, pfnColumnValue(t15, t13, LiteralSymbol("n_name")));
    PROFILE(13, pfnEq(t18, t10, LiteralSymbol("GERMANY")));
    PROFILE(14, pfnEq(t19, t15, LiteralSymbol("FRANCE")));
    PROFILE(15, pfnWhere(t20, t18));
    PROFILE(16, pfnWhere(t21, t19));
    PROFILE(17, pfnLen(t22, t20));
    PROFILE(18, pfnLen(t23, t21));
    PROFILE(19, pfnVector(t24, t23, t20));
    PROFILE(20, pfnVector(t25, t22, t21));
    PROFILE(21, pfnEq(t26, t10, LiteralSymbol("FRANCE")));
    PROFILE(22, pfnEq(t27, t15, LiteralSymbol("GERMANY")));
    PROFILE(23, pfnWhere(t28, t26));
    PROFILE(24, pfnWhere(t29, t27));
    PROFILE(25, pfnLen(t30, t28));
    PROFILE(26, pfnLen(t31, t29));
    PROFILE(27, pfnVector(t32, t31, t28));
    PROFILE(28, pfnVector(t33, t30, t29));
    PROFILE(29, pfnAppend(t34, t24, t32));
    PROFILE(30, pfnAppend(t35, t25, t33));
    PROFILE(32, q7_patternindex_1((V []){t36, t37}, (V []){t9, t10}, t34));
    PROFILE(34, q7_patternindex_2((V []){t41, t42}, (V []){t14, t15}, t35));
    PROFILE(35, pfnLoadTable(t46, LiteralSymbol("customer")));
    PROFILE(36, pfnColumnValue(t47, t46, LiteralSymbol("c_custkey")));
    PROFILE(37, pfnColumnValue(t50, t46, LiteralSymbol("c_nationkey")));
    PROFILE(38, pfnFetch(t55, t50));
    PROFILE(39, pfnJoinIndex(t56, t36, t55, LiteralSymbol((S)"eq")));
    PROFILE(40, pfnIndex(t57, t56, LiteralI64(0)));
    PROFILE(41, pfnIndex(t58, t56, LiteralI64(1)));
    PROFILE(44, q7_patternindex_3((V []){t60, t63, t64}, (V []){t37, t41, t42}, t57));
    PROFILE(45, pfnIndex(t67, t47, t58));
    PROFILE(46, pfnLoadTable(t75, LiteralSymbol("orders")));
    PROFILE(47, pfnColumnValue(t76, t75, LiteralSymbol("o_orderkey")));
    PROFILE(48, pfnColumnValue(t77, t75, LiteralSymbol("o_custkey")));
    PROFILE(49, pfnFetch(t85, t77));
    PROFILE(50, pfnJoinIndex(t86, t67, t85, LiteralSymbol((S)"eq")));
    PROFILE(51, pfnIndex(t87, t86, LiteralI64(0)));
    PROFILE(52, pfnIndex(t88, t86, LiteralI64(1)));
    PROFILE(55, q7_patternindex_4((V []){t90, t93, t94}, (V []){t60, t63, t64}, t87));
    PROFILE(56, pfnIndex(t105, t76, t88));
    PROFILE(57, pfnLoadTable(t114, LiteralSymbol("lineitem")));
    PROFILE(58, pfnColumnValue(t115, t114, LiteralSymbol("l_orderkey")));
    PROFILE(59, pfnColumnValue(t117, t114, LiteralSymbol("l_suppkey")));
    PROFILE(60, pfnColumnValue(t120, t114, LiteralSymbol("l_extendedprice")));
    PROFILE(61, pfnColumnValue(t121, t114, LiteralSymbol("l_discount")));
    PROFILE(62, pfnColumnValue(t125, t114, LiteralSymbol("l_shipdate")));
    PROFILE(65, q7_autofusion_13(t133, (V[]){t125}));
    PROFILE(66, pfnFetch(t134, t115));
    PROFILE(72, q7_patterncompress_14((V []){t150, t136, t139, t140, t144}, t133, (V []){t134, t117, t120, t121, t125}));
    PROFILE(74, pfnJoinIndex(t151, t105, t150, LiteralSymbol((S)"eq")));
    PROFILE(75, pfnIndex(t152, t151, LiteralI64(0)));
    PROFILE(76, pfnIndex(t153, t151, LiteralI64(1)));
    PROFILE(79, q7_patternindex_5((V []){t155, t158, t159}, (V []){t90, t93, t94}, t152));
    PROFILE(83, q7_patternindex_6((V []){t181, t184, t185, t189}, (V []){t136, t139, t140, t144}, t153));
    PROFILE(84, pfnFetch(t195, t4));
    PROFILE(85, pfnList(t196, 2, (V []){t195, t1}));
    PROFILE(86, pfnList(t197, 2, (V []){t158, t181}));
    PROFILE(87, pfnJoinIndex(t198, t196, t197, LiteralSymbol((S)"eq")));
    PROFILE(88, pfnIndex(t200, t198, LiteralI64(1)));
    PROFILE(93, q7_patternindex_7((V []){t209, t213, t238, t239, t243}, (V []){t155, t159, t184, t185, t189}, t200));
    PROFILE(94, pfnDateYear(t249, t243));
    PROFILE(96, q7_autofusion_12(t251, (V[]){t238,t239}));
    PROFILE(97, pfnList(t252, 3, (V []){t213, t209, t249}));
    PROFILE(98, pfnGroup(t253, t252));
    PROFILE(99, pfnKeys(t254, t253));
    PROFILE(100, pfnValues(t255, t253));
    PROFILE(103, q7_patternindex_8((V []){t256, t257, t258}, (V []){t213, t209, t249}, t254));
    PROFILE(106, q7_peephole_fp1_0(t261,t251,t255));
    PROFILE(107, pfnList(t262, 3, (V []){t256, t257, t258}));
    PROFILE(108, pfnOrderBy(t263, t262, LiteralVectorBool(3, (B []){1, 1, 1})));
    PROFILE(112, q7_patternindex_9((V []){t264, t265, t266, t267}, (V []){t256, t257, t258, t261}, t263));
    PROFILE(113, copyV(t268,LiteralVectorSymbol(4, (S []){"supp_nation", "cust_nation", "l_year", "revenue"})));
    PROFILE(114, pfnList(t269, 4, (V []){t264, t265, t266, t267}));
    PROFILE(115, pfnTable(t270, t268, t269));
    h_rtn[0] = t270;
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

// Compiling time (ms): 3.119
