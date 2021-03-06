#ifndef __H_COMPILE__
#define __H_COMPILE__

#include <float.h>  // DBL_MAX

// #define NO_PROFILE_INFO

//#define PROFILE(c, n, stmt) P("Line: %d\n",c); V n = allocNode(); stmt
#ifdef NO_PROFILE_INFO
    #define PROFILE(c,stmt) stmt
#else
    #define PROFILE(c,stmt) { tic(); \
        I e=stmt; \
        if(e) printErrMsg(e); \
        E t0=calc_toc(); \
        if(t0>=0.1) P("[Profiling] Line %d: %g ms\n", c,t0); \
        else P("[Profiling] Line %d:\n", c); }
#endif

#define DOP_ACC(n, x, ...) {L i2=n; \
    _Pragma(STRINGIFY(acc parallel __VA_ARGS__)) \
    for(L i=0;i<i2;i++) x;}

#define MAX_DBL DBL_MAX
#define LIKE2Q(x,y) simpleLike2Q(x,y)

// optional in q19
#define MEMBER_CONST_Q2(id, x) (vQ(x,0)==(id)||vQ(x,1)==(id))

#define HORSE_UDF(c,stmt,cb) do{L cur=buffS; PROFILE(c,stmt); buffS=cur; cb;}while(0)

#define MAX_V 1000
extern V buffV[MAX_V];
extern I buffS;

B MEMBER_CONST(S s, V x);
B MEMBER_CONST_Q(Q id, V x);
V incV();

V LiteralBool(B x);
V LiteralI8  (J x);
V LiteralI16 (H x);
V LiteralI32 (I x);
V LiteralI64 (L x);
V LiteralF32 (F x);
V LiteralF64 (E x);
V LiteralDate(L x);
V LiteralChar(C x);
V LiteralSymbol(S s);

V LiteralVectorBool(I n, B *x);
V LiteralVectorI8  (I n, J *x);
V LiteralVectorI16 (I n, H *x);
V LiteralVectorI32 (I n, I *x);
V LiteralVectorI64 (I n, L *x);
V LiteralVectorF32 (I n, F *x);
V LiteralVectorF64 (I n, E *x);
V LiteralVectorDate(I n, L *x);
V LiteralVectorString(I n, S *x);
V LiteralVectorSymbol(I n, S *s);

#ifdef LT
#undef LT
#endif

#ifdef EQ
#undef EQ
#endif


#define AND(x,y) (x)&&(y)
#define OR(x,y)  (x)||(y)
#define GEQ(x,y) (x)>=(y)
#define LEQ(x,y) (x)<=(y)
#define LT(x,y)  (x)<(y)
#define GT(x,y)  (x)>(y)
#define EQ(x,y)  (x)==(y)
#define NEQ(x,y) (x)!=(y)

#define MUL(x,y)   (x)*(y)
#define DIV(x,y)   (x)/(y)
#define MINUS(x,y) (x)-(y)
#define PLUS(x,y)  (x)+(y)
#define NOT(x)     !(x)


// copy from pfnLike
#define LIKEMATCH(src,slen,re,matchData) \
    pcre2_jit_match(re,\
       (PCRE2_SPTR)src,\
        slen,0,PCRE2_ANCHORED|PCRE2_NO_UTF_CHECK,matchData,NULL\
    )<0?0:1


#define DOLIKE(n, x, ...){ L seg=(n)/H_CORE; \
    _Pragma(STRINGIFY(omp parallel __VA_ARGS__)) \
    { \
        pcre2_match_context *mcontext = pcre2_match_context_create(NULL); \
        pcre2_jit_stack *jit_stack = pcre2_jit_stack_create(1024*1024, 4096*1024, NULL);\
        pcre2_jit_stack_assign(mcontext, NULL, jit_stack);\
        pcre2_match_data *match = pcre2_match_data_create_from_pattern(re, NULL);\
        L tid = omp_get_thread_num(); \
        for(L i=tid*seg,i2=(tid!=H_CORE-1?(i+seg):(n));i<i2;i++) x; \
        pcre2_match_data_free(match); \
        pcre2_match_context_free(mcontext); \
        pcre2_jit_stack_free(jit_stack); \
    } \
}


#endif
