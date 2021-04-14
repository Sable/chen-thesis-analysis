#include "global.h"
#include <math.h>

#define MAX_V 1000
static V buffV[MAX_V];
static I buffS = 0;
extern L CSV_FILE_SCALE;

#include "header.h"
#include "gencode.h" 

static void initMorgan(){
    initBackend();
    initTableByName((S)"morgan");
    DOI(MAX_V, buffV[i]=allocNode())
}

static void clearRun(L cur){
    setHeapOffset(cur);
    time_clear();
}

static void run(int n){
    initMorgan();
    I offset = 5;
    L n2 = n + offset;
    E *record=(E*)malloc(sizeof(E)*n2), total=0;
    L cur = getHeapOffset();
    DOI(n2, {clearRun(cur); record[i]=horse_entry();})
    DOI(n, total += record[i+offset])
    P("morgan>> Run with %lld times, last %d average (ms): %g |",n2,n,total/n);
    DOI(n2, P(" %g",record[i])) P("\n");
    free(record);
}

int main(int argc, char** argv){
    if(argc!=3){
        printf("[Usage]: %s <scale> <n>\n",argv[0]);
        exit(1);
    }
    L scale= atoi(argv[1]);
    int n  = atoi(argv[2]);
    if(n<0){ EP("[n]: must be >=0\n"); }
    if(scale != 1 && scale != 2 && scale!=4 && scale!=8) { EP("scale must be one of 1/2/4/8\n"); }
    CSV_FILE_SCALE = scale;
    run(n);
    return 0;
}

