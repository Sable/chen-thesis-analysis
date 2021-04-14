#!/bin/bash
usage(){
    printf '%s\n\n' \
        "Usage: (default optimization: release)" \
        "  1) $0 <kind> <qid>                   ## kind: naive/opt/opt-fl/opt-fp" \
        "  2) $0 lib                            ## build libcore.a" \
        "  3) $0 code <naive/opt/opt-fl/opt-fp> ## compile to a folder" \
        "  4) $0 code all                       ## compile to naive/opt/opt-fl/opt-fp" \
        "  5) $0 test <naive/opt> <qid>         ## test a query: generating C code from hir" \
        "  6) $0 gen  <qid>                     ## compile lib + gen opt + save to opt/" \
        "  Note: default mykind=\"opt\", myavx=\"yes\""
    exit 1
}

# query_set=(1 4 6 12 14 16 19 22)
query_set=`seq 22`
#mykind="opt"
opt1="-o basic"
opt2="-o fp1 -o fa -o fp2"

# if [ -z ${opt} ]; then
#     opt="${opt2[@]}"
# fi

if [ -z ${mykind} ]; then
    mykind="opt"
fi

if [ -z ${myavx} ]; then
    myavx1=""
    myavx2=""
elif [ ${myavx} = "no"  ]; then
    myavx1="-mno-avx"
    myavx2="-mno-avx2"
else
    myavx1=""
    myavx2=""
fi

# HORSE_HYPER_HIR="/home/sable/hanfeng.c/github/branch-plan2ir/tests/hyper/work-hir"

compile_code(){
    kind=$1
    for id in ${query_set[@]}
    do
        echo "** [${kind}] Compiling query ${id} **"
        compile_single ${kind} ${id} > ${kind}/q${id}.h
    done
}

compile_single(){
    folder=$1 ; id=$2
    if [ ${folder} = "opt" ]; then
        ${HORSE_SRC_CODE}/build/horse -c cpu ${opt2} -f ${HORSE_HYPER_HIR}/q${id}.hir --tpch=${id}
    elif [ ${folder} = "naive" ]; then
        ${HORSE_SRC_CODE}/build/horse -c cpu -f ${HORSE_HYPER_HIR}/q${id}.hir --tpch=${id}
    elif [ ${folder} = "opt-fp" ]; then
        ${HORSE_SRC_CODE}/build/horse -c cpu -o basicfp -f ${HORSE_HYPER_HIR}/q${id}.hir --tpch=${id}
    elif [ ${folder} = "opt-fl" ]; then
        ${HORSE_SRC_CODE}/build/horse -c cpu -o fa -f ${HORSE_HYPER_HIR}/q${id}.hir --tpch=${id}
    else
        usage
    fi
}

gen_all_exp(){
    compile_code "naive"  2> /dev/null
    compile_code "opt"    2> /dev/null
    compile_code "opt-fp" 2> /dev/null
    compile_code "opt-fl" 2> /dev/null
}


sys=`hostname`
if [ "$#" -eq 1 ]; then
    if [ $1 = "lib" ]; then
        (set -x && cd ${HORSE_SRC_CODE} && ./make.sh lib)
    else
        usage
    fi
elif [ "$#" -eq 2 ]; then
    folder=$1 ; id=$2
    if [ $1 = "naive" -o $1 = "opt" -o $1 = "opt-fl" -o $1 = "opt-fp" ]; then
        (set -x && cp "${folder}/q${id}.h" gencode.h && make q${id} debug=${debug} avx1=${myavx1} avx2=${myavx2})
    elif [ $1 = "code" ]; then
        if [ $2 = "naive" -o $2 = "opt" -o $2 = "opt-fl" -o $2 = "opt-fp" ]; then
            compile_code $2 2> /dev/null
        elif [ $2 = "all" ]; then
            gen_all_exp
        else
            usage
        fi
    elif [ $1 = "gen" ]; then
        # mykind="opt-fl"
        mkdir -p /tmp/${mykind}
        (set -x && (cd ${HORSE_SRC_CODE} && ./make.sh debug) 1> /dev/null  && compile_single ${mykind} $2 > /tmp/${mykind}/q$2.h)
    else
        usage
    fi
elif [ "$#" -eq 3 ]; then
    if [ $1 = "test" ]; then
        (set -x && (cd ${HORSE_SRC_CODE} && ./make.sh debug) 1> /dev/null  && compile_single $2 $3)
    else
        usage
    fi
else
    usage
fi












