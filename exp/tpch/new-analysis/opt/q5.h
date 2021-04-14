// Parsing time (ms): 0.779
 // - #: 2
 // - #: 3
// Total # of fused stmts: 5
static I horse_main(V *h_rtn);
static I q5_patternindex_1(V *z, V *x, V y);
static I q5_patternindex_2(V *z, V *x, V y);
static I q5_patternindex_3(V *z, V *x, V y);
static I q5_autofusion_12(V z, V *x);
static I q5_patterncompress_13(V *z, V x, V *y);
static I q5_patternindex_4(V *z, V *x, V y);
static I q5_patternindex_5(V *z, V *x, V y);
static I q5_patternindex_6(V *z, V *x, V y);
static I q5_patternindex_7(V *z, V *x, V y);
static I q5_autofusion_11(V z, V *x);
static I q5_peephole_fp1_0(V z, V x, V y);
static I q5_patternindex_8(V *z, V *x, V y);

static I q5_patternindex_1(V *z, V *x, V y){
    V z0 = z[0]; // t28
    V z1 = z[1]; // t29
    V x0 = x[0]; // t17
    V x1 = x[1]; // t18
    initV(z0, H_I, vn(y));
    initV(z1, H_Q, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vQ(z1,i) = vQ(x1, vL(y,i));
    })
    R 0;
}

static I q5_patternindex_2(V *z, V *x, V y){
    V z0 = z[0]; // t49
    V z1 = z[1]; // t50
    V x0 = x[0]; // t28
    V x1 = x[1]; // t29
    initV(z0, H_I, vn(y));
    initV(z1, H_Q, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vQ(z1,i) = vQ(x1, vL(y,i));
    })
    R 0;
}

static I q5_patternindex_3(V *z, V *x, V y){
    V z0 = z[0]; // t53
    V z1 = z[1]; // t56
    V x0 = x[0]; // t34
    V x1 = x[1]; // t42
    initV(z0, H_I, vn(y));
    initV(z1, H_I, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vI(z1,i) = vI(x1, vL(y,i));
    })
    R 0;
}

static I q5_autofusion_12(V z, V *x){
    V x0=x[0]; // t66
    L r0=vn(x0);
    /* Fusion: kind E */
    initV(z, H_B, r0);
    DOP(r0, vB(z,i)=AND(GEQ(vD(x0,i),19940101),LT(vD(x0,i),19950101))) R 0;
}
static I q5_patterncompress_13(V *z, V x, V *y){
    V z0 = z[0]; // t74
    V z1 = z[1]; // t83
    V y0 = y[0]; // t62
    V y1 = y[1]; // t75
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

static I q5_patternindex_4(V *z, V *x, V y){
    V z0 = z[0]; // t90
    V z1 = z[1]; // t91
    V z2 = z[2]; // t97
    V x0 = x[0]; // t49
    V x1 = x[1]; // t50
    V x2 = x[2]; // t56
    initV(z0, H_I, vn(y));
    initV(z1, H_Q, vn(y));
    initV(z2, H_I, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vQ(z1,i) = vQ(x1, vL(y,i));
        vI(z2,i) = vI(x2, vL(y,i));
    })
    R 0;
}

static I q5_patternindex_5(V *z, V *x, V y){
    V z0 = z[0]; // t135
    V z1 = z[1]; // t136
    V z2 = z[2]; // t142
    V x0 = x[0]; // t90
    V x1 = x[1]; // t91
    V x2 = x[2]; // t97
    initV(z0, H_I, vn(y));
    initV(z1, H_Q, vn(y));
    initV(z2, H_I, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vQ(z1,i) = vQ(x1, vL(y,i));
        vI(z2,i) = vI(x2, vL(y,i));
    })
    R 0;
}

static I q5_patternindex_6(V *z, V *x, V y){
    V z0 = z[0]; // t158
    V z1 = z[1]; // t161
    V z2 = z[2]; // t162
    V x0 = x[0]; // t114
    V x1 = x[1]; // t117
    V x2 = x[2]; // t118
    initV(z0, H_I, vn(y));
    initV(z1, H_E, vn(y));
    initV(z2, H_E, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vE(z1,i) = vE(x1, vL(y,i));
        vE(z2,i) = vE(x2, vL(y,i));
    })
    R 0;
}

static I q5_patternindex_7(V *z, V *x, V y){
    V z0 = z[0]; // t189
    V z1 = z[1]; // t214
    V z2 = z[2]; // t215
    V x0 = x[0]; // t136
    V x1 = x[1]; // t161
    V x2 = x[2]; // t162
    initV(z0, H_Q, vn(y));
    initV(z1, H_E, vn(y));
    initV(z2, H_E, vn(y));
    DOP(vn(z0), {
        vQ(z0,i) = vQ(x0, vL(y,i));
        vE(z1,i) = vE(x1, vL(y,i));
        vE(z2,i) = vE(x2, vL(y,i));
    })
    R 0;
}

static I q5_autofusion_11(V z, V *x){
    V x0=x[0]; // t214
    V x1=x[1]; // t215
    L r0=vn(x0);
    /* Fusion: kind E */
    initV(z, H_E, r0);
    DOP(r0, vE(z,i)=MUL(vE(x0,i),MINUS(1,vE(x1,i)))) R 0;
}
static I q5_peephole_fp1_0(V z, V x, V y){
    // z -> t234
    initV(z, H_E, vn(y));
    DOP(vn(y), {E a=0; V t=vV(y,i); DOJ(vn(t), a+=vE(x,vL(t,j))) vE(z,i)=a;}) R 0;
}

static I q5_patternindex_8(V *z, V *x, V y){
    V z0 = z[0]; // t237
    V z1 = z[1]; // t238
    V x0 = x[0]; // t231
    V x1 = x[1]; // t234
    initV(z0, H_Q, vn(y));
    initV(z1, H_E, vn(y));
    DOP(vn(z0), {
        vQ(z0,i) = vQ(x0, vL(y,i));
        vE(z1,i) = vE(x1, vL(y,i));
    })
    R 0;
}


static I horse_main(V *h_rtn){
    V t102 = incV(); V t111 = incV(); V t112 = incV(); V t130 = incV(); 
    V t114 = incV(); V t131 = incV(); V t117 = incV(); V t230 = incV(); 
    V t214 = incV(); V t142 = incV(); V t118 = incV(); V t231 = incV(); 
    V t215 = incV(); V t135 = incV(); V t240 = incV(); V t232 = incV(); 
    V t136 = incV(); V t128 = incV(); V t241 = incV(); V t233 = incV(); 
    V t225 = incV(); V t161 = incV(); V t129 = incV(); V t234 = incV(); 
    V t226 = incV(); V t162 = incV(); V t235 = incV(); V t227 = incV(); 
    V t236 = incV(); V t228 = incV(); V t172 = incV(); V t237 = incV(); 
    V t229 = incV(); V t173 = incV(); V t238 = incV(); V t174 = incV(); 
    V t158 = incV(); V t239 = incV(); V t175 = incV(); V t177 = incV(); 
    V t189 = incV(); V t0 = incV(); V t1 = incV(); V t4 = incV(); 
    V t8 = incV(); V t10 = incV(); V t12 = incV(); V t21 = incV(); 
    V t22 = incV(); V t24 = incV(); V t16 = incV(); V t33 = incV(); 
    V t17 = incV(); V t50 = incV(); V t42 = incV(); V t34 = incV(); 
    V t18 = incV(); V t43 = incV(); V t19 = incV(); V t44 = incV(); 
    V t28 = incV(); V t61 = incV(); V t53 = incV(); V t45 = incV(); 
    V t37 = incV(); V t29 = incV(); V t62 = incV(); V t71 = incV(); 
    V t63 = incV(); V t72 = incV(); V t56 = incV(); V t73 = incV(); 
    V t49 = incV(); V t90 = incV(); V t74 = incV(); V t66 = incV(); 
    V t91 = incV(); V t83 = incV(); V t75 = incV(); V t84 = incV(); 
    V t85 = incV(); V t86 = incV(); V t97 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("supplier")));
    PROFILE(5, pfnColumnValue(t1, t0, LiteralSymbol("s_suppkey")));
    PROFILE(6, pfnColumnValue(t4, t0, LiteralSymbol("s_nationkey")));
    PROFILE(7, pfnLoadTable(t8, LiteralSymbol("region")));
    PROFILE(8, pfnColumnValue(t10, t8, LiteralSymbol("r_name")));
    PROFILE(9, pfnEq(t12, t10, LiteralSymbol("ASIA")));
    PROFILE(10, pfnLoadTable(t16, LiteralSymbol("nation")));
    PROFILE(11, pfnColumnValue(t17, t16, LiteralSymbol("n_nationkey")));
    PROFILE(12, pfnColumnValue(t18, t16, LiteralSymbol("n_name")));
    PROFILE(13, pfnColumnValue(t19, t16, LiteralSymbol("n_regionkey")));
    PROFILE(14, pfnValues(t21, t19));
    PROFILE(15, pfnIndex(t22, t12, t21));
    PROFILE(16, pfnWhere(t24, t22));
    PROFILE(18, q5_patternindex_1((V []){t28, t29}, (V []){t17, t18}, t24));
    PROFILE(19, pfnLoadTable(t33, LiteralSymbol("customer")));
    PROFILE(20, pfnColumnValue(t34, t33, LiteralSymbol("c_custkey")));
    PROFILE(21, pfnColumnValue(t37, t33, LiteralSymbol("c_nationkey")));
    PROFILE(22, pfnFetch(t42, t37));
    PROFILE(23, pfnJoinIndex(t43, t28, t42, LiteralSymbol((S)"eq")));
    PROFILE(24, pfnIndex(t44, t43, LiteralI64(0)));
    PROFILE(25, pfnIndex(t45, t43, LiteralI64(1)));
    PROFILE(27, q5_patternindex_2((V []){t49, t50}, (V []){t28, t29}, t44));
    PROFILE(29, q5_patternindex_3((V []){t53, t56}, (V []){t34, t42}, t45));
    PROFILE(30, pfnLoadTable(t61, LiteralSymbol("orders")));
    PROFILE(31, pfnColumnValue(t62, t61, LiteralSymbol("o_orderkey")));
    PROFILE(32, pfnColumnValue(t63, t61, LiteralSymbol("o_custkey")));
    PROFILE(33, pfnColumnValue(t66, t61, LiteralSymbol("o_orderdate")));
    PROFILE(36, q5_autofusion_12(t73, (V[]){t66}));
    PROFILE(38, pfnFetch(t75, t63));
    PROFILE(39, q5_patterncompress_13((V []){t74, t83}, t73, (V []){t62, t75}));
    PROFILE(42, pfnJoinIndex(t84, t53, t83, LiteralSymbol((S)"eq")));
    PROFILE(43, pfnIndex(t85, t84, LiteralI64(0)));
    PROFILE(44, pfnIndex(t86, t84, LiteralI64(1)));
    PROFILE(47, q5_patternindex_4((V []){t90, t91, t97}, (V []){t49, t50, t56}, t85));
    PROFILE(48, pfnIndex(t102, t74, t86));
    PROFILE(49, pfnLoadTable(t111, LiteralSymbol("lineitem")));
    PROFILE(50, pfnColumnValue(t112, t111, LiteralSymbol("l_orderkey")));
    PROFILE(51, pfnColumnValue(t114, t111, LiteralSymbol("l_suppkey")));
    PROFILE(52, pfnColumnValue(t117, t111, LiteralSymbol("l_extendedprice")));
    PROFILE(53, pfnColumnValue(t118, t111, LiteralSymbol("l_discount")));
    PROFILE(54, pfnFetch(t128, t112));
    PROFILE(55, pfnJoinIndex(t129, t102, t128, LiteralSymbol((S)"eq")));
    PROFILE(56, pfnIndex(t130, t129, LiteralI64(0)));
    PROFILE(57, pfnIndex(t131, t129, LiteralI64(1)));
    PROFILE(60, q5_patternindex_5((V []){t135, t136, t142}, (V []){t90, t91, t97}, t130));
    PROFILE(63, q5_patternindex_6((V []){t158, t161, t162}, (V []){t114, t117, t118}, t131));
    PROFILE(64, pfnFetch(t172, t4));
    PROFILE(65, pfnList(t173, 3, (V []){t1, t172, t172}));
    PROFILE(66, pfnList(t174, 3, (V []){t158, t142, t135}));
    PROFILE(67, pfnJoinIndex(t175, t173, t174, LiteralSymbol((S)"eq")));
    PROFILE(68, pfnIndex(t177, t175, LiteralI64(1)));
    PROFILE(71, q5_patternindex_7((V []){t189, t214, t215}, (V []){t136, t161, t162}, t177));
    PROFILE(73, q5_autofusion_11(t226, (V[]){t214,t215}));
    PROFILE(74, pfnList(t227, 1, (V []){t189}));
    PROFILE(75, pfnGroup(t228, t227));
    PROFILE(76, pfnKeys(t229, t228));
    PROFILE(77, pfnValues(t230, t228));
    PROFILE(78, pfnIndex(t231, t189, t229));
    PROFILE(81, q5_peephole_fp1_0(t234,t226,t230));
    PROFILE(82, pfnList(t235, 1, (V []){t234}));
    PROFILE(83, pfnOrderBy(t236, t235, LiteralBool(0)));
    PROFILE(85, q5_patternindex_8((V []){t237, t238}, (V []){t231, t234}, t236));
    PROFILE(86, copyV(t239,LiteralVectorSymbol(2, (S []){"n_name", "revenue"})));
    PROFILE(87, pfnList(t240, 2, (V []){t237, t238}));
    PROFILE(88, pfnTable(t241, t239, t240));
    h_rtn[0] = t241;
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

// Compiling time (ms): 1.95
