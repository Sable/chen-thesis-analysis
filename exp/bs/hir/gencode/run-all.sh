#!/bin/bash

threads=40
runs=10
scales=(1 2 4 8)

usage(){
    printf '%s\n\n' \
        "Usage: $0 <cmd>" \
        "  1) $0 <runid>        ## run with an id" \
        "  2) $0 <runid> view   ## view result"
    exit 1
}

setenv(){
    log="log/run$1"
}

view_result(){
    echo "naive:"
    for sf in ${scales[@]}
    do
        cat ${log}/naive_sf${sf}_40.txt | grep -i "Run with" | cut -d':' -f 2 | cut -d'|' -f 1
    done
    echo "opt:"
    for sf in ${scales[@]}
    do
        cat ${log}/opt_sf${sf}_40.txt | grep -i "Run with" | cut -d':' -f 2 | cut -d'|' -f 1
    done
}

run_main(){
    mkdir -p ${log}

    echo "Building naive"
    ./make.sh 0 naive 1> /dev/null
    for sf in ${scales[@]}
    do
        log_file="${log}/naive_sf${sf}_${threads}.txt"
        echo "** Logging scale ${sf} ... save to ${log_file} **"
        ./run-query.sh 0 ${runs} ${threads} ${sf} &> ${log_file}
    done
    echo "Building opt"
    ./make.sh 0  opt 1> /dev/null
    for sf in ${scales[@]}
    do
        log_file="${log}/opt_sf${sf}_${threads}.txt"
        echo "** Logging scale ${sf} ... save to ${log_file} **"
        ./run-query.sh 0 ${runs} ${threads} ${sf} &> ${log_file}
    done
    view_result
    echo "done."
}

if [ $# -eq 1 ]; then
    setenv $1
    run_main
elif [ $# -eq 2 ]; then
    if [ $2 = "view" ]; then
        setenv $1
        view_result
    else
        usage
    fi
else
    usage
fi

