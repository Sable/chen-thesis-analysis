#!/bin/bash
usage(){
    printf '%s\n\n' \
        "Usage: (default optimization: release)" \
        "  1) $0 naive/opt morgan   ## create a query under naive or opt" \
        "  2) $0 lib                ## build libcore.a" \
        "  3) $0 code naive/opt     ## generate C code from HorseIR"
    exit 1
}

compile_horse(){
    echo "** Compiling horse **"
    (cd ${HORSE_SRC_CODE} && ./make.sh debug)
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
    if [ $1 = "naive" -o $1 = "opt" ]; then
        (set -x && cp "${folder}/${id}.h" gencode.h)
        (set -x && make ${id} sys=${sys})
    elif [ $1 = "code" ]; then
        if [ $2 = "naive" ]; then
            compile_horse 1> /dev/null && (set -x && ${HORSE_SRC_CODE}/build/horse -c cpu -f ../morgan.hir)
        elif [ $2 = "opt" ]; then
            compile_horse 1> /dev/null && (set -x && ${HORSE_SRC_CODE}/build/horse -c cpu -f ../morgan.hir -o fa)
        else
            usage
        fi
    else
        usage
    fi
else
    usage
fi

