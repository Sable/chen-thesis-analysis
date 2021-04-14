// Parsing time (ms): 0.513
 // - #: 6
 // - #: 3
 // - #: 5
// Total # of fused stmts: 14
static I horse_main(V *h_rtn);
static I q22_autofusion_6(V z, V *x);
static I q22_autofusion_5(V z, V *x);
static I q22_patterncompress_0(V *z, V x, V *y);
static I q22_autofusionlist_1(V *z, V *x);
static I q22_patternindex_7(V *z, V *x, V y);

static I q22_autofusion_6(V z, V *x){
    V x0=x[0]; // t7
    V x1=x[1]; // t11
    V x2=x[2]; // t10
    L r0=vn(x0);
    E c = 0; L tot=0;
    initV(z, H_E, 1);
    DOP(r0, if(AND(GT(vE(x0,i),0),MEMBER_CONST(vS(x1,i),x2))){\
	c+=vE(x0,i);tot++;}, reduction(+:c,tot))
    vE(z,0) = c/tot;
    R 0;
}
static I q22_autofusion_5(V z, V *x){
    V x0=x[0]; // t33
    V x1=x[1]; // t25
    V x2=x[2]; // t37
    V x3=x[3]; // t36
    L r0=vn(x2);
    /* Fusion: kind E */
    initV(z, H_B, r0);
    DOP(r0, vB(z,i)=AND(GT(vE(x0,i),ve(x1)),MEMBER_CONST(vS(x2,i),x3))) R 0;
}
static I q22_patterncompress_0(V *z, V x, V *y){
    V z0 = z[0]; // t66
    V z1 = z[1]; // t67
    V y0 = y[0]; // t32
    V y1 = y[1]; // t33
    L len = vn(x), k = 0;
    L lenZ = 0, parZ[H_CORE], offset[H_CORE];
    DOI(H_CORE, parZ[i]=offset[i]=0)
    CHECKE(getNumOfNonZero(x,parZ));
    DOI(H_CORE, lenZ += parZ[i])
    DOIa(H_CORE, offset[i]=parZ[i-1]+offset[i-1])
    initV(z0,H_S,lenZ);
    initV(z1,H_E,lenZ);
    DOT(len, if(vB(x,i)){L c=offset[tid]++;\
        vS(z0,c) = vS(y0,i);\
        vE(z1,c) = vE(y1,i);\
    })
    R 0;
}

static I q22_autofusionlist_1(V *z, V *x){
    V x0=x[0]; // t70
    V x1=x[1]; // t74
    V x2=x[2]; // t67
    V z0=z[0]; // t81
    V z1=z[1]; // t78
    initV(z0, H_L, vn(x1)); // t81
    initV(z1, H_E, vn(x1)); // t78
        DOJ(vn(x1), {V t=vV(x1,j); \
            E c1=0;E c2=0; \
            DOP(vn(t), {L k=vL(t,i);\
                c1+=vE(x2,k); \
            }, reduction(+:c1,c2)) \
            vL(z0,j)=vn(vV(x1,j)); \
            vE(z1,j)=c1; \
        })
    R 0;
}

static I q22_patternindex_7(V *z, V *x, V y){
    V z0 = z[0]; // t84
    V z1 = z[1]; // t85
    V z2 = z[2]; // t86
    V x0 = x[0]; // t75
    V x1 = x[1]; // t81
    V x2 = x[2]; // t78
    initV(z0, H_S, vn(y));
    initV(z1, H_L, vn(y));
    initV(z2, H_E, vn(y));
    DOP(vn(z0), {
        vS(z0,i) = vS(x0, vL(y,i));
        vL(z1,i) = vL(x1, vL(y,i));
        vE(z2,i) = vE(x2, vL(y,i));
    })
    R 0;
}


static I horse_main(V *h_rtn){
    V t0 = incV(); V t6 = incV(); V t7 = incV(); V t10 = incV(); 
    V t11 = incV(); V t20 = incV(); V t12 = incV(); V t13 = incV(); 
    V t14 = incV(); V t32 = incV(); V t33 = incV(); V t25 = incV(); 
    V t26 = incV(); V t51 = incV(); V t60 = incV(); V t36 = incV(); 
    V t61 = incV(); V t37 = incV(); V t70 = incV(); V t38 = incV(); 
    V t71 = incV(); V t47 = incV(); V t80 = incV(); V t72 = incV(); 
    V t48 = incV(); V t81 = incV(); V t73 = incV(); V t49 = incV(); 
    V t82 = incV(); V t74 = incV(); V t66 = incV(); V t83 = incV(); 
    V t75 = incV(); V t67 = incV(); V t84 = incV(); V t76 = incV(); 
    V t85 = incV(); V t77 = incV(); V t86 = incV(); V t78 = incV(); 
    V t87 = incV(); V t79 = incV(); V t88 = incV(); V t89 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("customer")));
    PROFILE(5, pfnColumnValue(t6, t0, LiteralSymbol("c_phone")));
    PROFILE(6, pfnColumnValue(t7, t0, LiteralSymbol("c_acctbal")));
    PROFILE(7, copyV(t10,LiteralVectorString(7, (S []){"13", "31", "23", "29", "30", "18", "17"})));
    PROFILE(8, pfnSubString(t11, t6, LiteralVectorI32(2, (I []){1, 2})));
    PROFILE(13, q22_autofusion_6(t25, (V[]){t7,t11,t10}));
    PROFILE(14, pfnLoadTable(t26, LiteralSymbol("customer")));
    PROFILE(15, pfnColumnValue(t32, t26, LiteralSymbol("c_phone")));
    PROFILE(16, pfnColumnValue(t33, t26, LiteralSymbol("c_acctbal")));
    PROFILE(17, copyV(t36,LiteralVectorString(7, (S []){"13", "31", "23", "29", "30", "18", "17"})));
    PROFILE(18, pfnSubString(t37, t32, LiteralVectorI32(2, (I []){1, 2})));
    PROFILE(21, q22_autofusion_5(t48, (V[]){t33,t25,t37,t36}));
    PROFILE(22, pfnLoadTable(t49, LiteralSymbol("orders")));
    PROFILE(23, pfnColumnValue(t51, t49, LiteralSymbol("o_custkey")));
    PROFILE(24, pfnValues(t60, t51));
    PROFILE(25, pfnIndexA(t61, t48, t60, LiteralBool(0)));
    PROFILE(27, q22_patterncompress_0((V []){t66, t67}, t61, (V []){t32, t33}));
    PROFILE(28, pfnSubString(t70, t66, LiteralVectorI32(2, (I []){1, 2})));
    PROFILE(29, pfnList(t71, 1, (V []){t70}));
    PROFILE(30, pfnGroup(t72, t71));
    PROFILE(31, pfnKeys(t73, t72));
    PROFILE(32, pfnValues(t74, t72));
    PROFILE(33, pfnIndex(t75, t70, t73));
    PROFILE(39, q22_autofusionlist_1((V []){t81,t78}, (V []){t70,t74,t67}));
    PROFILE(40, pfnList(t82, 1, (V []){t75}));
    PROFILE(41, pfnOrderBy(t83, t82, LiteralBool(1)));
    PROFILE(44, q22_patternindex_7((V []){t84, t85, t86}, (V []){t75, t81, t78}, t83));
    PROFILE(45, copyV(t87,LiteralVectorSymbol(3, (S []){"cntrycode", "numcust", "totacctbal"})));
    PROFILE(46, pfnList(t88, 3, (V []){t84, t85, t86}));
    PROFILE(47, pfnTable(t89, t87, t88));
    h_rtn[0] = t89;
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

// Compiling time (ms): 1.387
