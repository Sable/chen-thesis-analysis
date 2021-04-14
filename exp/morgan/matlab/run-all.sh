#!/bin/bash
machine=`hostname`

if [ $machine = "sableintel" ]; then
    data_folder="data-intel"
elif [ $machine = "tigger" ]; then
    data_folder="data-tigger"
else
    echo "Unknown machine: ${machine}"
fi


usage(){
    printf '%s\n\n' \
         "Usage: $0 <cmd>" \
         "  1) $0 <runid>       ## run with an id" \
         "  2) $0 <runid> view  ## view result"
    exit 1
}

view_result(){
    cat ${log_matlab} | grep -i "The average elapsed time" | cut -d':' -f 2
}

run_main(){
    echo "Running MATLAB (logging to ${log_matlab}) ..."
    mkdir -p $log && rm -f ${log_matlab}
    matlab19="/usr/local/pkgs/matlab/R2019a/bin/matlab -nodesktop"
    runs=10
    scales=(1 2 4 8)
    for sf in "${scales[@]}"
    do
        echo "** Logging sf${sf} to ${log_matlab} **"
        ${matlab19} -batch "run('${data_folder}/in_${sf}M.txt', $runs)" >> ${log_matlab}
    done
    view_result
}

setup(){
    log="log/run$1"
    log_matlab="${log}/log_matlab.txt"
}

if [ $# -eq 1 ]; then
    setup $1
    run_main
elif [ $# -eq 2 ]; then
    if [ $2 = "view" ]; then
        setup $1
        view_result
    else
        usage
    fi
else
    usage
fi


## debug code
##   matlab19 -batch "run('data-intel/in_1M.txt', 1)"

