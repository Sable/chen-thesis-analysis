// Parsing time (ms): 0.55
 // - #: 6
 // - #: 7
 // - #: 7
 // - #: 4
 // - #: 9
// Total # of fused stmts: 33
static I horse_main(V *h_rtn);
static I q12_autofusion_9(V z, V *x);
static I q12_autofusion_4(V *z, V *x);
static I q12_autofusion_8(V z, V *x);
static I q12_autofusion_7(V z, V *x);
static I q12_autofusionlist_0(V *z, V *x);

static I q12_autofusion_9(V z, V *x){
    V x0=x[0]; // t14
    V x1=x[1]; // t16
    V x2=x[2]; // t18
    V x3=x[3]; // t13
    V x4=x[4]; // t12
    L r0=vn(x3);
    /* Fusion: kind E */
    initV(z, H_B, r0);
    DOP(r0, vB(z,i)=AND(AND(GEQ(vD(x0,i),19940101),LT(vD(x0,i),19950101)),AND(AND(MEMBER_CONST_Q(vQ(x1,i),x2),LT(vD(x3,i),vD(x0,i))),LT(vD(x4,i),vD(x3,i))))) R 0;
}
static I q12_autofusion_4(V *z, V *x){
    V x0=x[0]; // t51
    V x1=x[1]; // t27
    V x2=x[2]; // t55
    V x3=x[3]; // t16
    V z0=z[0]; // 
    V z1=z[1]; // 
    L parZ[H_CORE], offset[H_CORE], total = 0;
    DOI(H_CORE, parZ[i]=offset[i]=0)
    DOT(vn(x1), if(vB(x1,i)) parZ[tid]++)
    DOI(H_CORE, total+=parZ[i])
    DOIa(H_CORE, offset[i]=parZ[i-1]+offset[i-1])
    initV(z0, H_Q, total);
    initV(z1, H_Q, total);
    DOT(vn(x1),if(vB(x1,i)){ L c=offset[tid]++; \
        vQ(z0,c) = vQ(x0,vL(x2,i)); \
        vQ(z1,c) = vQ(x3,i);})
    R 0;
}

static I q12_autofusion_8(V z, V *x){
    V x0=x[0]; // t79
    Q id0=getSymbol("1-URGENT");
    Q id1=getSymbol("2-HIGH");
    L r0=vn(x0);
    /* Fusion: kind E */
    initV(z, H_I, r0);
    DOP(r0, vI(z,i)=PLUS(MUL(OR(EQ(vQ(x0,i),id0),EQ(vQ(x0,i),id1)),1),MUL(NOT(OR(EQ(vQ(x0,i),id0),EQ(vQ(x0,i),id1))),0))) R 0;
}
static I q12_autofusion_7(V z, V *x){
    V x0=x[0]; // t79
    Q id0=getSymbol("1-URGENT");
    Q id1=getSymbol("2-HIGH");
    L r0=vn(x0);
    /* Fusion: kind E */
    initV(z, H_I, r0);
    DOP(r0, vI(z,i)=PLUS(MUL(AND(NEQ(vQ(x0,i),id0),NEQ(vQ(x0,i),id1)),1),MUL(NOT(AND(NEQ(vQ(x0,i),id0),NEQ(vQ(x0,i),id1))),0))) R 0;
}
static I q12_autofusionlist_0(V *z, V *x){
    V x0=x[0]; // t96
    V x1=x[1]; // t100
    V x2=x[2]; // t89
    V z0=z[0]; // t107
    V z1=z[1]; // t104
    initV(z0, H_L, vn(x1)); // t107
    initV(z1, H_L, vn(x1)); // t104
        DOJ(vn(x1), {V t=vV(x1,j); \
            L c0=0; L c1=0; \
            DOP(vn(t), {L k=vL(t,i);\
                c0+=vI(x0,k); \
                c1+=vI(x2,k); \
            }, reduction(+:c0,c1)) \
            vL(z0,j)=c0; \
            vL(z1,j)=c1; \
        })
    R 0;
}


static I horse_main(V *h_rtn){
    V t100 = incV(); V t98 = incV(); V t101 = incV(); V t99 = incV(); 
    V t110 = incV(); V t102 = incV(); V t111 = incV(); V t103 = incV(); 
    V t112 = incV(); V t104 = incV(); V t113 = incV(); V t105 = incV(); 
    V t114 = incV(); V t106 = incV(); V t115 = incV(); V t107 = incV(); 
    V t108 = incV(); V t109 = incV(); V t0 = incV(); V t1 = incV(); 
    V t20 = incV(); V t12 = incV(); V t21 = incV(); V t13 = incV(); 
    V t22 = incV(); V t14 = incV(); V t23 = incV(); V t24 = incV(); 
    V t16 = incV(); V t25 = incV(); V t26 = incV(); V t18 = incV(); 
    V t51 = incV(); V t27 = incV(); V t19 = incV(); V t44 = incV(); 
    V t55 = incV(); V t72 = incV(); V t56 = incV(); V t57 = incV(); 
    V t90 = incV(); V t91 = incV(); V t83 = incV(); V t92 = incV(); 
    V t84 = incV(); V t93 = incV(); V t85 = incV(); V t94 = incV(); 
    V t86 = incV(); V t95 = incV(); V t87 = incV(); V t79 = incV(); 
    V t96 = incV(); V t88 = incV(); V t97 = incV(); V t89 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("lineitem")));
    PROFILE(5, pfnColumnValue(t1, t0, LiteralSymbol("l_orderkey")));
    PROFILE(6, pfnColumnValue(t12, t0, LiteralSymbol("l_shipdate")));
    PROFILE(7, pfnColumnValue(t13, t0, LiteralSymbol("l_commitdate")));
    PROFILE(8, pfnColumnValue(t14, t0, LiteralSymbol("l_receiptdate")));
    PROFILE(9, pfnColumnValue(t16, t0, LiteralSymbol("l_shipmode")));
    PROFILE(10, copyV(t18,LiteralVectorSymbol(2, (S []){"MAIL", "SHIP"})));
    PROFILE(19, q12_autofusion_9(t27, (V[]){t14,t16,t18,t13,t12}));
    PROFILE(20, pfnLoadTable(t44, LiteralSymbol("orders")));
    PROFILE(21, pfnColumnValue(t51, t44, LiteralSymbol("o_orderpriority")));
    PROFILE(22, pfnValues(t55, t1));
    PROFILE(23, pfnCompress(t56, t27, t55));
    PROFILE(24, pfnWhere(t57, t27));
    PROFILE(26, q12_autofusion_4((V []){t79,t72}, (V []){t51,t27,t55,t16}));
    PROFILE(33, q12_autofusion_8(t89, (V[]){t79}));
    PROFILE(40, q12_autofusion_7(t96, (V[]){t79}));
    PROFILE(41, pfnList(t97, 1, (V []){t72}));
    PROFILE(42, pfnGroup(t98, t97));
    PROFILE(43, pfnKeys(t99, t98));
    PROFILE(44, pfnValues(t100, t98));
    PROFILE(45, pfnIndex(t101, t72, t99));
    PROFILE(51, q12_autofusionlist_0((V []){t107,t104}, (V []){t96,t100,t89}));
    PROFILE(52, pfnList(t108, 1, (V []){t101}));
    PROFILE(53, pfnOrderBy(t109, t108, LiteralBool(1)));
    PROFILE(54, pfnIndex(t110, t101, t109));
    PROFILE(55, pfnIndex(t111, t104, t109));
    PROFILE(56, pfnIndex(t112, t107, t109));
    PROFILE(57, copyV(t113,LiteralVectorSymbol(3, (S []){"l_shipmode", "high_line_count", "low_line_count"})));
    PROFILE(58, pfnList(t114, 3, (V []){t110, t111, t112}));
    PROFILE(59, pfnTable(t115, t113, t114));
    h_rtn[0] = t115;
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

// Compiling time (ms): 1.992
