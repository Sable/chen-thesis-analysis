// Parsing time (ms): 0.535
static I horse_main(V *h_rtn);
static I q16_patterncompress_1(V *z, V x, V *y);
static I q16_peephole_fp4_0(V z, V x, V y);

static I q16_patterncompress_1(V *z, V x, V *y){
    V z0 = z[0]; // t73
    V z1 = z[1]; // t74
    V z2 = z[2]; // t75
    V z3 = z[3]; // t80
    V y0 = y[0]; // t55
    V y1 = y[1]; // t56
    V y2 = y[2]; // t57
    V y3 = y[3]; // t64
    L len = vn(x), k = 0;
    L lenZ = 0, parZ[H_CORE], offset[H_CORE];
    DOI(H_CORE, parZ[i]=offset[i]=0)
    CHECKE(getNumOfNonZero(x,parZ));
    DOI(H_CORE, lenZ += parZ[i])
    DOIa(H_CORE, offset[i]=parZ[i-1]+offset[i-1])
    initV(z0,H_Q,lenZ);
    initV(z1,H_Q,lenZ);
    initV(z2,H_I,lenZ);
    initV(z3,H_I,lenZ);
    DOT(len, if(vB(x,i)){L c=offset[tid]++;\
        vQ(z0,c) = vQ(y0,i);\
        vQ(z1,c) = vQ(y1,i);\
        vI(z2,c) = vI(y2,i);\
        vI(z3,c) = vI(y3,i);\
    })
    R 0;
}

static I q16_peephole_fp4_0(V z, V x, V y){
    // z -> t94, x -> t80, y -> t87
    L r0 = vn(y);
    initV(z, H_L, r0);
    DOP(r0, {V t=vV(y,i); L len=vn(t); L tot=0; B f[199]={0};\
        DOJ(len, if(!f[j]){ \
        DOK(len, if(k!=j && vI(x,vL(t,j))==vI(x,vL(t,k))) f[k]=1)\
        f[j]=1; tot++;}) vL(z,i)=tot; }) R 0;
}


static I horse_main(V *h_rtn){
    V t100 = incV(); V t98 = incV(); V t101 = incV(); V t99 = incV(); 
    V t102 = incV(); V t103 = incV(); V t0 = incV(); V t1 = incV(); 
    V t7 = incV(); V t8 = incV(); V t9 = incV(); V t20 = incV(); 
    V t21 = incV(); V t30 = incV(); V t22 = incV(); V t31 = incV(); 
    V t32 = incV(); V t16 = incV(); V t50 = incV(); V t42 = incV(); 
    V t26 = incV(); V t51 = incV(); V t43 = incV(); V t27 = incV(); 
    V t44 = incV(); V t28 = incV(); V t29 = incV(); V t63 = incV(); 
    V t55 = incV(); V t80 = incV(); V t64 = incV(); V t56 = incV(); 
    V t48 = incV(); V t73 = incV(); V t57 = incV(); V t49 = incV(); 
    V t90 = incV(); V t74 = incV(); V t91 = incV(); V t75 = incV(); 
    V t92 = incV(); V t84 = incV(); V t68 = incV(); V t93 = incV(); 
    V t85 = incV(); V t69 = incV(); V t94 = incV(); V t86 = incV(); 
    V t95 = incV(); V t87 = incV(); V t96 = incV(); V t88 = incV(); 
    V t97 = incV(); V t89 = incV(); 
    V tempV[10]; // temporary return vars
    PROFILE(4, pfnLoadTable(t0, LiteralSymbol("supplier")));
    PROFILE(5, pfnColumnValue(t1, t0, LiteralSymbol("s_suppkey")));
    PROFILE(6, pfnColumnValue(t7, t0, LiteralSymbol("s_comment")));
    PROFILE(7, pfnLike2(t8, t7, LiteralSymbol("%Customer%Complaints%")));
    PROFILE(8, pfnCompress(t9, t8, t1));
    PROFILE(9, pfnLoadTable(t16, LiteralSymbol("part")));
    PROFILE(10, pfnColumnValue(t20, t16, LiteralSymbol("p_brand")));
    PROFILE(11, pfnColumnValue(t21, t16, LiteralSymbol("p_type")));
    PROFILE(12, pfnColumnValue(t22, t16, LiteralSymbol("p_size")));
    PROFILE(13, copyV(t26,LiteralVectorI32(8, (I []){49, 14, 23, 45, 19, 3, 36, 9})));
    PROFILE(14, pfnMember(t27, t22, t26));
    PROFILE(15, pfnNeq(t28, t20, LiteralSymbol("Brand#45")));
    PROFILE(16, pfnLike2(t29, t21, LiteralSymbol("MEDIUM POLISHED%")));
    PROFILE(17, pfnNot(t30, t29));
    PROFILE(18, pfnAnd(t31, t27, t28));
    PROFILE(19, pfnAnd(t32, t31, t30));
    PROFILE(20, pfnLoadTable(t42, LiteralSymbol("partsupp")));
    PROFILE(21, pfnColumnValue(t43, t42, LiteralSymbol("ps_partkey")));
    PROFILE(22, pfnColumnValue(t44, t42, LiteralSymbol("ps_suppkey")));
    PROFILE(23, pfnValues(t48, t43));
    PROFILE(24, pfnIndex(t49, t32, t48));
    PROFILE(25, pfnCompress(t50, t49, t48));
    PROFILE(26, pfnWhere(t51, t49));
    PROFILE(27, pfnIndex(t55, t20, t50));
    PROFILE(28, pfnIndex(t56, t21, t50));
    PROFILE(29, pfnIndex(t57, t22, t50));
    PROFILE(30, pfnFetch(t63, t44));
    PROFILE(31, pfnIndex(t64, t63, t51));
    PROFILE(32, pfnMember(t68, t64, t9));
    PROFILE(33, pfnNot(t69, t68));
    PROFILE(37, q16_patterncompress_1((V []){t73, t74, t75, t80}, t69, (V []){t55, t56, t57, t64}));
    PROFILE(38, pfnList(t84, 3, (V []){t73, t74, t75}));
    PROFILE(39, pfnGroup(t85, t84));
    PROFILE(40, pfnKeys(t86, t85));
    PROFILE(41, pfnValues(t87, t85));
    PROFILE(42, pfnIndex(t88, t73, t86));
    PROFILE(43, pfnIndex(t89, t74, t86));
    PROFILE(44, pfnIndex(t90, t75, t86));
    PROFILE(48, q16_peephole_fp4_0(t94,t80,t87));
    PROFILE(49, pfnList(t95, 4, (V []){t94, t88, t89, t90}));
    PROFILE(50, pfnOrderBy(t96, t95, LiteralVectorBool(4, (B []){0, 1, 1, 1})));
    PROFILE(51, pfnIndex(t97, t88, t96));
    PROFILE(52, pfnIndex(t98, t89, t96));
    PROFILE(53, pfnIndex(t99, t90, t96));
    PROFILE(54, pfnIndex(t100, t94, t96));
    PROFILE(55, copyV(t101,LiteralVectorSymbol(4, (S []){"p_brand", "p_type", "p_size", "supplier_cnt"})));
    PROFILE(56, pfnList(t102, 4, (V []){t97, t98, t99, t100}));
    PROFILE(57, pfnTable(t103, t101, t102));
    h_rtn[0] = t103;
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

// Compiling time (ms): 0.899
