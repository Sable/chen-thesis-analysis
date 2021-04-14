// Parsing time (ms): 0.812
 // - #: 4
 // - #: 2
// Total # of fused stmts: 6
static I horse_main(V *h_rtn);
static I q9_autofusion_2(V z, V *x);
static I q9_autofusion_3(V z, V *x);

static I q9_autofusion_2(V z, V *x){
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

static I q9_autofusion_3(V z, V *x){
    V x0=x[0]; // t201
    V x1=x[1]; // t202
    V x2=x[2]; // t194
    V x3=x[3]; // t200
    L r0=vn(x3);
    /* Fusion: kind E */
    initV(z, H_E, r0);
    DOP(r0, vE(z,i)=MINUS(MUL(vE(x0,i),MINUS(1,vE(x1,i))),MUL(vE(x2,i),vE(x3,i)))) R 0;
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
    PROFILE(23, q9_autofusion_2(t49, (V[]){t20,t46,t45}));
    PROFILE(24, pfnFetch(t58, t40));
    PROFILE(25, pfnIndex(t59, t58, t48));
    PROFILE(26, pfnFetch(t60, t41));
    PROFILE(27, pfnIndex(t61, t60, t48));
    PROFILE(28, pfnIndex(t63, t43, t48));
    PROFILE(29, pfnJoinIndex(t65, t6, t61, LiteralSymbol((S)"eq")));
    PROFILE(30, pfnIndex(t66, t65, LiteralI64(0)));
    PROFILE(31, pfnIndex(t67, t65, LiteralI64(1)));
    PROFILE(32, pfnIndex(t69, t15, t66));
    PROFILE(33, pfnIndex(t72, t6, t66));
    PROFILE(34, pfnIndex(t80, t49, t67));
    PROFILE(35, pfnIndex(t89, t59, t67));
    PROFILE(36, pfnIndex(t90, t61, t67));
    PROFILE(37, pfnIndex(t92, t63, t67));
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
    PROFILE(50, pfnIndex(t117, t69, t114));
    PROFILE(51, pfnIndex(t139, t92, t114));
    PROFILE(52, pfnFetch(t141, t95));
    PROFILE(53, pfnIndex(t142, t141, t115));
    PROFILE(54, pfnIndex(t146, t99, t115));
    PROFILE(55, pfnIndex(t147, t100, t115));
    PROFILE(56, pfnIndex(t148, t101, t115));
    PROFILE(57, pfnLoadTable(t158, LiteralSymbol("orders")));
    PROFILE(58, pfnColumnValue(t159, t158, LiteralSymbol("o_orderkey")));
    PROFILE(59, pfnColumnValue(t163, t158, LiteralSymbol("o_orderdate")));
    PROFILE(60, pfnJoinIndex(t168, t159, t142, LiteralSymbol((S)"eq")));
    PROFILE(61, pfnIndex(t169, t168, LiteralI64(0)));
    PROFILE(62, pfnIndex(t170, t168, LiteralI64(1)));
    PROFILE(63, pfnIndex(t172, t117, t170));
    PROFILE(64, pfnIndex(t194, t139, t170));
    PROFILE(65, pfnIndex(t200, t146, t170));
    PROFILE(66, pfnIndex(t201, t147, t170));
    PROFILE(67, pfnIndex(t202, t148, t170));
    PROFILE(68, pfnIndex(t217, t163, t169));
    PROFILE(69, pfnDateYear(t222, t217));
    PROFILE(73, q9_autofusion_3(t226, (V[]){t201,t202,t194,t200}));
    PROFILE(74, pfnList(t227, 2, (V []){t172, t222}));
    PROFILE(75, pfnGroup(t228, t227));
    PROFILE(76, pfnKeys(t229, t228));
    PROFILE(77, pfnValues(t230, t228));
    PROFILE(78, pfnIndex(t231, t172, t229));
    PROFILE(79, pfnIndex(t232, t222, t229));
    PROFILE(80, pfnEachRight(t233, t226, t230, pfnIndex));
    PROFILE(81, pfnEach(t234, t233, pfnSum));
    PROFILE(82, pfnRaze(t235, t234));
    PROFILE(83, pfnList(t236, 2, (V []){t231, t232}));
    PROFILE(84, pfnOrderBy(t237, t236, LiteralVectorBool(2, (B []){1, 0})));
    PROFILE(85, pfnIndex(t238, t231, t237));
    PROFILE(86, pfnIndex(t239, t232, t237));
    PROFILE(87, pfnIndex(t240, t235, t237));
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

// Compiling time (ms): 1.897
