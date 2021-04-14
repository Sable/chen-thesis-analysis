// Parsing time (ms): 0.877
static I horse_main(V *h_rtn);
static I q10_patterncompress_1(V *z, V x, V *y);
static I q10_peephole_fp1_0(V z, V x, V y);

static I q10_patterncompress_1(V *z, V x, V *y){
    V z0 = z[0]; // t117
    V z1 = z[1]; // t106
    V z2 = z[2]; // t107
    V y0 = y[0]; // t101
    V y1 = y[1]; // t89
    V y2 = y[2]; // t90
    L len = vn(x), k = 0;
    L lenZ = 0, parZ[H_CORE], offset[H_CORE];
    DOI(H_CORE, parZ[i]=offset[i]=0)
    CHECKE(getNumOfNonZero(x,parZ));
    DOI(H_CORE, lenZ += parZ[i])
    DOIa(H_CORE, offset[i]=parZ[i-1]+offset[i-1])
    initV(z0,H_I,lenZ);
    initV(z1,H_E,lenZ);
    initV(z2,H_E,lenZ);
    DOT(len, if(vB(x,i)){L c=offset[tid]++;\
        vI(z0,c) = vI(y0,i);\
        vE(z1,c) = vE(y1,i);\
        vE(z2,c) = vE(y2,i);\
    })
    R 0;
}

static I q10_peephole_fp1_0(V z, V x, V y){
    // z -> t173
    initV(z, H_E, vn(y));
    DOP(vn(y), {E a=0; V t=vV(y,i); DOJ(vn(t), a+=vE(x,vL(t,j))) vE(z,i)=a;}) R 0;
}


static I horse_main(V *h_rtn){
    V t100 = incV(); V t101 = incV(); V t120 = incV(); V t122 = incV(); 
    V t106 = incV(); V t107 = incV(); V t141 = incV(); V t117 = incV(); 
    V t134 = incV(); V t118 = incV(); V t135 = incV(); V t119 = incV(); 
    V t160 = incV(); V t136 = incV(); V t161 = incV(); V t170 = incV(); 
    V t162 = incV(); V t138 = incV(); V t171 = incV(); V t163 = incV(); 
    V t147 = incV(); V t139 = incV(); V t180 = incV(); V t172 = incV(); 
    V t164 = incV(); V t148 = incV(); V t181 = incV(); V t173 = incV(); 
    V t165 = incV(); V t182 = incV(); V t174 = incV(); V t166 = incV(); 
    V t158 = incV(); V t183 = incV(); V t175 = incV(); V t167 = incV(); 
    V t159 = incV(); V t184 = incV(); V t176 = incV(); V t168 = incV(); 
    V t185 = incV(); V t177 = incV(); V t169 = incV(); V t186 = incV(); 
    V t178 = incV(); V t179 = incV(); V t0 = incV(); V t1 = incV(); 
    V t2 = incV(); V t5 = incV(); V t6 = incV(); V t7 = incV(); 
    V t10 = incV(); V t30 = incV(); V t31 = incV(); V t15 = incV(); 
    V t32 = incV(); V t16 = incV(); V t33 = incV(); V t17 = incV(); 
    V t50 = incV(); V t51 = incV(); V t35 = incV(); V t27 = incV(); 
    V t52 = incV(); V t36 = incV(); V t28 = incV(); V t61 = incV(); 
    V t53 = incV(); V t37 = incV(); V t29 = incV(); V t54 = incV(); 
    V t38 = incV(); V t39 = incV(); V t80 = incV(); V t56 = incV(); 
    V t48 = incV(); V t65 = incV(); V t57 = incV(); V t49 = incV(); 
    V t90 = incV(); V t82 = incV(); V t58 = incV(); V t83 = incV(); 
    V t75 = incV(); V t59 = incV(); V t92 = incV(); V t84 = incV(); 
    V t76 = incV(); V t77 = incV(); V t79 = incV(); V t89 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("nation")));
    PROFILE(5, pfnColumnValue(t1, t0, LiteralSymbol("n_nationkey")));
    PROFILE(6, pfnColumnValue(t2, t0, LiteralSymbol("n_name")));
    PROFILE(7, pfnLoadTable(t5, LiteralSymbol("orders")));
    PROFILE(8, pfnColumnValue(t6, t5, LiteralSymbol("o_orderkey")));
    PROFILE(9, pfnColumnValue(t7, t5, LiteralSymbol("o_custkey")));
    PROFILE(10, pfnColumnValue(t10, t5, LiteralSymbol("o_orderdate")));
    PROFILE(11, pfnGeq(t15, t10, LiteralDate(19931001)));
    PROFILE(12, pfnLt(t16, t10, LiteralDate(19940101)));
    PROFILE(13, pfnAnd(t17, t15, t16));
    PROFILE(14, pfnLoadTable(t27, LiteralSymbol("customer")));
    PROFILE(15, pfnColumnValue(t28, t27, LiteralSymbol("c_custkey")));
    PROFILE(16, pfnColumnValue(t29, t27, LiteralSymbol("c_name")));
    PROFILE(17, pfnColumnValue(t30, t27, LiteralSymbol("c_address")));
    PROFILE(18, pfnColumnValue(t31, t27, LiteralSymbol("c_nationkey")));
    PROFILE(19, pfnColumnValue(t32, t27, LiteralSymbol("c_phone")));
    PROFILE(20, pfnColumnValue(t33, t27, LiteralSymbol("c_acctbal")));
    PROFILE(21, pfnColumnValue(t35, t27, LiteralSymbol("c_comment")));
    PROFILE(22, pfnValues(t36, t7));
    PROFILE(23, pfnCompress(t37, t17, t36));
    PROFILE(24, pfnWhere(t38, t17));
    PROFILE(25, pfnIndex(t39, t6, t38));
    PROFILE(26, pfnIndex(t48, t28, t37));
    PROFILE(27, pfnIndex(t49, t29, t37));
    PROFILE(28, pfnIndex(t50, t30, t37));
    PROFILE(29, pfnFetch(t51, t31));
    PROFILE(30, pfnIndex(t52, t51, t37));
    PROFILE(31, pfnIndex(t53, t32, t37));
    PROFILE(32, pfnIndex(t54, t33, t37));
    PROFILE(33, pfnIndex(t56, t35, t37));
    PROFILE(34, pfnJoinIndex(t57, t1, t52, LiteralSymbol((S)"eq")));
    PROFILE(35, pfnIndex(t58, t57, LiteralI64(0)));
    PROFILE(36, pfnIndex(t59, t57, LiteralI64(1)));
    PROFILE(37, pfnIndex(t61, t2, t58));
    PROFILE(38, pfnIndex(t65, t39, t59));
    PROFILE(39, pfnIndex(t75, t48, t59));
    PROFILE(40, pfnIndex(t76, t49, t59));
    PROFILE(41, pfnIndex(t77, t50, t59));
    PROFILE(42, pfnIndex(t79, t53, t59));
    PROFILE(43, pfnIndex(t80, t54, t59));
    PROFILE(44, pfnIndex(t82, t56, t59));
    PROFILE(45, pfnLoadTable(t83, LiteralSymbol("lineitem")));
    PROFILE(46, pfnColumnValue(t84, t83, LiteralSymbol("l_orderkey")));
    PROFILE(47, pfnColumnValue(t89, t83, LiteralSymbol("l_extendedprice")));
    PROFILE(48, pfnColumnValue(t90, t83, LiteralSymbol("l_discount")));
    PROFILE(49, pfnColumnValue(t92, t83, LiteralSymbol("l_returnflag")));
    PROFILE(50, pfnEq(t100, t92, LiteralChar('R')));
    PROFILE(51, pfnFetch(t101, t84));
    PROFILE(55, q10_patterncompress_1((V []){t117, t106, t107}, t100, (V []){t101, t89, t90}));
    PROFILE(57, pfnJoinIndex(t118, t65, t117, LiteralSymbol((S)"eq")));
    PROFILE(58, pfnIndex(t119, t118, LiteralI64(0)));
    PROFILE(59, pfnIndex(t120, t118, LiteralI64(1)));
    PROFILE(60, pfnIndex(t122, t61, t119));
    PROFILE(61, pfnIndex(t134, t75, t119));
    PROFILE(62, pfnIndex(t135, t76, t119));
    PROFILE(63, pfnIndex(t136, t77, t119));
    PROFILE(64, pfnIndex(t138, t79, t119));
    PROFILE(65, pfnIndex(t139, t80, t119));
    PROFILE(66, pfnIndex(t141, t82, t119));
    PROFILE(67, pfnIndex(t147, t106, t120));
    PROFILE(68, pfnIndex(t148, t107, t120));
    PROFILE(69, pfnMinus(t158, LiteralI32(1), t148));
    PROFILE(70, pfnMul(t159, t147, t158));
    PROFILE(71, pfnList(t160, 7, (V []){t134, t135, t139, t138, t122, t136, t141}));
    PROFILE(72, pfnGroup(t161, t160));
    PROFILE(73, pfnKeys(t162, t161));
    PROFILE(74, pfnValues(t163, t161));
    PROFILE(75, pfnIndex(t164, t134, t162));
    PROFILE(76, pfnIndex(t165, t135, t162));
    PROFILE(77, pfnIndex(t166, t139, t162));
    PROFILE(78, pfnIndex(t167, t138, t162));
    PROFILE(79, pfnIndex(t168, t122, t162));
    PROFILE(80, pfnIndex(t169, t136, t162));
    PROFILE(81, pfnIndex(t170, t141, t162));
    PROFILE(84, q10_peephole_fp1_0(t173,t159,t163));
    PROFILE(85, pfnList(t174, 1, (V []){t173}));
    PROFILE(86, pfnOrderBy(t175, t174, LiteralBool(0)));
    PROFILE(87, pfnIndex(t176, t164, t175));
    PROFILE(88, pfnIndex(t177, t165, t175));
    PROFILE(89, pfnIndex(t178, t173, t175));
    PROFILE(90, pfnIndex(t179, t166, t175));
    PROFILE(91, pfnIndex(t180, t168, t175));
    PROFILE(92, pfnIndex(t181, t169, t175));
    PROFILE(93, pfnIndex(t182, t167, t175));
    PROFILE(94, pfnIndex(t183, t170, t175));
    PROFILE(95, copyV(t184,LiteralVectorSymbol(8, (S []){"c_custkey", "c_name", "revenue", "c_acctbal", "n_name", "c_address", "c_phone", "c_comment"})));
    PROFILE(96, pfnList(t185, 8, (V []){t176, t177, t178, t179, t180, t181, t182, t183}));
    PROFILE(97, pfnTable(t186, t184, t185));
    h_rtn[0] = t186;
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

// Compiling time (ms): 1.744
