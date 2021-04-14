// Parsing time (ms): 0.487
static I horse_main(V *h_rtn);
static I q22_patterncompress_1(V *z, V x, V *y);
static I q22_peephole_fp1_0(V z, V x, V y);

static I q22_patterncompress_1(V *z, V x, V *y){
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

static I q22_peephole_fp1_0(V z, V x, V y){
    // z -> t78
    initV(z, H_E, vn(y));
    DOP(vn(y), {E a=0; V t=vV(y,i); DOJ(vn(t), a+=vE(x,vL(t,j))) vE(z,i)=a;}) R 0;
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
    PROFILE(9, pfnMember(t12, t11, t10));
    PROFILE(10, pfnGt(t13, t7, LiteralF64(0)));
    PROFILE(11, pfnAnd(t14, t13, t12));
    PROFILE(12, pfnCompress(t20, t14, t7));
    PROFILE(13, pfnAvg(t25, t20));
    PROFILE(14, pfnLoadTable(t26, LiteralSymbol("customer")));
    PROFILE(15, pfnColumnValue(t32, t26, LiteralSymbol("c_phone")));
    PROFILE(16, pfnColumnValue(t33, t26, LiteralSymbol("c_acctbal")));
    PROFILE(17, copyV(t36,LiteralVectorString(7, (S []){"13", "31", "23", "29", "30", "18", "17"})));
    PROFILE(18, pfnSubString(t37, t32, LiteralVectorI32(2, (I []){1, 2})));
    PROFILE(19, pfnMember(t38, t37, t36));
    PROFILE(20, pfnGt(t47, t33, t25));
    PROFILE(21, pfnAnd(t48, t47, t38));
    PROFILE(22, pfnLoadTable(t49, LiteralSymbol("orders")));
    PROFILE(23, pfnColumnValue(t51, t49, LiteralSymbol("o_custkey")));
    PROFILE(24, pfnValues(t60, t51));
    PROFILE(25, pfnIndexA(t61, t48, t60, LiteralBool(0)));
    PROFILE(27, q22_patterncompress_1((V []){t66, t67}, t61, (V []){t32, t33}));
    PROFILE(28, pfnSubString(t70, t66, LiteralVectorI32(2, (I []){1, 2})));
    PROFILE(29, pfnList(t71, 1, (V []){t70}));
    PROFILE(30, pfnGroup(t72, t71));
    PROFILE(31, pfnKeys(t73, t72));
    PROFILE(32, pfnValues(t74, t72));
    PROFILE(33, pfnIndex(t75, t70, t73));
    PROFILE(36, q22_peephole_fp1_0(t78,t67,t74));
    PROFILE(37, pfnEachRight(t79, t70, t74, pfnIndex));
    PROFILE(38, pfnEach(t80, t79, pfnLen));
    PROFILE(39, pfnRaze(t81, t80));
    PROFILE(40, pfnList(t82, 1, (V []){t75}));
    PROFILE(41, pfnOrderBy(t83, t82, LiteralBool(1)));
    PROFILE(42, pfnIndex(t84, t75, t83));
    PROFILE(43, pfnIndex(t85, t81, t83));
    PROFILE(44, pfnIndex(t86, t78, t83));
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

// Compiling time (ms): 0.7
