// Parsing time (ms): 0.803
 // - #: 4
 // - #: 2
// Total # of fused stmts: 6
static I horse_main(V *h_rtn);
static I q9_autofusion_10(V z, V *x);
static I q9_patternindex_1(V *z, V *x, V y);
static I q9_patternindex_2(V *z, V *x, V y);
static I q9_patternindex_3(V *z, V *x, V y);
static I q9_patternindex_4(V *z, V *x, V y);
static I q9_patternindex_5(V *z, V *x, V y);
static I q9_patternindex_6(V *z, V *x, V y);
static I q9_autofusion_11(V z, V *x);
static I q9_patternindex_7(V *z, V *x, V y);
static I q9_peephole_fp1_0(V z, V x, V y);
static I q9_patternindex_8(V *z, V *x, V y);

static I q9_autofusion_10(V z, V *x){
    V x0=x[0]; // t20
    V x1=x[1]; // t46
    V x2=x[2]; // t45
    /* Fusion: special index for compress */
    L lenZ = 0, parZ[H_CORE], offset[H_CORE];
    DOI(H_CORE, parZ[i]=offset[i]=0)
    CHECKE(getNumOfNonZero(x1,parZ));
    DOI(H_CORE, lenZ += parZ[i])
    DOIa(H_CORE, offset[i]=parZ[i-1]+offset[i-1])
    initV(z, H_I, lenZ);
    DOT(vn(x1), if(vB(x1,i)){L c=offset[tid]++;\
        vI(z,c) = vI(x0,vL(x2,i));})
    R 0;
}

static I q9_patternindex_1(V *z, V *x, V y){
    V z0 = z[0]; // t59
    V z1 = z[1]; // t61
    V z2 = z[2]; // t63
    V x0 = x[0]; // t58
    V x1 = x[1]; // t60
    V x2 = x[2]; // t43
    initV(z0, H_I, vn(y));
    initV(z1, H_I, vn(y));
    initV(z2, H_E, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vI(z1,i) = vI(x1, vL(y,i));
        vE(z2,i) = vE(x2, vL(y,i));
    })
    R 0;
}

static I q9_patternindex_2(V *z, V *x, V y){
    V z0 = z[0]; // t69
    V z1 = z[1]; // t72
    V x0 = x[0]; // t15
    V x1 = x[1]; // t6
    initV(z0, H_Q, vn(y));
    initV(z1, H_I, vn(y));
    DOP(vn(z0), {
        vQ(z0,i) = vQ(x0, vL(y,i));
        vI(z1,i) = vI(x1, vL(y,i));
    })
    R 0;
}

static I q9_patternindex_3(V *z, V *x, V y){
    V z0 = z[0]; // t80
    V z1 = z[1]; // t89
    V z2 = z[2]; // t90
    V z3 = z[3]; // t92
    V x0 = x[0]; // t49
    V x1 = x[1]; // t59
    V x2 = x[2]; // t61
    V x3 = x[3]; // t63
    initV(z0, H_I, vn(y));
    initV(z1, H_I, vn(y));
    initV(z2, H_I, vn(y));
    initV(z3, H_E, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vI(z1,i) = vI(x1, vL(y,i));
        vI(z2,i) = vI(x2, vL(y,i));
        vE(z3,i) = vE(x3, vL(y,i));
    })
    R 0;
}

static I q9_patternindex_4(V *z, V *x, V y){
    V z0 = z[0]; // t117
    V z1 = z[1]; // t139
    V x0 = x[0]; // t69
    V x1 = x[1]; // t92
    initV(z0, H_Q, vn(y));
    initV(z1, H_E, vn(y));
    DOP(vn(z0), {
        vQ(z0,i) = vQ(x0, vL(y,i));
        vE(z1,i) = vE(x1, vL(y,i));
    })
    R 0;
}

static I q9_patternindex_5(V *z, V *x, V y){
    V z0 = z[0]; // t142
    V z1 = z[1]; // t146
    V z2 = z[2]; // t147
    V z3 = z[3]; // t148
    V x0 = x[0]; // t141
    V x1 = x[1]; // t99
    V x2 = x[2]; // t100
    V x3 = x[3]; // t101
    initV(z0, H_I, vn(y));
    initV(z1, H_E, vn(y));
    initV(z2, H_E, vn(y));
    initV(z3, H_E, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vE(z1,i) = vE(x1, vL(y,i));
        vE(z2,i) = vE(x2, vL(y,i));
        vE(z3,i) = vE(x3, vL(y,i));
    })
    R 0;
}

static I q9_patternindex_6(V *z, V *x, V y){
    V z0 = z[0]; // t172
    V z1 = z[1]; // t194
    V z2 = z[2]; // t200
    V z3 = z[3]; // t201
    V z4 = z[4]; // t202
    V x0 = x[0]; // t117
    V x1 = x[1]; // t139
    V x2 = x[2]; // t146
    V x3 = x[3]; // t147
    V x4 = x[4]; // t148
    initV(z0, H_Q, vn(y));
    initV(z1, H_E, vn(y));
    initV(z2, H_E, vn(y));
    initV(z3, H_E, vn(y));
    initV(z4, H_E, vn(y));
    DOP(vn(z0), {
        vQ(z0,i) = vQ(x0, vL(y,i));
        vE(z1,i) = vE(x1, vL(y,i));
        vE(z2,i) = vE(x2, vL(y,i));
        vE(z3,i) = vE(x3, vL(y,i));
        vE(z4,i) = vE(x4, vL(y,i));
    })
    R 0;
}

static I q9_autofusion_11(V z, V *x){
    V x0=x[0]; // t201
    V x1=x[1]; // t202
    V x2=x[2]; // t194
    V x3=x[3]; // t200
    L r0=vn(x3);
    /* Fusion: kind E */
    initV(z, H_E, r0);
    DOP(r0, vE(z,i)=MINUS(MUL(vE(x0,i),MINUS(1,vE(x1,i))),MUL(vE(x2,i),vE(x3,i)))) R 0;
}
static I q9_patternindex_7(V *z, V *x, V y){
    V z0 = z[0]; // t231
    V z1 = z[1]; // t232
    V x0 = x[0]; // t172
    V x1 = x[1]; // t222
    initV(z0, H_Q, vn(y));
    initV(z1, H_H, vn(y));
    DOP(vn(z0), {
        vQ(z0,i) = vQ(x0, vL(y,i));
        vH(z1,i) = vH(x1, vL(y,i));
    })
    R 0;
}

static I q9_peephole_fp1_0(V z, V x, V y){
    // z -> t235
    initV(z, H_E, vn(y));
    DOP(vn(y), {E a=0; V t=vV(y,i); DOJ(vn(t), a+=vE(x,vL(t,j))) vE(z,i)=a;}) R 0;
}

static I q9_patternindex_8(V *z, V *x, V y){
    V z0 = z[0]; // t238
    V z1 = z[1]; // t239
    V z2 = z[2]; // t240
    V x0 = x[0]; // t231
    V x1 = x[1]; // t232
    V x2 = x[2]; // t235
    initV(z0, H_Q, vn(y));
    initV(z1, H_H, vn(y));
    initV(z2, H_E, vn(y));
    DOP(vn(z0), {
        vQ(z0,i) = vQ(x0, vL(y,i));
        vH(z1,i) = vH(x1, vL(y,i));
        vE(z2,i) = vE(x2, vL(y,i));
    })
    R 0;
}


static I horse_main(V *h_rtn){
    V t100 = incV(); V t101 = incV(); V t99 = incV(); V t111 = incV(); 
    V t200 = incV(); V t112 = incV(); V t201 = incV(); V t113 = incV(); 
    V t202 = incV(); V t114 = incV(); V t115 = incV(); V t141 = incV(); 
    V t117 = incV(); V t230 = incV(); V t222 = incV(); V t142 = incV(); 
    V t231 = incV(); V t223 = incV(); V t240 = incV(); V t232 = incV(); 
    V t224 = incV(); V t241 = incV(); V t233 = incV(); V t225 = incV(); 
    V t217 = incV(); V t242 = incV(); V t234 = incV(); V t226 = incV(); 
    V t170 = incV(); V t146 = incV(); V t243 = incV(); V t235 = incV(); 
    V t227 = incV(); V t163 = incV(); V t147 = incV(); V t139 = incV(); 
    V t236 = incV(); V t228 = incV(); V t172 = incV(); V t148 = incV(); 
    V t237 = incV(); V t229 = incV(); V t238 = incV(); V t158 = incV(); 
    V t239 = incV(); V t159 = incV(); V t168 = incV(); V t169 = incV(); 
    V t194 = incV(); V t0 = incV(); V t2 = incV(); V t5 = incV(); 
    V t6 = incV(); V t9 = incV(); V t20 = incV(); V t21 = incV(); 
    V t13 = incV(); V t15 = incV(); V t40 = incV(); V t41 = incV(); 
    V t43 = incV(); V t19 = incV(); V t60 = incV(); V t61 = incV(); 
    V t45 = incV(); V t29 = incV(); V t46 = incV(); V t63 = incV(); 
    V t47 = incV(); V t39 = incV(); V t80 = incV(); V t72 = incV(); 
    V t48 = incV(); V t65 = incV(); V t49 = incV(); V t90 = incV(); 
    V t66 = incV(); V t58 = incV(); V t67 = incV(); V t59 = incV(); 
    V t92 = incV(); V t69 = incV(); V t94 = incV(); V t95 = incV(); 
    V t96 = incV(); V t97 = incV(); V t89 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("nation")));
    PROFILE(5, pfnColumnValue(t2, t0, LiteralSymbol("n_name")));
    PROFILE(6, pfnLoadTable(t5, LiteralSymbol("supplier")));
    PROFILE(7, pfnColumnValue(t6, t5, LiteralSymbol("s_suppkey")));
    PROFILE(8, pfnColumnValue(t9, t5, LiteralSymbol("s_nationkey")));
    PROFILE(9, pfnValues(t13, t9));
    PROFILE(10, pfnIndex(t15, t2, t13));
    PROFILE(11, pfnLoadTable(t19, LiteralSymbol("part")));
    PROFILE(12, pfnColumnValue(t20, t19, LiteralSymbol("p_partkey")));
    PROFILE(13, pfnColumnValue(t21, t19, LiteralSymbol("p_name")));
    PROFILE(14, pfnLike2(t29, t21, LiteralSymbol("%green%")));
    PROFILE(15, pfnLoadTable(t39, LiteralSymbol("partsupp")));
    PROFILE(16, pfnColumnValue(t40, t39, LiteralSymbol("ps_partkey")));
    PROFILE(17, pfnColumnValue(t41, t39, LiteralSymbol("ps_suppkey")));
    PROFILE(18, pfnColumnValue(t43, t39, LiteralSymbol("ps_supplycost")));
    PROFILE(19, pfnValues(t45, t40));
    PROFILE(20, pfnIndex(t46, t29, t45));
    PROFILE(22, pfnWhere(t48, t46));
    PROFILE(23, q9_autofusion_10(t49, (V[]){t20,t46,t45}));
    PROFILE(24, pfnFetch(t58, t40));
    PROFILE(26, pfnFetch(t60, t41));
    PROFILE(28, q9_patternindex_1((V []){t59, t61, t63}, (V []){t58, t60, t43}, t48));
    PROFILE(29, pfnJoinIndex(t65, t6, t61, LiteralSymbol((S)"eq")));
    PROFILE(30, pfnIndex(t66, t65, LiteralI64(0)));
    PROFILE(31, pfnIndex(t67, t65, LiteralI64(1)));
    PROFILE(33, q9_patternindex_2((V []){t69, t72}, (V []){t15, t6}, t66));
    PROFILE(37, q9_patternindex_3((V []){t80, t89, t90, t92}, (V []){t49, t59, t61, t63}, t67));
    PROFILE(38, pfnLoadTable(t94, LiteralSymbol("lineitem")));
    PROFILE(39, pfnColumnValue(t95, t94, LiteralSymbol("l_orderkey")));
    PROFILE(40, pfnColumnValue(t96, t94, LiteralSymbol("l_partkey")));
    PROFILE(41, pfnColumnValue(t97, t94, LiteralSymbol("l_suppkey")));
    PROFILE(42, pfnColumnValue(t99, t94, LiteralSymbol("l_quantity")));
    PROFILE(43, pfnColumnValue(t100, t94, LiteralSymbol("l_extendedprice")));
    PROFILE(44, pfnColumnValue(t101, t94, LiteralSymbol("l_discount")));
    PROFILE(45, pfnList(t111, 4, (V []){t90, t89, t80, t72}));
    PROFILE(46, pfnList(t112, 4, (V []){t97, t96, t96, t97}));
    PROFILE(47, pfnJoinIndex(t113, t111, t112, LiteralSymbol((S)"eq")));
    PROFILE(48, pfnIndex(t114, t113, LiteralI64(0)));
    PROFILE(49, pfnIndex(t115, t113, LiteralI64(1)));
    PROFILE(51, q9_patternindex_4((V []){t117, t139}, (V []){t69, t92}, t114));
    PROFILE(52, pfnFetch(t141, t95));
    PROFILE(56, q9_patternindex_5((V []){t142, t146, t147, t148}, (V []){t141, t99, t100, t101}, t115));
    PROFILE(57, pfnLoadTable(t158, LiteralSymbol("orders")));
    PROFILE(58, pfnColumnValue(t159, t158, LiteralSymbol("o_orderkey")));
    PROFILE(59, pfnColumnValue(t163, t158, LiteralSymbol("o_orderdate")));
    PROFILE(60, pfnJoinIndex(t168, t159, t142, LiteralSymbol((S)"eq")));
    PROFILE(61, pfnIndex(t169, t168, LiteralI64(0)));
    PROFILE(62, pfnIndex(t170, t168, LiteralI64(1)));
    PROFILE(67, q9_patternindex_6((V []){t172, t194, t200, t201, t202}, (V []){t117, t139, t146, t147, t148}, t170));
    PROFILE(68, pfnIndex(t217, t163, t169));
    PROFILE(69, pfnDateYear(t222, t217));
    PROFILE(73, q9_autofusion_11(t226, (V[]){t201,t202,t194,t200}));
    PROFILE(74, pfnList(t227, 2, (V []){t172, t222}));
    PROFILE(75, pfnGroup(t228, t227));
    PROFILE(76, pfnKeys(t229, t228));
    PROFILE(77, pfnValues(t230, t228));
    PROFILE(79, q9_patternindex_7((V []){t231, t232}, (V []){t172, t222}, t229));
    PROFILE(82, q9_peephole_fp1_0(t235,t226,t230));
    PROFILE(83, pfnList(t236, 2, (V []){t231, t232}));
    PROFILE(84, pfnOrderBy(t237, t236, LiteralVectorBool(2, (B []){1, 0})));
    PROFILE(87, q9_patternindex_8((V []){t238, t239, t240}, (V []){t231, t232, t235}, t237));
    PROFILE(88, copyV(t241,LiteralVectorSymbol(3, (S []){"nation", "o_year", "sum_profit"})));
    PROFILE(89, pfnList(t242, 3, (V []){t238, t239, t240}));
    PROFILE(90, pfnTable(t243, t241, t242));
    h_rtn[0] = t243;
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

// Compiling time (ms): 2.057
