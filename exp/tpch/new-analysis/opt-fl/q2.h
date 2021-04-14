// Parsing time (ms): 1.192
 // - #: 2
 // - #: 3
// Total # of fused stmts: 5
static I horse_main(V *h_rtn);
static I q2_autofusion_3(V z, V *x);
static I q2_autofusion_1(V z, V *x);

static I q2_autofusion_3(V z, V *x){
    V x0=x[0]; // t57
    V x1=x[1]; // t56
    Q id0=getSymbol("%BRASS");
    L r0=vn(x1);
    /* Fusion: kind E */
    initV(z, H_B, r0);
    DOP(r0, vB(z,i)=AND(EQ(vI(x0,i),15),LIKE2Q(vQ(x1,i),id0))) R 0;
}
static I q2_autofusion_1(V z, V *x){
    V x0=x[0]; // t82
    V x1=x[1]; // t87
    /* Fusion: special index for where */
    L lenZ = 0, parZ[H_CORE], offset[H_CORE];
    DOI(H_CORE, parZ[i]=offset[i]=0)
    CHECKE(getNumOfNonZero(x1,parZ));
    DOI(H_CORE, lenZ += parZ[i])
    DOIa(H_CORE, offset[i]=parZ[i-1]+offset[i-1])
    initV(z, H_I, lenZ);
    DOT(vn(x1), if(vB(x1,i)){L c=offset[tid]++;\
        vI(z,c) = vI(x0,i);})
    R 0;
}


static I horse_main(V *h_rtn){
    V t98 = incV(); V t99 = incV(); V t102 = incV(); V t130 = incV(); 
    V t106 = incV(); V t131 = incV(); V t107 = incV(); V t220 = incV(); 
    V t132 = incV(); V t213 = incV(); V t117 = incV(); V t109 = incV(); 
    V t230 = incV(); V t214 = incV(); V t134 = incV(); V t215 = incV(); 
    V t232 = incV(); V t224 = incV(); V t208 = incV(); V t160 = incV(); 
    V t136 = incV(); V t225 = incV(); V t209 = incV(); V t161 = incV(); 
    V t137 = incV(); V t250 = incV(); V t170 = incV(); V t162 = incV(); 
    V t154 = incV(); V t251 = incV(); V t227 = incV(); V t171 = incV(); 
    V t163 = incV(); V t155 = incV(); V t139 = incV(); V t252 = incV(); 
    V t228 = incV(); V t180 = incV(); V t164 = incV(); V t253 = incV(); 
    V t229 = incV(); V t173 = incV(); V t165 = incV(); V t254 = incV(); 
    V t190 = incV(); V t166 = incV(); V t158 = incV(); V t255 = incV(); 
    V t247 = incV(); V t191 = incV(); V t183 = incV(); V t167 = incV(); 
    V t256 = incV(); V t248 = incV(); V t192 = incV(); V t184 = incV(); 
    V t168 = incV(); V t257 = incV(); V t249 = incV(); V t193 = incV(); 
    V t185 = incV(); V t169 = incV(); V t258 = incV(); V t194 = incV(); 
    V t259 = incV(); V t195 = incV(); V t187 = incV(); V t197 = incV(); 
    V t189 = incV(); V t0 = incV(); V t2 = incV(); V t4 = incV(); 
    V t8 = incV(); V t9 = incV(); V t10 = incV(); V t11 = incV(); 
    V t20 = incV(); V t21 = incV(); V t13 = incV(); V t30 = incV(); 
    V t14 = incV(); V t31 = incV(); V t32 = incV(); V t16 = incV(); 
    V t41 = incV(); V t33 = incV(); V t25 = incV(); V t50 = incV(); 
    V t34 = incV(); V t26 = incV(); V t51 = incV(); V t35 = incV(); 
    V t27 = incV(); V t52 = incV(); V t44 = incV(); V t36 = incV(); 
    V t28 = incV(); V t61 = incV(); V t45 = incV(); V t29 = incV(); 
    V t62 = incV(); V t54 = incV(); V t46 = incV(); V t63 = incV(); 
    V t64 = incV(); V t56 = incV(); V t48 = incV(); V t81 = incV(); 
    V t73 = incV(); V t57 = incV(); V t49 = incV(); V t82 = incV(); 
    V t66 = incV(); V t75 = incV(); V t84 = incV(); V t93 = incV(); 
    V t77 = incV(); V t86 = incV(); V t87 = incV(); V t89 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("region")));
    PROFILE(5, pfnColumnValue(t2, t0, LiteralSymbol("r_name")));
    PROFILE(6, pfnEq(t4, t2, LiteralSymbol("EUROPE")));
    PROFILE(7, pfnLoadTable(t8, LiteralSymbol("nation")));
    PROFILE(8, pfnColumnValue(t9, t8, LiteralSymbol("n_nationkey")));
    PROFILE(9, pfnColumnValue(t10, t8, LiteralSymbol("n_name")));
    PROFILE(10, pfnColumnValue(t11, t8, LiteralSymbol("n_regionkey")));
    PROFILE(11, pfnValues(t13, t11));
    PROFILE(12, pfnIndex(t14, t4, t13));
    PROFILE(13, pfnWhere(t16, t14));
    PROFILE(14, pfnIndex(t20, t9, t16));
    PROFILE(15, pfnIndex(t21, t10, t16));
    PROFILE(16, pfnLoadTable(t25, LiteralSymbol("supplier")));
    PROFILE(17, pfnColumnValue(t26, t25, LiteralSymbol("s_suppkey")));
    PROFILE(18, pfnColumnValue(t27, t25, LiteralSymbol("s_name")));
    PROFILE(19, pfnColumnValue(t28, t25, LiteralSymbol("s_address")));
    PROFILE(20, pfnColumnValue(t29, t25, LiteralSymbol("s_nationkey")));
    PROFILE(21, pfnColumnValue(t30, t25, LiteralSymbol("s_phone")));
    PROFILE(22, pfnColumnValue(t31, t25, LiteralSymbol("s_acctbal")));
    PROFILE(23, pfnColumnValue(t32, t25, LiteralSymbol("s_comment")));
    PROFILE(24, pfnFetch(t33, t29));
    PROFILE(25, pfnJoinIndex(t34, t20, t33, LiteralSymbol((S)"eq")));
    PROFILE(26, pfnIndex(t35, t34, LiteralI64(0)));
    PROFILE(27, pfnIndex(t36, t34, LiteralI64(1)));
    PROFILE(28, pfnIndex(t41, t21, t35));
    PROFILE(29, pfnIndex(t44, t26, t36));
    PROFILE(30, pfnIndex(t45, t27, t36));
    PROFILE(31, pfnIndex(t46, t28, t36));
    PROFILE(32, pfnIndex(t48, t30, t36));
    PROFILE(33, pfnIndex(t49, t31, t36));
    PROFILE(34, pfnIndex(t50, t32, t36));
    PROFILE(35, pfnLoadTable(t51, LiteralSymbol("part")));
    PROFILE(36, pfnColumnValue(t52, t51, LiteralSymbol("p_partkey")));
    PROFILE(37, pfnColumnValue(t54, t51, LiteralSymbol("p_mfgr")));
    PROFILE(38, pfnColumnValue(t56, t51, LiteralSymbol("p_type")));
    PROFILE(39, pfnColumnValue(t57, t51, LiteralSymbol("p_size")));
    PROFILE(42, q2_autofusion_3(t63, (V[]){t57,t56}));
    PROFILE(43, pfnCompress(t64, t63, t52));
    PROFILE(44, pfnCompress(t66, t63, t54));
    PROFILE(45, pfnLoadTable(t73, LiteralSymbol("region")));
    PROFILE(46, pfnColumnValue(t75, t73, LiteralSymbol("r_name")));
    PROFILE(47, pfnEq(t77, t75, LiteralSymbol("EUROPE")));
    PROFILE(48, pfnLoadTable(t81, LiteralSymbol("nation")));
    PROFILE(49, pfnColumnValue(t82, t81, LiteralSymbol("n_nationkey")));
    PROFILE(50, pfnColumnValue(t84, t81, LiteralSymbol("n_regionkey")));
    PROFILE(51, pfnValues(t86, t84));
    PROFILE(52, pfnIndex(t87, t77, t86));
    PROFILE(54, q2_autofusion_1(t93, (V[]){t82,t87}));
    PROFILE(55, pfnLoadTable(t98, LiteralSymbol("supplier")));
    PROFILE(56, pfnColumnValue(t99, t98, LiteralSymbol("s_suppkey")));
    PROFILE(57, pfnColumnValue(t102, t98, LiteralSymbol("s_nationkey")));
    PROFILE(58, pfnFetch(t106, t102));
    PROFILE(59, pfnJoinIndex(t107, t93, t106, LiteralSymbol((S)"eq")));
    PROFILE(60, pfnIndex(t109, t107, LiteralI64(1)));
    PROFILE(61, pfnIndex(t117, t99, t109));
    PROFILE(62, pfnLoadTable(t130, LiteralSymbol("partsupp")));
    PROFILE(63, pfnColumnValue(t131, t130, LiteralSymbol("ps_partkey")));
    PROFILE(64, pfnColumnValue(t132, t130, LiteralSymbol("ps_suppkey")));
    PROFILE(65, pfnColumnValue(t134, t130, LiteralSymbol("ps_supplycost")));
    PROFILE(66, pfnFetch(t136, t132));
    PROFILE(67, pfnJoinIndex(t137, t117, t136, LiteralSymbol((S)"eq")));
    PROFILE(68, pfnIndex(t139, t137, LiteralI64(1)));
    PROFILE(69, pfnFetch(t154, t131));
    PROFILE(70, pfnIndex(t155, t154, t139));
    PROFILE(71, pfnIndex(t158, t134, t139));
    PROFILE(72, pfnList(t160, 1, (V []){t155}));
    PROFILE(73, pfnGroup(t161, t160));
    PROFILE(74, pfnKeys(t162, t161));
    PROFILE(75, pfnValues(t163, t161));
    PROFILE(76, pfnEachRight(t164, t158, t163, pfnIndex));
    PROFILE(77, pfnEach(t165, t164, pfnMin));
    PROFILE(78, pfnRaze(t166, t165));
    PROFILE(79, pfnIndex(t167, t155, t162));
    PROFILE(80, pfnJoinIndex(t168, t64, t167, LiteralSymbol((S)"eq")));
    PROFILE(81, pfnIndex(t169, t168, LiteralI64(0)));
    PROFILE(82, pfnIndex(t170, t168, LiteralI64(1)));
    PROFILE(83, pfnIndex(t171, t64, t169));
    PROFILE(84, pfnIndex(t173, t66, t169));
    PROFILE(85, pfnIndex(t180, t166, t170));
    PROFILE(86, pfnLoadTable(t183, LiteralSymbol("partsupp")));
    PROFILE(87, pfnColumnValue(t184, t183, LiteralSymbol("ps_partkey")));
    PROFILE(88, pfnColumnValue(t185, t183, LiteralSymbol("ps_suppkey")));
    PROFILE(89, pfnColumnValue(t187, t183, LiteralSymbol("ps_supplycost")));
    PROFILE(90, pfnFetch(t189, t184));
    PROFILE(91, pfnList(t190, 2, (V []){t180, t171}));
    PROFILE(92, pfnList(t191, 2, (V []){t187, t189}));
    PROFILE(93, pfnJoinIndex(t192, t190, t191, LiteralSymbol((S)"eq")));
    PROFILE(94, pfnIndex(t193, t192, LiteralI64(0)));
    PROFILE(95, pfnIndex(t194, t192, LiteralI64(1)));
    PROFILE(96, pfnIndex(t195, t171, t193));
    PROFILE(97, pfnIndex(t197, t173, t193));
    PROFILE(98, pfnFetch(t208, t185));
    PROFILE(99, pfnIndex(t209, t208, t194));
    PROFILE(100, pfnJoinIndex(t213, t44, t209, LiteralSymbol((S)"eq")));
    PROFILE(101, pfnIndex(t214, t213, LiteralI64(0)));
    PROFILE(102, pfnIndex(t215, t213, LiteralI64(1)));
    PROFILE(103, pfnIndex(t220, t41, t214));
    PROFILE(104, pfnIndex(t224, t45, t214));
    PROFILE(105, pfnIndex(t225, t46, t214));
    PROFILE(106, pfnIndex(t227, t48, t214));
    PROFILE(107, pfnIndex(t228, t49, t214));
    PROFILE(108, pfnIndex(t229, t50, t214));
    PROFILE(109, pfnIndex(t230, t195, t215));
    PROFILE(110, pfnIndex(t232, t197, t215));
    PROFILE(111, pfnList(t247, 4, (V []){t228, t220, t224, t230}));
    PROFILE(112, pfnOrderBy(t248, t247, LiteralVectorBool(4, (B []){0, 1, 1, 1})));
    PROFILE(113, pfnIndex(t249, t228, t248));
    PROFILE(114, pfnIndex(t250, t224, t248));
    PROFILE(115, pfnIndex(t251, t220, t248));
    PROFILE(116, pfnIndex(t252, t230, t248));
    PROFILE(117, pfnIndex(t253, t232, t248));
    PROFILE(118, pfnIndex(t254, t225, t248));
    PROFILE(119, pfnIndex(t255, t227, t248));
    PROFILE(120, pfnIndex(t256, t229, t248));
    PROFILE(121, copyV(t257,LiteralVectorSymbol(8, (S []){"s_acctbal", "s_name", "n_name", "p_partkey", "p_mfgr", "s_address", "s_phone", "s_comment"})));
    PROFILE(122, pfnList(t258, 8, (V []){t249, t250, t251, t252, t253, t254, t255, t256}));
    PROFILE(123, pfnTable(t259, t257, t258));
    h_rtn[0] = t259;
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

// Compiling time (ms): 3.003
