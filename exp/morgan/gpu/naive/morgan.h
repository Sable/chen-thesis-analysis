// Parsing time (ms): 0.157
static I horse_main(V *h_rtn);
static I horse_morgan(V *h_rtn, V n, V x, V y);
static I horse_msum(V *h_rtn, V n, V a);


static I horse_main(V *h_rtn){
    V mg = incV(); V result = incV(); V column_x = incV(); V column_y = incV(); 
    V n = incV(); V rtn_name = incV(); V rtn = incV(); V rtn_value = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(63, pfnLoadTable(mg, LiteralSymbol("morgan")));
    PROFILE(64, copyV(n,LiteralI64(1000)));
    PROFILE(65, pfnColumnValue(column_x, mg, LiteralSymbol("x")));
    PROFILE(66, pfnColumnValue(column_y, mg, LiteralSymbol("y")));
    HORSE_UDF(67, horse_morgan(tempV, n, column_x, column_y), {*rtn=*tempV[0];});
    PROFILE(68, copyV(rtn_name,LiteralSymbol("result")));
    PROFILE(69, pfnList(rtn_value, 1, (V []){rtn}));
    PROFILE(70, pfnTable(result, rtn_name, rtn_value));
    h_rtn[0] = result;
    return 0;
}

static I horse_morgan(V *h_rtn, V n, V x, V y){
    V result = incV(); V mc_t0 = incV(); V mc_t1 = incV(); V mc_t2 = incV(); 
    V mc_t3 = incV(); V mc_t4 = incV(); V mc_t5 = incV(); V mc_t6 = incV(); 
    V mc_t7 = incV(); V sx = incV(); V mc_t8 = incV(); V sy = incV(); 
    V mc_t9 = incV(); V mc_t10 = incV(); V mc_t11 = incV(); V mc_t20 = incV(); 
    V mc_t12 = incV(); V mc_t21 = incV(); V mc_t13 = incV(); V mc_t14 = incV(); 
    V mc_t22 = incV(); V mc_t15 = incV(); V mc_t23 = incV(); V mc_t16 = incV(); 
    V mc_t24 = incV(); V mc_t17 = incV(); V mc_t25 = incV(); V mc_t18 = incV(); 
    V mc_t26 = incV(); V mc_t19 = incV(); V mc_t27 = incV(); V mc_t28 = incV(); 
    V sx2 = incV(); V sy2 = incV(); V part1 = incV(); V part2 = incV(); 
    V part3 = incV(); V sxy = incV(); 
    V tempV[10]; // temporary return vars
    HORSE_UDF(21, horse_msum(tempV, n, x), {*sx=*tempV[0];});
    HORSE_UDF(22, horse_msum(tempV, n, y), {*sy=*tempV[0];});
    PROFILE(23, copyV(mc_t0,n));
    PROFILE(24, copyV(mc_t22,LiteralF64(2)));
    PROFILE(25, gpuPower(mc_t1, x, mc_t22));
    HORSE_UDF(26, horse_msum(tempV, mc_t0, mc_t1), {*sx2=*tempV[0];});
    PROFILE(27, copyV(mc_t2,n));
    PROFILE(28, copyV(mc_t23,LiteralF64(2)));
    PROFILE(29, gpuPower(mc_t3, y, mc_t23));
    HORSE_UDF(30, horse_msum(tempV, mc_t2, mc_t3), {*sy2=*tempV[0];});
    PROFILE(31, copyV(mc_t4,n));
    PROFILE(32, pfnMul(mc_t5, x, y));
    HORSE_UDF(33, horse_msum(tempV, mc_t4, mc_t5), {*sxy=*tempV[0];});
    PROFILE(34, pfnDiv(mc_t8, sy2, n));
    PROFILE(35, pfnDiv(mc_t10, sy, n));
    PROFILE(36, copyV(mc_t24,LiteralF64(2)));
    PROFILE(37, gpuPower(mc_t9, mc_t10, mc_t24));
    PROFILE(38, pfnMinus(mc_t7, mc_t8, mc_t9));
    PROFILE(39, pfnAbs(mc_t6, mc_t7));
    PROFILE(40, copyV(mc_t25,LiteralF64(0.5)));
    PROFILE(41, gpuPower(part3, mc_t6, mc_t25));
    PROFILE(42, pfnDiv(mc_t13, sx2, n));
    PROFILE(43, pfnDiv(mc_t15, sx, n));
    PROFILE(44, copyV(mc_t26,LiteralF64(2)));
    PROFILE(45, gpuPower(mc_t14, mc_t15, mc_t26));
    PROFILE(46, pfnPlus(mc_t12, mc_t13, mc_t14));
    PROFILE(47, pfnAbs(mc_t11, mc_t12));
    PROFILE(48, copyV(mc_t27,LiteralF64(0.5)));
    PROFILE(49, gpuPower(part2, mc_t11, mc_t27));
    PROFILE(50, pfnDiv(mc_t16, sxy, n));
    PROFILE(51, pfnMul(mc_t18, sx, sy));
    PROFILE(52, copyV(mc_t28,LiteralF64(2)));
    PROFILE(53, gpuPower(mc_t19, n, mc_t28));
    PROFILE(54, pfnDiv(mc_t17, mc_t18, mc_t19));
    PROFILE(55, pfnMinus(part1, mc_t16, mc_t17));
    PROFILE(56, copyV(mc_t20,part1));
    PROFILE(57, pfnMul(mc_t21, part2, part3));
    PROFILE(58, pfnDiv(result, mc_t20, mc_t21));
    h_rtn[0] = result;
    return 0;
}

static I horse_msum(V *h_rtn, V n, V a){
    V result = incV(); V mc_t30 = incV(); V mc_t31 = incV(); V k = incV(); 
    V mc_t32 = incV(); V mc_t33 = incV(); V mc_t34 = incV(); V mc_t35 = incV(); 
    V mc_t36 = incV(); V mc_t37 = incV(); V mc_t29 = incV(); V t = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(5, pfnCumsum(t, a));
    PROFILE(6, pfnLen(k, a));
    PROFILE(7, copyV(mc_t36,LiteralF64(1)));
    PROFILE(8, pfnPlus(mc_t34, n, mc_t36));
    PROFILE(9, copyV(mc_t35,k));
    PROFILE(10, pfnRange2(mc_t33, mc_t34, mc_t35));
    PROFILE(11, pfnIndex2(mc_t29, t, mc_t33));
    PROFILE(12, pfnMinus(mc_t32, k, n));
    PROFILE(13, copyV(mc_t37,LiteralF64(1)));
    PROFILE(14, pfnRange2(mc_t31, mc_t37, mc_t32));
    PROFILE(15, pfnIndex2(mc_t30, t, mc_t31));
    PROFILE(16, pfnMinus(result, mc_t29, mc_t30));
    h_rtn[0] = result;
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

// Compiling time (ms): 1.5
