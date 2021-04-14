// Parsing time (ms): 0.637
 // - #: 24
 // - #: 4
 // - #: 2
// Total # of fused stmts: 30
static I horse_main(V *h_rtn);
static I q1_autofusion_11(V z, V *x);
static I q1_autofusion_10(V z, V *x);
static I q1_autofusionlist_0(V *z, V *x);

static I q1_autofusion_11(V z, V *x){
    V x0=x[0]; // t24
    V x1=x[1]; // t25
    L r0=vn(x0);
    /* Fusion: kind E */
    initV(z, H_E, r0);
    DOP(r0, vE(z,i)=MUL(vE(x0,i),MINUS(1,vE(x1,i)))) R 0;
}
static I q1_autofusion_10(V z, V *x){
    V x0=x[0]; // t24
    V x1=x[1]; // t25
    V x2=x[2]; // t26
    L r0=vn(x2);
    /* Fusion: kind E */
    initV(z, H_E, r0);
    DOP(r0, vE(z,i)=MUL(MUL(vE(x0,i),MINUS(1,vE(x1,i))),PLUS(1,vE(x2,i)))) R 0;
}
static I q1_autofusionlist_0(V *z, V *x){
    V x0=x[0]; // t27
    V x1=x[1]; // t44
    V x2=x[2]; // t25
    V x3=x[3]; // t40
    V x4=x[4]; // t36
    V x5=x[5]; // t24
    V x6=x[6]; // t23
    V z0=z[0]; // t73
    V z1=z[1]; // t70
    V z2=z[2]; // t64
    V z3=z[3]; // t61
    V z4=z[4]; // t58
    V z5=z[5]; // t55
    V z6=z[6]; // t52
    V z7=z[7]; // t49
    initV(z0, H_L, vn(x1)); // t73
    initV(z1, H_E, vn(x1)); // t70
    initV(z2, H_E, vn(x1)); // t64
    initV(z3, H_E, vn(x1)); // t61
    initV(z4, H_E, vn(x1)); // t58
    initV(z5, H_E, vn(x1)); // t55
    initV(z6, H_E, vn(x1)); // t52
    initV(z7, H_E, vn(x1)); // t49
        DOJ(vn(x1), {V t=vV(x1,j); \
            E c0=0;E c1=0; E c2=0; E c3=0; E c4=0; E c5=0; E c6=0; E c7=0; \
            DOP(vn(t), {L k=vL(t,i);\
                c1+=vE(x2,k); \
                c2+=vE(x3,k); \
                c3+=vE(x4,k); \
                c4+=vE(x5,k); \
                c5+=vE(x5,k); \
                c6+=vE(x6,k); \
                c7+=vE(x6,k); \
            }, reduction(+:c0,c1,c2,c3,c4,c5,c6,c7)) \
            vL(z0,j)=vn(vV(x1,j)); \
            vE(z1,j)=c1/vn(t); \
            vE(z2,j)=c2; \
            vE(z3,j)=c3; \
            vE(z4,j)=c4/vn(t); \
            vE(z5,j)=c5; \
            vE(z6,j)=c6/vn(t); \
            vE(z7,j)=c7; \
        })
    R 0;
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
    PROFILE(13, pfnCompress(t23, t18, t6));
    PROFILE(14, pfnCompress(t24, t18, t7));
    PROFILE(15, pfnCompress(t25, t18, t8));
    PROFILE(16, pfnCompress(t26, t18, t9));
    PROFILE(17, pfnCompress(t27, t18, t10));
    PROFILE(18, pfnCompress(t28, t18, t11));
    PROFILE(20, q1_autofusion_11(t36, (V[]){t24,t25}));
    PROFILE(24, q1_autofusion_10(t40, (V[]){t24,t25,t26}));
    PROFILE(25, pfnList(t41, 2, (V []){t27, t28}));
    PROFILE(26, pfnGroup(t42, t41));
    PROFILE(27, pfnKeys(t43, t42));
    PROFILE(28, pfnValues(t44, t42));
    PROFILE(29, pfnIndex(t45, t27, t43));
    PROFILE(30, pfnIndex(t46, t28, t43));
    PROFILE(54, q1_autofusionlist_0((V []){t73,t70,t64,t61,t58,t55,t52,t49}, (V []){t27,t44,t25,t40,t36,t24,t23}));
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

// Compiling time (ms): 1.993
