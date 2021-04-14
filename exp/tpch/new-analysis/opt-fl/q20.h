// Parsing time (ms): 0.647
 // - #: 3
// Total # of fused stmts: 3
static I horse_main(V *h_rtn);
static I q20_autofusion_2(V z, V *x);

static I q20_autofusion_2(V z, V *x){
    V x0=x[0]; // t122
    L r0=vn(x0);
    /* Fusion: kind E */
    initV(z, H_B, r0);
    DOP(r0, vB(z,i)=AND(GEQ(vD(x0,i),19940101),LT(vD(x0,i),19950101))) R 0;
}

static I horse_main(V *h_rtn){
    V t111 = incV(); V t113 = incV(); V t130 = incV(); V t122 = incV(); 
    V t114 = incV(); V t132 = incV(); V t116 = incV(); V t133 = incV(); 
    V t150 = incV(); V t151 = incV(); V t135 = incV(); V t160 = incV(); 
    V t152 = incV(); V t128 = incV(); V t153 = incV(); V t129 = incV(); 
    V t154 = incV(); V t163 = incV(); V t155 = incV(); V t147 = incV(); 
    V t180 = incV(); V t172 = incV(); V t156 = incV(); V t148 = incV(); 
    V t157 = incV(); V t149 = incV(); V t190 = incV(); V t158 = incV(); 
    V t191 = incV(); V t159 = incV(); V t185 = incV(); V t186 = incV(); 
    V t187 = incV(); V t179 = incV(); V t188 = incV(); V t189 = incV(); 
    V t0 = incV(); V t2 = incV(); V t5 = incV(); V t10 = incV(); 
    V t11 = incV(); V t12 = incV(); V t21 = incV(); V t13 = incV(); 
    V t14 = incV(); V t34 = incV(); V t26 = incV(); V t18 = incV(); 
    V t27 = incV(); V t19 = incV(); V t60 = incV(); V t44 = incV(); 
    V t36 = incV(); V t28 = incV(); V t61 = incV(); V t70 = incV(); 
    V t62 = incV(); V t71 = incV(); V t63 = incV(); V t72 = incV(); 
    V t66 = incV(); V t67 = incV(); V t68 = incV(); V t69 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("nation")));
    PROFILE(5, pfnColumnValue(t2, t0, LiteralSymbol("n_name")));
    PROFILE(6, pfnEq(t5, t2, LiteralSymbol("CANADA")));
    PROFILE(7, pfnLoadTable(t10, LiteralSymbol("supplier")));
    PROFILE(8, pfnColumnValue(t11, t10, LiteralSymbol("s_suppkey")));
    PROFILE(9, pfnColumnValue(t12, t10, LiteralSymbol("s_name")));
    PROFILE(10, pfnColumnValue(t13, t10, LiteralSymbol("s_address")));
    PROFILE(11, pfnColumnValue(t14, t10, LiteralSymbol("s_nationkey")));
    PROFILE(12, pfnValues(t18, t14));
    PROFILE(13, pfnIndex(t19, t5, t18));
    PROFILE(14, pfnWhere(t21, t19));
    PROFILE(15, pfnIndex(t26, t11, t21));
    PROFILE(16, pfnIndex(t27, t12, t21));
    PROFILE(17, pfnIndex(t28, t13, t21));
    PROFILE(18, pfnLoadTable(t34, LiteralSymbol("part")));
    PROFILE(19, pfnColumnValue(t36, t34, LiteralSymbol("p_name")));
    PROFILE(20, pfnLike2(t44, t36, LiteralSymbol("forest%")));
    PROFILE(21, pfnLoadTable(t60, LiteralSymbol("partsupp")));
    PROFILE(22, pfnColumnValue(t61, t60, LiteralSymbol("ps_partkey")));
    PROFILE(23, pfnColumnValue(t62, t60, LiteralSymbol("ps_suppkey")));
    PROFILE(24, pfnColumnValue(t63, t60, LiteralSymbol("ps_availqty")));
    PROFILE(25, pfnValues(t66, t61));
    PROFILE(26, pfnIndex(t67, t44, t66));
    PROFILE(27, pfnFetch(t68, t61));
    PROFILE(28, pfnCompress(t69, t67, t68));
    PROFILE(29, pfnFetch(t70, t62));
    PROFILE(30, pfnCompress(t71, t67, t70));
    PROFILE(31, pfnCompress(t72, t67, t63));
    PROFILE(32, pfnLoadTable(t111, LiteralSymbol("lineitem")));
    PROFILE(33, pfnColumnValue(t113, t111, LiteralSymbol("l_partkey")));
    PROFILE(34, pfnColumnValue(t114, t111, LiteralSymbol("l_suppkey")));
    PROFILE(35, pfnColumnValue(t116, t111, LiteralSymbol("l_quantity")));
    PROFILE(36, pfnColumnValue(t122, t111, LiteralSymbol("l_shipdate")));
    PROFILE(39, q20_autofusion_2(t130, (V[]){t122}));
    PROFILE(40, pfnCompress(t132, t130, t113));
    PROFILE(41, pfnCompress(t133, t130, t114));
    PROFILE(42, pfnCompress(t135, t130, t116));
    PROFILE(43, pfnList(t147, 2, (V []){t133, t132}));
    PROFILE(44, pfnGroup(t148, t147));
    PROFILE(45, pfnKeys(t149, t148));
    PROFILE(46, pfnValues(t150, t148));
    PROFILE(47, pfnEachRight(t151, t135, t150, pfnIndex));
    PROFILE(48, pfnEach(t152, t151, pfnSum));
    PROFILE(49, pfnRaze(t153, t152));
    PROFILE(50, pfnIndex(t154, t133, t149));
    PROFILE(51, pfnIndex(t155, t132, t149));
    PROFILE(52, pfnMul(t156, LiteralF64(0.5), t153));
    PROFILE(53, pfnList(t157, 3, (V []){t72, t69, t71}));
    PROFILE(54, pfnList(t158, 3, (V []){t156, t155, t154}));
    PROFILE(55, pfnJoinIndex(t159, t157, t158, LiteralVectorSymbol(3, (S []){"gt", "eq", "eq"})));
    PROFILE(56, pfnIndex(t160, t159, LiteralI64(0)));
    PROFILE(57, pfnIndex(t163, t71, t160));
    PROFILE(58, pfnMember(t172, t26, t163));
    PROFILE(59, pfnCompress(t179, t172, t27));
    PROFILE(60, pfnCompress(t180, t172, t28));
    PROFILE(61, pfnList(t185, 1, (V []){t179}));
    PROFILE(62, pfnOrderBy(t186, t185, LiteralBool(1)));
    PROFILE(63, pfnIndex(t187, t179, t186));
    PROFILE(64, pfnIndex(t188, t180, t186));
    PROFILE(65, copyV(t189,LiteralVectorSymbol(2, (S []){"s_name", "s_address"})));
    PROFILE(66, pfnList(t190, 2, (V []){t187, t188}));
    PROFILE(67, pfnTable(t191, t189, t190));
    h_rtn[0] = t191;
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

// Compiling time (ms): 1.518
