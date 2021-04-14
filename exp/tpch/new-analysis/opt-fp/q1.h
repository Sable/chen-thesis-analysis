// Parsing time (ms): 0.711
static I horse_main(V *h_rtn);
static I q1_patterncompress_7(V *z, V x, V *y);
static I q1_peephole_fp1_0(V z, V x, V y);
static I q1_peephole_fp2_4(V z, V x, V y);
static I q1_peephole_fp1_1(V z, V x, V y);
static I q1_peephole_fp2_5(V z, V x, V y);
static I q1_peephole_fp1_2(V z, V x, V y);
static I q1_peephole_fp1_3(V z, V x, V y);
static I q1_peephole_fp2_6(V z, V x, V y);

static I q1_patterncompress_7(V *z, V x, V *y){
    V z0 = z[0]; // t23
    V z1 = z[1]; // t24
    V z2 = z[2]; // t25
    V z3 = z[3]; // t26
    V z4 = z[4]; // t27
    V z5 = z[5]; // t28
    V y0 = y[0]; // t6
    V y1 = y[1]; // t7
    V y2 = y[2]; // t8
    V y3 = y[3]; // t9
    V y4 = y[4]; // t10
    V y5 = y[5]; // t11
    L len = vn(x), k = 0;
    L lenZ = 0, parZ[H_CORE], offset[H_CORE];
    DOI(H_CORE, parZ[i]=offset[i]=0)
    CHECKE(getNumOfNonZero(x,parZ));
    DOI(H_CORE, lenZ += parZ[i])
    DOIa(H_CORE, offset[i]=parZ[i-1]+offset[i-1])
    initV(z0,H_E,lenZ);
    initV(z1,H_E,lenZ);
    initV(z2,H_E,lenZ);
    initV(z3,H_E,lenZ);
    initV(z4,H_C,lenZ);
    initV(z5,H_C,lenZ);
    DOT(len, if(vB(x,i)){L c=offset[tid]++;\
        vE(z0,c) = vE(y0,i);\
        vE(z1,c) = vE(y1,i);\
        vE(z2,c) = vE(y2,i);\
        vE(z3,c) = vE(y3,i);\
        vC(z4,c) = vC(y4,i);\
        vC(z5,c) = vC(y5,i);\
    })
    R 0;
}

static I q1_peephole_fp1_0(V z, V x, V y){
    // z -> t49
    initV(z, H_E, vn(y));
    DOP(vn(y), {E a=0; V t=vV(y,i); DOJ(vn(t), a+=vE(x,vL(t,j))) vE(z,i)=a;}) R 0;
}

static I q1_peephole_fp2_4(V z, V x, V y){
    // z -> t52
    initV(z, H_E, vn(y));
    DOP(vn(y), {E a=0; V t=vV(y,i); DOJ(vn(t), a+=vE(x,vL(t,j))) vE(z,i)=a/vn(t);}) R 0;
}

static I q1_peephole_fp1_1(V z, V x, V y){
    // z -> t55
    initV(z, H_E, vn(y));
    DOP(vn(y), {E a=0; V t=vV(y,i); DOJ(vn(t), a+=vE(x,vL(t,j))) vE(z,i)=a;}) R 0;
}

static I q1_peephole_fp2_5(V z, V x, V y){
    // z -> t58
    initV(z, H_E, vn(y));
    DOP(vn(y), {E a=0; V t=vV(y,i); DOJ(vn(t), a+=vE(x,vL(t,j))) vE(z,i)=a/vn(t);}) R 0;
}

static I q1_peephole_fp1_2(V z, V x, V y){
    // z -> t61
    initV(z, H_E, vn(y));
    DOP(vn(y), {E a=0; V t=vV(y,i); DOJ(vn(t), a+=vE(x,vL(t,j))) vE(z,i)=a;}) R 0;
}

static I q1_peephole_fp1_3(V z, V x, V y){
    // z -> t64
    initV(z, H_E, vn(y));
    DOP(vn(y), {E a=0; V t=vV(y,i); DOJ(vn(t), a+=vE(x,vL(t,j))) vE(z,i)=a;}) R 0;
}

static I q1_peephole_fp2_6(V z, V x, V y){
    // z -> t70
    initV(z, H_E, vn(y));
    DOP(vn(y), {E a=0; V t=vV(y,i); DOJ(vn(t), a+=vE(x,vL(t,j))) vE(z,i)=a/vn(t);}) R 0;
}


static I horse_main(V *h_rtn){
    V t0 = incV(); V t6 = incV(); V t7 = incV(); V t8 = incV(); 
    V t9 = incV(); V t10 = incV(); V t11 = incV(); V t12 = incV(); 
    V t23 = incV(); V t40 = incV(); V t24 = incV(); V t41 = incV(); 
    V t25 = incV(); V t50 = incV(); V t42 = incV(); V t26 = incV(); 
    V t18 = incV(); V t51 = incV(); V t43 = incV(); V t35 = incV(); 
    V t27 = incV(); V t60 = incV(); V t52 = incV(); V t44 = incV(); 
    V t36 = incV(); V t28 = incV(); V t61 = incV(); V t53 = incV(); 
    V t45 = incV(); V t37 = incV(); V t70 = incV(); V t62 = incV(); 
    V t54 = incV(); V t46 = incV(); V t38 = incV(); V t71 = incV(); 
    V t63 = incV(); V t55 = incV(); V t47 = incV(); V t39 = incV(); 
    V t80 = incV(); V t72 = incV(); V t64 = incV(); V t56 = incV(); 
    V t48 = incV(); V t81 = incV(); V t73 = incV(); V t57 = incV(); 
    V t49 = incV(); V t82 = incV(); V t74 = incV(); V t58 = incV(); 
    V t83 = incV(); V t75 = incV(); V t59 = incV(); V t84 = incV(); 
    V t76 = incV(); V t68 = incV(); V t85 = incV(); V t77 = incV(); 
    V t69 = incV(); V t86 = incV(); V t78 = incV(); V t87 = incV(); 
    V t79 = incV(); V t88 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("lineitem")));
    PROFILE(5, pfnColumnValue(t6, t0, LiteralSymbol("l_quantity")));
    PROFILE(6, pfnColumnValue(t7, t0, LiteralSymbol("l_extendedprice")));
    PROFILE(7, pfnColumnValue(t8, t0, LiteralSymbol("l_discount")));
    PROFILE(8, pfnColumnValue(t9, t0, LiteralSymbol("l_tax")));
    PROFILE(9, pfnColumnValue(t10, t0, LiteralSymbol("l_returnflag")));
    PROFILE(10, pfnColumnValue(t11, t0, LiteralSymbol("l_linestatus")));
    PROFILE(11, pfnColumnValue(t12, t0, LiteralSymbol("l_shipdate")));
    PROFILE(12, pfnLeq(t18, t12, LiteralDate(19980902)));
    PROFILE(18, q1_patterncompress_7((V []){t23, t24, t25, t26, t27, t28}, t18, (V []){t6, t7, t8, t9, t10, t11}));
    PROFILE(19, pfnMinus(t35, LiteralI32(1), t25));
    PROFILE(20, pfnMul(t36, t24, t35));
    PROFILE(21, pfnPlus(t37, LiteralI32(1), t26));
    PROFILE(22, pfnMinus(t38, LiteralI32(1), t25));
    PROFILE(23, pfnMul(t39, t24, t38));
    PROFILE(24, pfnMul(t40, t39, t37));
    PROFILE(25, pfnList(t41, 2, (V []){t27, t28}));
    PROFILE(26, pfnGroup(t42, t41));
    PROFILE(27, pfnKeys(t43, t42));
    PROFILE(28, pfnValues(t44, t42));
    PROFILE(29, pfnIndex(t45, t27, t43));
    PROFILE(30, pfnIndex(t46, t28, t43));
    PROFILE(33, q1_peephole_fp1_0(t49,t23,t44));
    PROFILE(36, q1_peephole_fp2_4(t52,t23,t44));
    PROFILE(39, q1_peephole_fp1_1(t55,t24,t44));
    PROFILE(42, q1_peephole_fp2_5(t58,t24,t44));
    PROFILE(45, q1_peephole_fp1_2(t61,t36,t44));
    PROFILE(48, q1_peephole_fp1_3(t64,t40,t44));
    PROFILE(51, q1_peephole_fp2_6(t70,t25,t44));
    PROFILE(52, pfnEachRight(t71, t27, t44, pfnIndex));
    PROFILE(53, pfnEach(t72, t71, pfnLen));
    PROFILE(54, pfnRaze(t73, t72));
    PROFILE(55, pfnList(t74, 2, (V []){t45, t46}));
    PROFILE(56, pfnOrderBy(t75, t74, LiteralVectorBool(2, (B []){1, 1})));
    PROFILE(57, pfnIndex(t76, t45, t75));
    PROFILE(58, pfnIndex(t77, t46, t75));
    PROFILE(59, pfnIndex(t78, t49, t75));
    PROFILE(60, pfnIndex(t79, t55, t75));
    PROFILE(61, pfnIndex(t80, t61, t75));
    PROFILE(62, pfnIndex(t81, t64, t75));
    PROFILE(63, pfnIndex(t82, t52, t75));
    PROFILE(64, pfnIndex(t83, t58, t75));
    PROFILE(65, pfnIndex(t84, t70, t75));
    PROFILE(66, pfnIndex(t85, t73, t75));
    PROFILE(67, copyV(t86,LiteralVectorSymbol(10, (S []){"l_returnflag", "l_linestatus", "sum_qty", "sum_base_price", "sum_disc_price", "sum_charge", "avg_qty", "avg_price", "avg_disc", "count_order"})));
    PROFILE(68, pfnList(t87, 10, (V []){t76, t77, t78, t79, t80, t81, t82, t83, t84, t85}));
    PROFILE(69, pfnTable(t88, t86, t87));
    h_rtn[0] = t88;
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

// Compiling time (ms): 1.155
