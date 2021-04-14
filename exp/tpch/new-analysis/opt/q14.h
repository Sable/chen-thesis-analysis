// Parsing time (ms): 0.432
 // - #: 2
 // - #: 3
 // - #: 8
 // - #: 3
// Total # of fused stmts: 16
static I horse_main(V *h_rtn);
static I q14_autofusion_7(V z, V *x);
static I q14_patterncompress_8(V *z, V x, V *y);
static I q14_patternindex_0(V *z, V *x, V y);
static I q14_autofusion_3(V z, V *x);
static I q14_autofusion_6(V z, V *x);
static I q14_autofusion_5(V z, V *x);

static I q14_autofusion_7(V z, V *x){
    V x0=x[0]; // t12
    L r0=vn(x0);
    /* Fusion: kind E */
    initV(z, H_B, r0);
    DOP(r0, vB(z,i)=AND(GEQ(vD(x0,i),19950901),LT(vD(x0,i),19951001))) R 0;
}
static I q14_patterncompress_8(V *z, V x, V *y){
    V z0 = z[0]; // t22
    V z1 = z[1]; // t26
    V z2 = z[2]; // t27
    V y0 = y[0]; // t3
    V y1 = y[1]; // t7
    V y2 = y[2]; // t8
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

static I q14_patternindex_0(V *z, V *x, V y){
    V z0 = z[0]; // t58
    V z1 = z[1]; // t59
    V x0 = x[0]; // t26
    V x1 = x[1]; // t27
    initV(z0, H_E, vn(y));
    initV(z1, H_E, vn(y));
    DOP(vn(z0), {
        vE(z0,i) = vE(x0, vL(y,i));
        vE(z1,i) = vE(x1, vL(y,i));
    })
    R 0;
}

static I q14_autofusion_3(V z, V *x){
    V x0=x[0]; // t73
    V x1=x[1]; // t58
    V x2=x[2]; // t59
    Q id0=getSymbol("PROMO%");
    initV(z, H_E, 1);
    E r[H_CORE]; DOI(H_CORE, r[i]=0)
    DOT(vn(x0), {
        B t = LIKE2Q(vQ(x0,i),id0);
        r[tid]+=PLUS(MUL(t,MUL(vE(x1,i),MINUS(1,vE(x2,i)))),MUL(NOT(t),0));})
    E r0=0; DOI(H_CORE, r0+=r[i]) ve(z)=r0;
    R 0;
}

static I q14_autofusion_6(V z, V *x){
    V x0=x[0]; // t58
    V x1=x[1]; // t59
    L r0=vn(x0);
    E c = 0; L tot=0;
    initV(z, H_E, 1);
    DOP(r0, c+=MUL(vE(x0,i),MINUS(1,vE(x1,i))), reduction(+:c))
    vE(z,0) = c;
    R 0;
}
static I q14_autofusion_5(V z, V *x){
    V x0=x[0]; // t87
    V x1=x[1]; // t88
    L r0=vn(x0);
    /* Fusion: kind E */
    initV(z, H_E, r0);
    DOP(r0, vE(z,i)=DIV(MUL(100,ve(x0)),ve(x1))) R 0;
}

static I horse_main(V *h_rtn){
    V t0 = incV(); V t3 = incV(); V t7 = incV(); V t8 = incV(); 
    V t20 = incV(); V t12 = incV(); V t22 = incV(); V t50 = incV(); 
    V t42 = incV(); V t26 = incV(); V t18 = incV(); V t51 = incV(); 
    V t27 = incV(); V t19 = incV(); V t52 = incV(); V t37 = incV(); 
    V t38 = incV(); V t47 = incV(); V t80 = incV(); V t48 = incV(); 
    V t81 = incV(); V t73 = incV(); V t49 = incV(); V t90 = incV(); 
    V t82 = incV(); V t58 = incV(); V t91 = incV(); V t83 = incV(); 
    V t59 = incV(); V t92 = incV(); V t84 = incV(); V t93 = incV(); 
    V t85 = incV(); V t86 = incV(); V t78 = incV(); V t87 = incV(); 
    V t79 = incV(); V t88 = incV(); V t89 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("lineitem")));
    PROFILE(5, pfnColumnValue(t3, t0, LiteralSymbol("l_partkey")));
    PROFILE(6, pfnColumnValue(t7, t0, LiteralSymbol("l_extendedprice")));
    PROFILE(7, pfnColumnValue(t8, t0, LiteralSymbol("l_discount")));
    PROFILE(8, pfnColumnValue(t12, t0, LiteralSymbol("l_shipdate")));
    PROFILE(11, q14_autofusion_7(t20, (V[]){t12}));
    PROFILE(14, q14_patterncompress_8((V []){t22, t26, t27}, t20, (V []){t3, t7, t8}));
    PROFILE(15, pfnLoadTable(t37, LiteralSymbol("part")));
    PROFILE(16, pfnColumnValue(t38, t37, LiteralSymbol("p_partkey")));
    PROFILE(17, pfnColumnValue(t42, t37, LiteralSymbol("p_type")));
    PROFILE(18, pfnEnum(t47, t38, t22));
    PROFILE(19, pfnValues(t48, t47));
    PROFILE(20, pfnKeys(t49, t47));
    PROFILE(21, pfnLen(t50, t49));
    PROFILE(22, pfnLt(t51, t48, t50));
    PROFILE(23, pfnWhere(t52, t51));
    PROFILE(25, q14_patternindex_0((V []){t58, t59}, (V []){t26, t27}, t52));
    PROFILE(26, pfnIndex(t73, t42, t48));
    PROFILE(36, q14_autofusion_3(t87, (V[]){t73,t58,t59}));
    PROFILE(37, q14_autofusion_6(t88, (V[]){t58,t59}));
    PROFILE(39, q14_autofusion_5(t90, (V[]){t87,t88}));
    PROFILE(40, copyV(t91,LiteralSymbol("promo_revenue")));
    PROFILE(41, pfnList(t92, 1, (V []){t90}));
    PROFILE(42, pfnTable(t93, t91, t92));
    h_rtn[0] = t93;
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

// Compiling time (ms): 1.487
