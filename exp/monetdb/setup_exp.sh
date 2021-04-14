#!/usr/bin/env bash
#source /mnt/local/script-tpch/runtest (sable-intel)

# tpch_dir="../tpch_2_17_0/monetdb"   # format: <number>.sql
tpch_dir="${HORSE_TPCH_SQL}"          # format: q<number>.sql

testsql(){
    echo "-- Testing query $1"
    for i in {1..5}
    do
        cat "${tpch_dir}/q$1.sql"
    done
    echo "call sys.querylog_empty();"
    echo "call sys.querylog_enable();"
    for i in {1..10}
    do
        cat "${tpch_dir}/q$1.sql"
    done
    echo "call sys.querylog_disable();"
    echo "select * from sys.querylog_history;"
    echo "select run/1000 as query_time from sys.querylog_history where query like '%select%';"
    echo "select avg(run)/1000 as avg_query$1, stddev_samp(run/1000) as std_query$1 from sys.querylog_history where query like '%select%';"
}

set_partial_query(){
    #query=(1 3 4 6 14 16 17 18 19 22)
    query=(11)
}

set_dls18_query(){
    query=(1 4 6 12 14 16 19 22)
}

set_full_query(){
    query=$(seq 1 22)
}

if [ "$#" -eq 1 ]; then
    cmd=$1
    if [ $cmd = "partial" ]; then
        set_partial_query
    elif [ $cmd = "dls18" -o $cmd = "cc20" ]; then
        set_dls18_query
    else
        set_full_query
    fi
else
    set_full_query
fi

## run
for id in ${query[@]}
do
    testsql $id
done
