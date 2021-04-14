#!/bin/bash
if [ -z ${mysf} ]; then
    mysf=1
fi
dbname=tpch${mysf}  #tpch1 / tpch1-no

usage(){
    printf '%s\n\n' \
        "  1. $0 <id> <kind>           # run with kind: all/dls18/cc20" \
        "  2. $0 <id> client <thread>  # run tests for one kind of threads" \
        "  3. $0 <id> report <thread>  # report execution time"
    exit 1
}

init_system(){
    machine=`hostname`
    if [ ${machine} = "sableintel" ]; then
        threads=(1 2 4 8 16 32 64)
    elif [ ${machine} = "tigger" ]; then
        threads=(1 2 4 8 16)
    else
        echo "Unsupported: ${machine}"
        exit 1
    fi
    sf_set=(1 2 4 8 16)
}

run_test(){
    local kind=$1
    port="50005"
    for sf in ${sf_set[@]}
    do
        local dbname="tpch${sf}"
        for th in ${threads[@]}
        do
            echo "Setup ${th} thread(s)"
            monetdb -p ${port} set nthreads=${th} ${dbname}
            monetdb -p ${port} start ${dbname}
            (time ./setup_exp.sh ${kind} | mclient -d ${dbname} -t performance &> ${folder}/sf${sf}_exp_t${th}.txt)
            monetdb -p ${port} stop ${dbname}
        done
    done
}

run_client(){
    (time ./setup_exp.sh "all" | mclient -d ${dbname} -t performance) &> ${folder}/exp_t${1}.txt
}

set_log(){
    folder=log/run$1
    log=${folder}/run-log.txt
    mkdir -p ${folder}
    rm -f ${log}
}

init_system
if [ $# -eq 2 ]; then
    if [ $2 = "all" ]; then
        set_log $1
        sf_set=(1)
        run_test $2 | tee ${log}
    elif [ $2 = "dls18" ]; then
        set_log $1
        # sf_set=(1)
        run_test $2 | tee ${log}
    elif [ $2="cc20" ]; then
        set_log $1
        sf_set=(1)
        run_test $2 | tee ${log}
    else
        usage
    fi
elif [ $# -eq 3 ]; then
    if [ $2 = "client" ]; then
        set_log $1
        run_client $3 | tee ${log}
    elif [ $2 = "report" ]; then
        (set -x && grep -A 3 avg_query log/run$1/sf${mysf}_exp_t$3.txt | python cut.py)
    else
        usage
    fi
else
    usage
fi


#time ./setup_exp.sh "partial" | mclient -d tpch1 -t performance



