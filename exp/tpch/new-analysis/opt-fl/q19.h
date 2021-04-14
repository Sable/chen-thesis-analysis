// Parsing time (ms): 0.645
 // - #: 5
 // - #: 14
 // - #: 7
 // - #: 7
 // - #: 7
 // - #: 3
// Total # of fused stmts: 43
static I horse_main(V *h_rtn);
static I q19_autofusion_11(V z, V *x);
static I q19_autofusion_10(V z, V *x);
static I q19_autofusion_9(V z, V *x);
static I q19_autofusion_8(V z, V *x);
static I q19_autofusion_7(V z, V *x);
static I q19_autofusion_6(V z, V *x);

static I q19_autofusion_11(V z, V *x){
    V x0=x[0]; // t25
    V x1=x[1]; // t26
    V x2=x[2]; // t28
    Q id3=getSymbol("DELIVER IN PERSON");
    L r0=vn(x1);
    /* Fusion: kind E */
    initV(z, H_B, r0);
    DOP(r0, vB(z,i)=AND(EQ(vQ(x0,i),id3),MEMBER_CONST_Q(vQ(x1,i),x2))) R 0;
}
static I q19_autofusion_10(V z, V *x){
    V x0=x[0]; // t6
    V x1=x[1]; // t4
    V x2=x[2]; // t7
    V x3=x[3]; // t52
    Q id2=getSymbol("Brand#12");
    L r0=vn(x2);
    /* Fusion: kind E */
    initV(z, H_B, r0);
    DOP(r0, vB(z,i)=AND(AND(AND(GEQ(vI(x0,i),1),LEQ(vI(x0,i),5)),EQ(vQ(x1,i),id2)),MEMBER_CONST_Q(vQ(x2,i),x3))) R 0;
}
static I q19_autofusion_9(V z, V *x){
    V x0=x[0]; // t6
    V x1=x[1]; // t4
    V x2=x[2]; // t7
    V x3=x[3]; // t63
    Q id1=getSymbol("Brand#23");
    L r0=vn(x2);
    /* Fusion: kind E */
    initV(z, H_B, r0);
    DOP(r0, vB(z,i)=AND(AND(AND(GEQ(vI(x0,i),1),LEQ(vI(x0,i),10)),EQ(vQ(x1,i),id1)),MEMBER_CONST_Q(vQ(x2,i),x3))) R 0;
}
static I q19_autofusion_8(V z, V *x){
    V x0=x[0]; // t6
    V x1=x[1]; // t4
    V x2=x[2]; // t7
    V x3=x[3]; // t74
    Q id0=getSymbol("Brand#34");
    L r0=vn(x2);
    /* Fusion: kind E */
    initV(z, H_B, r0);
    DOP(r0, vB(z,i)=AND(AND(AND(GEQ(vI(x0,i),1),LEQ(vI(x0,i),15)),EQ(vQ(x1,i),id0)),MEMBER_CONST_Q(vQ(x2,i),x3))) R 0;
}
static I q19_autofusion_7(V z, V *x){
    V x0=x[0]; // t84
    V x1=x[1]; // t36
    V x2=x[2]; // t85
    V x3=x[3]; // t86
    L r0=vn(x3);
    /* Fusion: kind E */
    initV(z, H_B, r0);
    DOP(r0, vB(z,i)=OR(OR(AND(vB(x0,i),AND(GEQ(vE(x1,i),1),LEQ(vE(x1,i),11))),AND(vB(x2,i),AND(GEQ(vE(x1,i),10),LEQ(vE(x1,i),20)))),AND(vB(x3,i),AND(GEQ(vE(x1,i),20),LEQ(vE(x1,i),30))))) R 0;
}
static I q19_autofusion_6(V z, V *x){
    V x0=x[0]; // t91
    V x1=x[1]; // t37
    V x2=x[2]; // t38
    L r0=vn(x2);
    E c = 0; L tot=0;
    initV(z, H_E, 1);
    DOP(r0, if(vB(x0,i)){\
	c+=MUL(vE(x1,i),MINUS(1,vE(x2,i)));}, reduction(+:c))
    vE(z,0) = c;
    R 0;
}

static I horse_main(V *h_rtn){
    V t120 = incV(); V t121 = incV(); V t122 = incV(); V t106 = incV(); 
    V t107 = incV(); V t117 = incV(); V t118 = incV(); V t119 = incV(); 
    V t0 = incV(); V t1 = incV(); V t4 = incV(); V t6 = incV(); 
    V t7 = incV(); V t10 = incV(); V t13 = incV(); V t30 = incV(); 
    V t31 = incV(); V t16 = incV(); V t33 = incV(); V t25 = incV(); 
    V t17 = incV(); V t50 = incV(); V t26 = incV(); V t18 = incV(); 
    V t51 = incV(); V t60 = incV(); V t52 = incV(); V t36 = incV(); 
    V t28 = incV(); V t61 = incV(); V t53 = incV(); V t37 = incV(); 
    V t29 = incV(); V t70 = incV(); V t62 = incV(); V t54 = incV(); 
    V t38 = incV(); V t71 = incV(); V t63 = incV(); V t55 = incV(); 
    V t80 = incV(); V t72 = incV(); V t64 = incV(); V t56 = incV(); 
    V t48 = incV(); V t81 = incV(); V t73 = incV(); V t65 = incV(); 
    V t57 = incV(); V t49 = incV(); V t90 = incV(); V t82 = incV(); 
    V t74 = incV(); V t66 = incV(); V t58 = incV(); V t91 = incV(); 
    V t83 = incV(); V t75 = incV(); V t67 = incV(); V t59 = incV(); 
    V t84 = incV(); V t76 = incV(); V t68 = incV(); V t85 = incV(); 
    V t77 = incV(); V t69 = incV(); V t86 = incV(); V t78 = incV(); 
    V t87 = incV(); V t79 = incV(); V t88 = incV(); V t89 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("part")));
    PROFILE(5, pfnColumnValue(t1, t0, LiteralSymbol("p_partkey")));
    PROFILE(6, pfnColumnValue(t4, t0, LiteralSymbol("p_brand")));
    PROFILE(7, pfnColumnValue(t6, t0, LiteralSymbol("p_size")));
    PROFILE(8, pfnColumnValue(t7, t0, LiteralSymbol("p_container")));
    PROFILE(9, pfnLoadTable(t10, LiteralSymbol("lineitem")));
    PROFILE(10, pfnColumnValue(t13, t10, LiteralSymbol("l_partkey")));
    PROFILE(11, pfnColumnValue(t16, t10, LiteralSymbol("l_quantity")));
    PROFILE(12, pfnColumnValue(t17, t10, LiteralSymbol("l_extendedprice")));
    PROFILE(13, pfnColumnValue(t18, t10, LiteralSymbol("l_discount")));
    PROFILE(14, pfnColumnValue(t25, t10, LiteralSymbol("l_shipinstruct")));
    PROFILE(15, pfnColumnValue(t26, t10, LiteralSymbol("l_shipmode")));
    PROFILE(16, copyV(t28,LiteralVectorSymbol(2, (S []){"AIR", "AIR REG"})));
    PROFILE(19, q19_autofusion_11(t31, (V[]){t25,t26,t28}));
    PROFILE(20, pfnCompress(t33, t31, t13));
    PROFILE(21, pfnCompress(t36, t31, t16));
    PROFILE(22, pfnCompress(t37, t31, t17));
    PROFILE(23, pfnCompress(t38, t31, t18));
    PROFILE(28, copyV(t52,LiteralVectorSymbol(4, (S []){"SM CASE", "SM BOX", "SM PACK", "SM PKG"})));
    PROFILE(33, q19_autofusion_10(t57, (V[]){t6,t4,t7,t52}));
    PROFILE(39, copyV(t63,LiteralVectorSymbol(4, (S []){"MED BAG", "MED BOX", "MED PKG", "MED PACK"})));
    PROFILE(44, q19_autofusion_9(t68, (V[]){t6,t4,t7,t63}));
    PROFILE(50, copyV(t74,LiteralVectorSymbol(4, (S []){"LG CASE", "LG BOX", "LG PACK", "LG PKG"})));
    PROFILE(55, q19_autofusion_8(t79, (V[]){t6,t4,t7,t74}));
    PROFILE(57, pfnCompress(t81, t57, t1));
    PROFILE(58, pfnCompress(t82, t68, t1));
    PROFILE(59, pfnCompress(t83, t79, t1));
    PROFILE(60, pfnMember(t84, t33, t81));
    PROFILE(61, pfnMember(t85, t33, t82));
    PROFILE(62, pfnMember(t86, t33, t83));
    PROFILE(67, q19_autofusion_7(t91, (V[]){t84,t36,t85,t86}));
    PROFILE(72, q19_autofusion_6(t119, (V[]){t91,t37,t38}));
    PROFILE(73, copyV(t120,LiteralSymbol("revenue")));
    PROFILE(74, pfnList(t121, 1, (V []){t119}));
    PROFILE(75, pfnTable(t122, t120, t121));
    h_rtn[0] = t122;
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

// Compiling time (ms): 2.759
