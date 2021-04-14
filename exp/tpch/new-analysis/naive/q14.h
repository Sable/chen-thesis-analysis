// Parsing time (ms): 0.438
static I horse_main(V *h_rtn);


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
    PROFILE(9, pfnGeq(t18, t12, LiteralDate(19950901)));
    PROFILE(10, pfnLt(t19, t12, LiteralDate(19951001)));
    PROFILE(11, pfnAnd(t20, t18, t19));
    PROFILE(12, pfnCompress(t22, t20, t3));
    PROFILE(13, pfnCompress(t26, t20, t7));
    PROFILE(14, pfnCompress(t27, t20, t8));
    PROFILE(15, pfnLoadTable(t37, LiteralSymbol("part")));
    PROFILE(16, pfnColumnValue(t38, t37, LiteralSymbol("p_partkey")));
    PROFILE(17, pfnColumnValue(t42, t37, LiteralSymbol("p_type")));
    PROFILE(18, pfnEnum(t47, t38, t22));
    PROFILE(19, pfnValues(t48, t47));
    PROFILE(20, pfnKeys(t49, t47));
    PROFILE(21, pfnLen(t50, t49));
    PROFILE(22, pfnLt(t51, t48, t50));
    PROFILE(23, pfnWhere(t52, t51));
    PROFILE(24, pfnIndex(t58, t26, t52));
    PROFILE(25, pfnIndex(t59, t27, t52));
    PROFILE(26, pfnIndex(t73, t42, t48));
    PROFILE(27, pfnLike2(t78, t73, LiteralSymbol("PROMO%")));
    PROFILE(28, pfnMinus(t79, LiteralI32(1), t59));
    PROFILE(29, pfnMul(t80, t58, t79));
    PROFILE(30, pfnMul(t81, t78, t80));
    PROFILE(31, pfnNot(t82, t78));
    PROFILE(32, pfnMul(t83, t82, LiteralF64(0)));
    PROFILE(33, pfnPlus(t84, t81, t83));
    PROFILE(34, pfnMinus(t85, LiteralI32(1), t59));
    PROFILE(35, pfnMul(t86, t58, t85));
    PROFILE(36, pfnSum(t87, t84));
    PROFILE(37, pfnSum(t88, t86));
    PROFILE(38, pfnMul(t89, LiteralF64(100), t87));
    PROFILE(39, pfnDiv(t90, t89, t88));
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

// Compiling time (ms): 0.215
