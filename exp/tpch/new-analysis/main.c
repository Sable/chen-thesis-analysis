#include "global.h"
#include <math.h>
#include "header.h"
// #include "gencode.h" 

V buffV[MAX_V];
I buffS = 0;
extern L CSV_FILE_SCALE;
extern E horse_entry();



B MEMBER_CONST(S s, V x){
    DOI(xn, if(s[0]==vS(x,i)[0] && !strcmp(s,vS(x,i)))R 1) R 0;
}

B MEMBER_CONST_Q(Q id, V x){
    DOI(xn, if(id == vQ(x,i))R 1) R 0;
}

V incV(){
    if(buffS < MAX_V) return buffV[buffS++];
    else EP("Buff not available: %d\n", buffS);
}

#define LiteralSingle(T,t) {V z=incV(); initV(z, H_##T, 1); v##t(z)=x; R z;}
V LiteralBool(B x) { LiteralSingle(B, b); }
V LiteralI8  (J x) { LiteralSingle(J, j); }
V LiteralI16 (H x) { LiteralSingle(H, h); }
V LiteralI32 (I x) { LiteralSingle(I, i); }
V LiteralI64 (L x) { LiteralSingle(L, l); }
V LiteralF32 (F x) { LiteralSingle(F, f); }
V LiteralF64 (E x) { LiteralSingle(E, e); }
V LiteralDate(L x) { LiteralSingle(D, d); }
V LiteralChar(C x) { LiteralSingle(C, c); }
V LiteralSymbol(S s) {Q x=getSymbol(s); LiteralSingle(Q, q);}

#define LiteralVector(T) {V z=incV(); initV(z, H_##T, n); DOI(n, v##T(z,i)=x[i]) R z;}
V LiteralVectorBool(I n, B *x) { LiteralVector(B); }
V LiteralVectorI8  (I n, J *x) { LiteralVector(J); }
V LiteralVectorI16 (I n, H *x) { LiteralVector(H); }
V LiteralVectorI32 (I n, I *x) { LiteralVector(I); }
V LiteralVectorI64 (I n, L *x) { LiteralVector(L); }
V LiteralVectorF32 (I n, F *x) { LiteralVector(F); }
V LiteralVectorF64 (I n, E *x) { LiteralVector(E); }
V LiteralVectorDate(I n, L *x) { LiteralVector(D); }
V LiteralVectorString(I n, S *x) { LiteralVector(S); }

#define LiteralVectorDO(T,x) {V z=incV(); initV(z, H_##T, n); DOI(n, v##T(z,i)=x) R z;}
V LiteralVectorSymbol(I n, S *s) { LiteralVectorDO(Q,getSymbol(s[i])); }



static void initTPCHQuery(I id){
    initBackend();
    initTablesByQid(id);
    DOI(MAX_V, buffV[i]=allocNode())
}

static void clearRun(L cur){
    setHeapOffset(cur);
    time_clear();
}

static void run(I id, I n){
    initTPCHQuery(id);
    I offset = 5;
    I n2 = n + offset;
    E *record=(E*)malloc(sizeof(E)*n2), total=0;
    L cur = getHeapOffset();
    DOI(n2, {clearRun(cur); record[i]=horse_entry();})
    DOI(n, total += record[i+offset])
    P("q%02d>> Run with %d times, last %d average (ms): %g |",id,n2,n,total/n);
    DOI(n2, P(" %g",record[i])) P("\n");
    free(record);
}

static I getId(S str){
    I len=strlen(str), x=len-1;
    while(x>=0 && str[x]!='q') x--;
    if(x>=0)
        return atoi(str+x+1);
    else {
        EP("Not a valid executable: %s, but horse-compile-q<id> is expected", str);
    }
}

int main(int argc, char** argv){
    if(argc!=3){
        printf("[Usage]: %s <scale> <run>\n",argv[0]);
        exit(1);
    }
    I id    = getId(argv[0]);
    L scale = atoi(argv[1]);
    I n     = atoi(argv[2]);
    if(n<0){ EP("[run]: must be >=0"); }
    if(scale != 1 && scale != 2 && scale!=4 && scale!=8 && scale!=16) {
        EP("scale must be one of 1/2/4/8/16");
    }
    CSV_FILE_SCALE = scale;
    run(id, n);
    return 0;
}

