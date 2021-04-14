#!/bin/bash

usage(){
    printf '%s\n\n' \
        "$0 <option>" \
        "  1) $0 <run_id>       ## specify a run id (both naive and opt)" \
        "  2) $0 <run_id> view  ## get or report compilation time" \
        "  3) $0 ls             ## show run IDs"
    exit 1 
}

error(){
    echo "[ERROR] $1"
    exit 99
}

set_env(){
    machine=`hostname`
    runs=10
    thread=40
    scales=(1 2 4 8)
}

# run_build_time(){
#     local log_file="${log_folder}/all_compile.txt"
#     echo "** Logging to ${log_file} **"
#     rm -f ${log_file}
#     for id in {1..22}
#     do
#         echo "Compiling q$id"
#         (set -x && time make q${id} sys=${machine} report="-ftime-report") &>> ${log_file}
#     done
# }

run_build(){
    local kind=$1
    local log_file="${log_folder}/build_log_${kind}.txt"
    rm -f ${log_file}
    echo "** Logging to ${log_file} **"
    ./make.sh ${kind} morgan &>> ${log_file}
}

run_main(){
    local kind=$1
    local log_file="${log_folder}/${kind}_sf_t${thread}.txt"
    echo "** Logging to ${log_file} **"
    rm -f ${log_file}
    for sf in ${scales[@]}
    do
        ./run-query.sh ${runs} ${thread} ${sf} &>> ${log_file}
    done
}

run_report(){
    local kind=$1
    local log_file="${log_folder}/${kind}_sf_t${thread}.txt"
    echo "Fetch execution time from ${log_file}"
    cat ${log_file} | grep "Run with" | cut -d'|' -f 1 | awk -F " " '{print $NF}'
}

run_one(){
    run_build  $1
    run_main   $1
    run_report $1
}

run_all(){
    run_one "naive"
    run_one "opt"
}

set_log(){
    log_folder="log/run$1"
}

need_log(){
    set_log $1 $2
    mkdir -p ${log_folder}
}

set_env
if [ $# -eq 1 ]; then
    if [ $1 = "ls" ]; then
        ls log
    else
        need_log $1
        time run_all
    fi
elif [ $# -eq 2 ]; then
    if [ $2 = "view" ]; then
        set_log $1
        run_report
    else
        usage
    fi
else
    usage
fi
