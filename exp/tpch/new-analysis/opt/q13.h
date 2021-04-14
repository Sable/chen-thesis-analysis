// Parsing time (ms): 0.433
// Total # of fused stmts: 0
static I horse_main(V *h_rtn);
static I q13_patternindex_0(V *z, V *x, V y);

static I q13_patternindex_0(V *z, V *x, V y){
    V z0 = z[0]; // t64
    V z1 = z[1]; // t65
    V x0 = x[0]; // t59
    V x1 = x[1]; // t61
    initV(z0, H_L, vn(y));
    initV(z1, H_L, vn(y));
    DOP(vn(z0), {
        vL(z0,i) = vL(x0, vL(y,i));
        vL(z1,i) = vL(x1, vL(y,i));
    })
    R 0;
}


static I horse_main(V *h_rtn){
    V t0 = incV(); V t1 = incV(); V t9 = incV(); V t11 = incV(); 
    V t20 = incV(); V t30 = incV(); V t22 = incV(); V t31 = incV(); 
    V t40 = incV(); V t32 = incV(); V t41 = incV(); V t33 = incV(); 
    V t42 = incV(); V t34 = incV(); V t18 = incV(); V t51 = incV(); 
    V t43 = incV(); V t35 = incV(); V t19 = incV(); V t60 = incV(); 
    V t52 = incV(); V t44 = incV(); V t36 = incV(); V t61 = incV(); 
    V t53 = incV(); V t45 = incV(); V t37 = incV(); V t62 = incV(); 
    V t54 = incV(); V t46 = incV(); V t38 = incV(); V t63 = incV(); 
    V t55 = incV(); V t47 = incV(); V t39 = incV(); V t64 = incV(); 
    V t56 = incV(); V t65 = incV(); V t57 = incV(); V t66 = incV(); 
    V t58 = incV(); V t67 = incV(); V t59 = incV(); V t68 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("customer")));
    PROFILE(5, pfnColumnValue(t1, t0, LiteralSymbol("c_custkey")));
    PROFILE(6, pfnLoadTable(t9, LiteralSymbol("orders")));
    PROFILE(7, pfnColumnValue(t11, t9, LiteralSymbol("o_custkey")));
    PROFILE(8, pfnColumnValue(t18, t9, LiteralSymbol("o_comment")));
    PROFILE(9, pfnLike2(t19, t18, LiteralSymbol("%special%requests%")));
    PROFILE(10, pfnNot(t20, t19));
    PROFILE(11, pfnFetch(t22, t11));
    PROFILE(12, pfnCompress(t30, t20, t22));
    PROFILE(15, pfnGroup(t31, t1));
    PROFILE(16, pfnKeys(t32, t31));
    PROFILE(17, pfnValues(t33, t31));
    PROFILE(18, pfnEach(t34, t33, pfnLen));
    PROFILE(19, pfnRaze(t35, t34));
    PROFILE(20, pfnIndex(t36, t1, t32));
    PROFILE(21, pfnGroup(t37, t30));
    PROFILE(22, pfnKeys(t38, t37));
    PROFILE(23, pfnValues(t39, t37));
    PROFILE(24, pfnEach(t40, t39, pfnLen));
    PROFILE(25, pfnRaze(t41, t40));
    PROFILE(26, pfnIndex(t42, t30, t38));
    PROFILE(27, pfnJoinIndex(t43, t36, t42, LiteralSymbol((S)"eq")));
    PROFILE(28, pfnIndex(t44, t43, LiteralI64(0)));
    PROFILE(29, pfnIndex(t45, t43, LiteralI64(1)));
    PROFILE(30, pfnIndex(t46, t35, t44));
    PROFILE(31, pfnIndex(t47, t41, t45));
    PROFILE(32, pfnMul(t51, t46, t47));
    PROFILE(33, pfnLen(t52, t32));
    PROFILE(34, pfnVector(t53, t52, LiteralI64(0)));
    PROFILE(35, pfnIndexA(t54, t53, t44, t51));
    PROFILE(36, pfnList(t55, 1, (V []){t54}));
    PROFILE(37, pfnGroup(t56, t55));
    PROFILE(38, pfnKeys(t57, t56));
    PROFILE(39, pfnValues(t58, t56));
    PROFILE(40, pfnIndex(t59, t54, t57));
    PROFILE(41, pfnEach(t60, t58, pfnLen));
    PROFILE(42, pfnRaze(t61, t60));
    PROFILE(43, pfnList(t62, 2, (V []){t61, t59}));
    PROFILE(44, pfnOrderBy(t63, t62, LiteralVectorBool(2, (B []){0, 0})));
    PROFILE(46, q13_patternindex_0((V []){t64, t65}, (V []){t59, t61}, t63));
    PROFILE(47, copyV(t66,LiteralVectorSymbol(2, (S []){"c_count", "custdist"})));
    PROFILE(48, pfnList(t67, 2, (V []){t64, t65}));
    PROFILE(49, pfnTable(t68, t66, t67));
    h_rtn[0] = t68;
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

// Compiling time (ms): 0.878
