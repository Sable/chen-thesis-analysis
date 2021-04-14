// Parsing time (ms): 1.108
 // - #: 2
 // - #: 3
// Total # of fused stmts: 5
static I horse_main(V *h_rtn);
static I q2_patternindex_1(V *z, V *x, V y);
static I q2_patternindex_2(V *z, V *x, V y);
static I q2_autofusion_11(V z, V *x);
static I q2_patterncompress_12(V *z, V x, V *y);
static I q2_autofusion_9(V z, V *x);
static I q2_patternindex_3(V *z, V *x, V y);
static I q2_peephole_fp5_0(V z, V x, V y);
static I q2_patternindex_4(V *z, V *x, V y);
static I q2_patternindex_5(V *z, V *x, V y);
static I q2_patternindex_6(V *z, V *x, V y);
static I q2_patternindex_7(V *z, V *x, V y);
static I q2_patternindex_8(V *z, V *x, V y);

static I q2_patternindex_1(V *z, V *x, V y){
    V z0 = z[0]; // t20
    V z1 = z[1]; // t21
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

static I q2_patternindex_2(V *z, V *x, V y){
    V z0 = z[0]; // t44
    V z1 = z[1]; // t45
    V z2 = z[2]; // t46
    V z3 = z[3]; // t48
    V z4 = z[4]; // t49
    V z5 = z[5]; // t50
    V x0 = x[0]; // t26
    V x1 = x[1]; // t27
    V x2 = x[2]; // t28
    V x3 = x[3]; // t30
    V x4 = x[4]; // t31
    V x5 = x[5]; // t32
    initV(z0, H_I, vn(y));
    initV(z1, H_S, vn(y));
    initV(z2, H_S, vn(y));
    initV(z3, H_S, vn(y));
    initV(z4, H_E, vn(y));
    initV(z5, H_S, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vS(z1,i) = vS(x1, vL(y,i));
        vS(z2,i) = vS(x2, vL(y,i));
        vS(z3,i) = vS(x3, vL(y,i));
        vE(z4,i) = vE(x4, vL(y,i));
        vS(z5,i) = vS(x5, vL(y,i));
    })
    R 0;
}

static I q2_autofusion_11(V z, V *x){
    V x0=x[0]; // t57
    V x1=x[1]; // t56
    Q id0=getSymbol("%BRASS");
    L r0=vn(x1);
    /* Fusion: kind E */
    initV(z, H_B, r0);
    DOP(r0, vB(z,i)=AND(EQ(vI(x0,i),15),LIKE2Q(vQ(x1,i),id0))) R 0;
}
static I q2_patterncompress_12(V *z, V x, V *y){
    V z0 = z[0]; // t64
    V z1 = z[1]; // t66
    V y0 = y[0]; // t52
    V y1 = y[1]; // t54
    L len = vn(x), k = 0;
    L lenZ = 0, parZ[H_CORE], offset[H_CORE];
    DOI(H_CORE, parZ[i]=offset[i]=0)
    CHECKE(getNumOfNonZero(x,parZ));
    DOI(H_CORE, lenZ += parZ[i])
    DOIa(H_CORE, offset[i]=parZ[i-1]+offset[i-1])
    initV(z0,H_I,lenZ);
    initV(z1,H_S,lenZ);
    DOT(len, if(vB(x,i)){L c=offset[tid]++;\
        vI(z0,c) = vI(y0,i);\
        vS(z1,c) = vS(y1,i);\
    })
    R 0;
}

static I q2_autofusion_9(V z, V *x){
    V x0=x[0]; // t82
    V x1=x[1]; // t87
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

static I q2_patternindex_3(V *z, V *x, V y){
    V z0 = z[0]; // t155
    V z1 = z[1]; // t158
    V x0 = x[0]; // t154
    V x1 = x[1]; // t134
    initV(z0, H_I, vn(y));
    initV(z1, H_E, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vE(z1,i) = vE(x1, vL(y,i));
    })
    R 0;
}

static I q2_peephole_fp5_0(V z, V x, V y){
    // z -> t166
    initV(z, H_E, vn(y));
    DOP(vn(y), {E a=MAX_DBL; V t=vV(y,i); DOJ(vn(t), {E t0=vE(x,vL(t,j)); if(t0<a)a=t0;}) vE(z,i)=a;}) R 0;
}

static I q2_patternindex_4(V *z, V *x, V y){
    V z0 = z[0]; // t171
    V z1 = z[1]; // t173
    V x0 = x[0]; // t64
    V x1 = x[1]; // t66
    initV(z0, H_I, vn(y));
    initV(z1, H_S, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vS(z1,i) = vS(x1, vL(y,i));
    })
    R 0;
}

static I q2_patternindex_5(V *z, V *x, V y){
    V z0 = z[0]; // t195
    V z1 = z[1]; // t197
    V x0 = x[0]; // t171
    V x1 = x[1]; // t173
    initV(z0, H_I, vn(y));
    initV(z1, H_S, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vS(z1,i) = vS(x1, vL(y,i));
    })
    R 0;
}

static I q2_patternindex_6(V *z, V *x, V y){
    V z0 = z[0]; // t220
    V z1 = z[1]; // t224
    V z2 = z[2]; // t225
    V z3 = z[3]; // t227
    V z4 = z[4]; // t228
    V z5 = z[5]; // t229
    V x0 = x[0]; // t41
    V x1 = x[1]; // t45
    V x2 = x[2]; // t46
    V x3 = x[3]; // t48
    V x4 = x[4]; // t49
    V x5 = x[5]; // t50
    initV(z0, H_Q, vn(y));
    initV(z1, H_S, vn(y));
    initV(z2, H_S, vn(y));
    initV(z3, H_S, vn(y));
    initV(z4, H_E, vn(y));
    initV(z5, H_S, vn(y));
    DOP(vn(z0), {
        vQ(z0,i) = vQ(x0, vL(y,i));
        vS(z1,i) = vS(x1, vL(y,i));
        vS(z2,i) = vS(x2, vL(y,i));
        vS(z3,i) = vS(x3, vL(y,i));
        vE(z4,i) = vE(x4, vL(y,i));
        vS(z5,i) = vS(x5, vL(y,i));
    })
    R 0;
}

static I q2_patternindex_7(V *z, V *x, V y){
    V z0 = z[0]; // t230
    V z1 = z[1]; // t232
    V x0 = x[0]; // t195
    V x1 = x[1]; // t197
    initV(z0, H_I, vn(y));
    initV(z1, H_S, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vS(z1,i) = vS(x1, vL(y,i));
    })
    R 0;
}

static I q2_patternindex_8(V *z, V *x, V y){
    V z0 = z[0]; // t249
    V z1 = z[1]; // t250
    V z2 = z[2]; // t251
    V z3 = z[3]; // t252
    V z4 = z[4]; // t253
    V z5 = z[5]; // t254
    V z6 = z[6]; // t255
    V z7 = z[7]; // t256
    V x0 = x[0]; // t228
    V x1 = x[1]; // t224
    V x2 = x[2]; // t220
    V x3 = x[3]; // t230
    V x4 = x[4]; // t232
    V x5 = x[5]; // t225
    V x6 = x[6]; // t227
    V x7 = x[7]; // t229
    initV(z0, H_E, vn(y));
    initV(z1, H_S, vn(y));
    initV(z2, H_Q, vn(y));
    initV(z3, H_I, vn(y));
    initV(z4, H_S, vn(y));
    initV(z5, H_S, vn(y));
    initV(z6, H_S, vn(y));
    initV(z7, H_S, vn(y));
    DOP(vn(z0), {
        vE(z0,i) = vE(x0, vL(y,i));
        vS(z1,i) = vS(x1, vL(y,i));
        vQ(z2,i) = vQ(x2, vL(y,i));
        vI(z3,i) = vI(x3, vL(y,i));
        vS(z4,i) = vS(x4, vL(y,i));
        vS(z5,i) = vS(x5, vL(y,i));
        vS(z6,i) = vS(x6, vL(y,i));
        vS(z7,i) = vS(x7, vL(y,i));
    })
    R 0;
}


static I horse_main(V *h_rtn){
    V t98 = incV(); V t99 = incV(); V t102 = incV(); V t130 = incV(); 
    V t106 = incV(); V t131 = incV(); V t107 = incV(); V t220 = incV(); 
    V t132 = incV(); V t213 = incV(); V t117 = incV(); V t109 = incV(); 
    V t230 = incV(); V t214 = incV(); V t134 = incV(); V t215 = incV(); 
    V t232 = incV(); V t224 = incV(); V t208 = incV(); V t160 = incV(); 
    V t136 = incV(); V t225 = incV(); V t209 = incV(); V t161 = incV(); 
    V t137 = incV(); V t250 = incV(); V t170 = incV(); V t162 = incV(); 
    V t154 = incV(); V t251 = incV(); V t227 = incV(); V t171 = incV(); 
    V t163 = incV(); V t155 = incV(); V t139 = incV(); V t252 = incV(); 
    V t228 = incV(); V t180 = incV(); V t164 = incV(); V t253 = incV(); 
    V t229 = incV(); V t173 = incV(); V t165 = incV(); V t254 = incV(); 
    V t190 = incV(); V t166 = incV(); V t158 = incV(); V t255 = incV(); 
    V t247 = incV(); V t191 = incV(); V t183 = incV(); V t167 = incV(); 
    V t256 = incV(); V t248 = incV(); V t192 = incV(); V t184 = incV(); 
    V t168 = incV(); V t257 = incV(); V t249 = incV(); V t193 = incV(); 
    V t185 = incV(); V t169 = incV(); V t258 = incV(); V t194 = incV(); 
    V t259 = incV(); V t195 = incV(); V t187 = incV(); V t197 = incV(); 
    V t189 = incV(); V t0 = incV(); V t2 = incV(); V t4 = incV(); 
    V t8 = incV(); V t9 = incV(); V t10 = incV(); V t11 = incV(); 
    V t20 = incV(); V t21 = incV(); V t13 = incV(); V t30 = incV(); 
    V t14 = incV(); V t31 = incV(); V t32 = incV(); V t16 = incV(); 
    V t41 = incV(); V t33 = incV(); V t25 = incV(); V t50 = incV(); 
    V t34 = incV(); V t26 = incV(); V t51 = incV(); V t35 = incV(); 
    V t27 = incV(); V t52 = incV(); V t44 = incV(); V t36 = incV(); 
    V t28 = incV(); V t61 = incV(); V t45 = incV(); V t29 = incV(); 
    V t62 = incV(); V t54 = incV(); V t46 = incV(); V t63 = incV(); 
    V t64 = incV(); V t56 = incV(); V t48 = incV(); V t81 = incV(); 
    V t73 = incV(); V t57 = incV(); V t49 = incV(); V t82 = incV(); 
    V t66 = incV(); V t75 = incV(); V t84 = incV(); V t93 = incV(); 
    V t77 = incV(); V t86 = incV(); V t87 = incV(); V t89 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("region")));
    PROFILE(5, pfnColumnValue(t2, t0, LiteralSymbol("r_name")));
    PROFILE(6, pfnEq(t4, t2, LiteralSymbol("EUROPE")));
    PROFILE(7, pfnLoadTable(t8, LiteralSymbol("nation")));
    PROFILE(8, pfnColumnValue(t9, t8, LiteralSymbol("n_nationkey")));
    PROFILE(9, pfnColumnValue(t10, t8, LiteralSymbol("n_name")));
    PROFILE(10, pfnColumnValue(t11, t8, LiteralSymbol("n_regionkey")));
    PROFILE(11, pfnValues(t13, t11));
    PROFILE(12, pfnIndex(t14, t4, t13));
    PROFILE(13, pfnWhere(t16, t14));
    PROFILE(15, q2_patternindex_1((V []){t20, t21}, (V []){t9, t10}, t16));
    PROFILE(16, pfnLoadTable(t25, LiteralSymbol("supplier")));
    PROFILE(17, pfnColumnValue(t26, t25, LiteralSymbol("s_suppkey")));
    PROFILE(18, pfnColumnValue(t27, t25, LiteralSymbol("s_name")));
    PROFILE(19, pfnColumnValue(t28, t25, LiteralSymbol("s_address")));
    PROFILE(20, pfnColumnValue(t29, t25, LiteralSymbol("s_nationkey")));
    PROFILE(21, pfnColumnValue(t30, t25, LiteralSymbol("s_phone")));
    PROFILE(22, pfnColumnValue(t31, t25, LiteralSymbol("s_acctbal")));
    PROFILE(23, pfnColumnValue(t32, t25, LiteralSymbol("s_comment")));
    PROFILE(24, pfnFetch(t33, t29));
    PROFILE(25, pfnJoinIndex(t34, t20, t33, LiteralSymbol((S)"eq")));
    PROFILE(26, pfnIndex(t35, t34, LiteralI64(0)));
    PROFILE(27, pfnIndex(t36, t34, LiteralI64(1)));
    PROFILE(28, pfnIndex(t41, t21, t35));
    PROFILE(34, q2_patternindex_2((V []){t44, t45, t46, t48, t49, t50}, (V []){t26, t27, t28, t30, t31, t32}, t36));
    PROFILE(35, pfnLoadTable(t51, LiteralSymbol("part")));
    PROFILE(36, pfnColumnValue(t52, t51, LiteralSymbol("p_partkey")));
    PROFILE(37, pfnColumnValue(t54, t51, LiteralSymbol("p_mfgr")));
    PROFILE(38, pfnColumnValue(t56, t51, LiteralSymbol("p_type")));
    PROFILE(39, pfnColumnValue(t57, t51, LiteralSymbol("p_size")));
    PROFILE(42, q2_autofusion_11(t63, (V[]){t57,t56}));
    PROFILE(44, q2_patterncompress_12((V []){t64, t66}, t63, (V []){t52, t54}));
    PROFILE(45, pfnLoadTable(t73, LiteralSymbol("region")));
    PROFILE(46, pfnColumnValue(t75, t73, LiteralSymbol("r_name")));
    PROFILE(47, pfnEq(t77, t75, LiteralSymbol("EUROPE")));
    PROFILE(48, pfnLoadTable(t81, LiteralSymbol("nation")));
    PROFILE(49, pfnColumnValue(t82, t81, LiteralSymbol("n_nationkey")));
    PROFILE(50, pfnColumnValue(t84, t81, LiteralSymbol("n_regionkey")));
    PROFILE(51, pfnValues(t86, t84));
    PROFILE(52, pfnIndex(t87, t77, t86));
    PROFILE(54, q2_autofusion_9(t93, (V[]){t82,t87}));
    PROFILE(55, pfnLoadTable(t98, LiteralSymbol("supplier")));
    PROFILE(56, pfnColumnValue(t99, t98, LiteralSymbol("s_suppkey")));
    PROFILE(57, pfnColumnValue(t102, t98, LiteralSymbol("s_nationkey")));
    PROFILE(58, pfnFetch(t106, t102));
    PROFILE(59, pfnJoinIndex(t107, t93, t106, LiteralSymbol((S)"eq")));
    PROFILE(60, pfnIndex(t109, t107, LiteralI64(1)));
    PROFILE(61, pfnIndex(t117, t99, t109));
    PROFILE(62, pfnLoadTable(t130, LiteralSymbol("partsupp")));
    PROFILE(63, pfnColumnValue(t131, t130, LiteralSymbol("ps_partkey")));
    PROFILE(64, pfnColumnValue(t132, t130, LiteralSymbol("ps_suppkey")));
    PROFILE(65, pfnColumnValue(t134, t130, LiteralSymbol("ps_supplycost")));
    PROFILE(66, pfnFetch(t136, t132));
    PROFILE(67, pfnJoinIndex(t137, t117, t136, LiteralSymbol((S)"eq")));
    PROFILE(68, pfnIndex(t139, t137, LiteralI64(1)));
    PROFILE(69, pfnFetch(t154, t131));
    PROFILE(71, q2_patternindex_3((V []){t155, t158}, (V []){t154, t134}, t139));
    PROFILE(72, pfnList(t160, 1, (V []){t155}));
    PROFILE(73, pfnGroup(t161, t160));
    PROFILE(74, pfnKeys(t162, t161));
    PROFILE(75, pfnValues(t163, t161));
    PROFILE(78, q2_peephole_fp5_0(t166,t158,t163));
    PROFILE(79, pfnIndex(t167, t155, t162));
    PROFILE(80, pfnJoinIndex(t168, t64, t167, LiteralSymbol((S)"eq")));
    PROFILE(81, pfnIndex(t169, t168, LiteralI64(0)));
    PROFILE(82, pfnIndex(t170, t168, LiteralI64(1)));
    PROFILE(84, q2_patternindex_4((V []){t171, t173}, (V []){t64, t66}, t169));
    PROFILE(85, pfnIndex(t180, t166, t170));
    PROFILE(86, pfnLoadTable(t183, LiteralSymbol("partsupp")));
    PROFILE(87, pfnColumnValue(t184, t183, LiteralSymbol("ps_partkey")));
    PROFILE(88, pfnColumnValue(t185, t183, LiteralSymbol("ps_suppkey")));
    PROFILE(89, pfnColumnValue(t187, t183, LiteralSymbol("ps_supplycost")));
    PROFILE(90, pfnFetch(t189, t184));
    PROFILE(91, pfnList(t190, 2, (V []){t180, t171}));
    PROFILE(92, pfnList(t191, 2, (V []){t187, t189}));
    PROFILE(93, pfnJoinIndex(t192, t190, t191, LiteralSymbol((S)"eq")));
    PROFILE(94, pfnIndex(t193, t192, LiteralI64(0)));
    PROFILE(95, pfnIndex(t194, t192, LiteralI64(1)));
    PROFILE(97, q2_patternindex_5((V []){t195, t197}, (V []){t171, t173}, t193));
    PROFILE(98, pfnFetch(t208, t185));
    PROFILE(99, pfnIndex(t209, t208, t194));
    PROFILE(100, pfnJoinIndex(t213, t44, t209, LiteralSymbol((S)"eq")));
    PROFILE(101, pfnIndex(t214, t213, LiteralI64(0)));
    PROFILE(102, pfnIndex(t215, t213, LiteralI64(1)));
    PROFILE(108, q2_patternindex_6((V []){t220, t224, t225, t227, t228, t229}, (V []){t41, t45, t46, t48, t49, t50}, t214));
    PROFILE(110, q2_patternindex_7((V []){t230, t232}, (V []){t195, t197}, t215));
    PROFILE(111, pfnList(t247, 4, (V []){t228, t220, t224, t230}));
    PROFILE(112, pfnOrderBy(t248, t247, LiteralVectorBool(4, (B []){0, 1, 1, 1})));
    PROFILE(120, q2_patternindex_8((V []){t249, t250, t251, t252, t253, t254, t255, t256}, (V []){t228, t224, t220, t230, t232, t225, t227, t229}, t248));
    PROFILE(121, copyV(t257,LiteralVectorSymbol(8, (S []){"s_acctbal", "s_name", "n_name", "p_partkey", "p_mfgr", "s_address", "s_phone", "s_comment"})));
    PROFILE(122, pfnList(t258, 8, (V []){t249, t250, t251, t252, t253, t254, t255, t256}));
    PROFILE(123, pfnTable(t259, t257, t258));
    h_rtn[0] = t259;
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

// Compiling time (ms): 3.056
