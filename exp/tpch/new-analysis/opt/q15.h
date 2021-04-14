// Parsing time (ms): 0.572
 // - #: 2
 // - #: 3
// Total # of fused stmts: 5
static I horse_main(V *h_rtn);
static I q15_autofusion_7(V z, V *x);
static I q15_patterncompress_8(V *z, V x, V *y);
static I q15_autofusion_6(V z, V *x);
static I q15_peephole_fp1_0(V z, V x, V y);
static I q15_patternindex_1(V *z, V *x, V y);
static I q15_patternindex_2(V *z, V *x, V y);
static I q15_patternindex_3(V *z, V *x, V y);

static I q15_autofusion_7(V z, V *x){
    V x0=x[0]; // t11
    L r0=vn(x0);
    /* Fusion: kind E */
    initV(z, H_B, r0);
    DOP(r0, vB(z,i)=AND(GEQ(vD(x0,i),19960101),LT(vD(x0,i),19960401))) R 0;
}
static I q15_patterncompress_8(V *z, V x, V *y){
    V z0 = z[0]; // t22
    V z1 = z[1]; // t25
    V z2 = z[2]; // t26
    V y0 = y[0]; // t3
    V y1 = y[1]; // t6
    V y2 = y[2]; // t7
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

static I q15_autofusion_6(V z, V *x){
    V x0=x[0]; // t25
    V x1=x[1]; // t26
    L r0=vn(x0);
    /* Fusion: kind E */
    initV(z, H_E, r0);
    DOP(r0, vE(z,i)=MUL(vE(x0,i),MINUS(1,vE(x1,i)))) R 0;
}
static I q15_peephole_fp1_0(V z, V x, V y){
    // z -> t45
    initV(z, H_E, vn(y));
    DOP(vn(y), {E a=0; V t=vV(y,i); DOJ(vn(t), a+=vE(x,vL(t,j))) vE(z,i)=a;}) R 0;
}

static I q15_patternindex_1(V *z, V *x, V y){
    V z0 = z[0]; // t54
    V z1 = z[1]; // t55
    V x0 = x[0]; // t45
    V x1 = x[1]; // t42
    initV(z0, H_E, vn(y));
    initV(z1, H_I, vn(y));
    DOP(vn(z0), {
        vE(z0,i) = vE(x0, vL(y,i));
        vI(z1,i) = vI(x1, vL(y,i));
    })
    R 0;
}

static I q15_patternindex_2(V *z, V *x, V y){
    V z0 = z[0]; // t73
    V z1 = z[1]; // t74
    V z2 = z[2]; // t75
    V z3 = z[3]; // t78
    V x0 = x[0]; // t57
    V x1 = x[1]; // t58
    V x2 = x[2]; // t59
    V x3 = x[3]; // t61
    initV(z0, H_I, vn(y));
    initV(z1, H_S, vn(y));
    initV(z2, H_S, vn(y));
    initV(z3, H_S, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vS(z1,i) = vS(x1, vL(y,i));
        vS(z2,i) = vS(x2, vL(y,i));
        vS(z3,i) = vS(x3, vL(y,i));
    })
    R 0;
}

static I q15_patternindex_3(V *z, V *x, V y){
    V z0 = z[0]; // t83
    V z1 = z[1]; // t84
    V z2 = z[2]; // t85
    V z3 = z[3]; // t86
    V z4 = z[4]; // t87
    V x0 = x[0]; // t73
    V x1 = x[1]; // t74
    V x2 = x[2]; // t75
    V x3 = x[3]; // t78
    V x4 = x[4]; // t71
    initV(z0, H_I, vn(y));
    initV(z1, H_S, vn(y));
    initV(z2, H_S, vn(y));
    initV(z3, H_S, vn(y));
    initV(z4, H_E, vn(y));
    DOP(vn(z0), {
        vI(z0,i) = vI(x0, vL(y,i));
        vS(z1,i) = vS(x1, vL(y,i));
        vS(z2,i) = vS(x2, vL(y,i));
        vS(z3,i) = vS(x3, vL(y,i));
        vE(z4,i) = vE(x4, vL(y,i));
    })
    R 0;
}


static I horse_main(V *h_rtn){
    V t0 = incV(); V t3 = incV(); V t6 = incV(); V t7 = incV(); 
    V t11 = incV(); V t22 = incV(); V t40 = incV(); V t41 = incV(); 
    V t25 = incV(); V t17 = incV(); V t42 = incV(); V t26 = incV(); 
    V t18 = incV(); V t43 = incV(); V t19 = incV(); V t44 = incV(); 
    V t36 = incV(); V t61 = incV(); V t45 = incV(); V t37 = incV(); 
    V t54 = incV(); V t46 = incV(); V t38 = incV(); V t71 = incV(); 
    V t55 = incV(); V t47 = incV(); V t39 = incV(); V t64 = incV(); 
    V t56 = incV(); V t81 = incV(); V t73 = incV(); V t65 = incV(); 
    V t57 = incV(); V t49 = incV(); V t90 = incV(); V t82 = incV(); 
    V t74 = incV(); V t66 = incV(); V t58 = incV(); V t83 = incV(); 
    V t75 = incV(); V t59 = incV(); V t84 = incV(); V t85 = incV(); 
    V t86 = incV(); V t78 = incV(); V t87 = incV(); V t88 = incV(); 
    V t89 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("lineitem")));
    PROFILE(5, pfnColumnValue(t3, t0, LiteralSymbol("l_suppkey")));
    PROFILE(6, pfnColumnValue(t6, t0, LiteralSymbol("l_extendedprice")));
    PROFILE(7, pfnColumnValue(t7, t0, LiteralSymbol("l_discount")));
    PROFILE(8, pfnColumnValue(t11, t0, LiteralSymbol("l_shipdate")));
    PROFILE(11, q15_autofusion_7(t19, (V[]){t11}));
    PROFILE(14, q15_patterncompress_8((V []){t22, t25, t26}, t19, (V []){t3, t6, t7}));
    PROFILE(16, q15_autofusion_6(t37, (V[]){t25,t26}));
    PROFILE(17, pfnList(t38, 1, (V []){t22}));
    PROFILE(18, pfnGroup(t39, t38));
    PROFILE(19, pfnKeys(t40, t39));
    PROFILE(20, pfnValues(t41, t39));
    PROFILE(21, pfnIndex(t42, t22, t40));
    PROFILE(24, q15_peephole_fp1_0(t45,t37,t41));
    PROFILE(25, pfnMax(t46, t45));
    PROFILE(26, pfnJoinIndex(t47, t46, t45, LiteralSymbol((S)"eq")));
    PROFILE(27, pfnIndex(t49, t47, LiteralI64(1)));
    PROFILE(29, q15_patternindex_1((V []){t54, t55}, (V []){t45, t42}, t49));
    PROFILE(30, pfnLoadTable(t56, LiteralSymbol("supplier")));
    PROFILE(31, pfnColumnValue(t57, t56, LiteralSymbol("s_suppkey")));
    PROFILE(32, pfnColumnValue(t58, t56, LiteralSymbol("s_name")));
    PROFILE(33, pfnColumnValue(t59, t56, LiteralSymbol("s_address")));
    PROFILE(34, pfnColumnValue(t61, t56, LiteralSymbol("s_phone")));
    PROFILE(35, pfnJoinIndex(t64, t57, t55, LiteralSymbol((S)"eq")));
    PROFILE(36, pfnIndex(t65, t64, LiteralI64(0)));
    PROFILE(37, pfnIndex(t66, t64, LiteralI64(1)));
    PROFILE(38, pfnIndex(t71, t54, t66));
    PROFILE(42, q15_patternindex_2((V []){t73, t74, t75, t78}, (V []){t57, t58, t59, t61}, t65));
    PROFILE(43, pfnList(t81, 1, (V []){t73}));
    PROFILE(44, pfnOrderBy(t82, t81, LiteralBool(1)));
    PROFILE(49, q15_patternindex_3((V []){t83, t84, t85, t86, t87}, (V []){t73, t74, t75, t78, t71}, t82));
    PROFILE(50, copyV(t88,LiteralVectorSymbol(5, (S []){"s_suppkey", "s_name", "s_address", "s_phone", "total_revenue"})));
    PROFILE(51, pfnList(t89, 5, (V []){t83, t84, t85, t86, t87}));
    PROFILE(52, pfnTable(t90, t88, t89));
    h_rtn[0] = t90;
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

// Compiling time (ms): 1.291
