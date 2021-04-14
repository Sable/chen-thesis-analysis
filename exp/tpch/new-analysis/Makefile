# Note:
# libhorse.a must be placed before libpcre2-8.a

# cccc = gcc-8
cccc = gcc-8
include_files = main.c 
include_dirs  = -I${HORSE_LIB_INCLUDE} -I${HORSE_SRC_CODE}
include_libs  = -L${HORSE_LIB_LIB} -lcore -lpcre2-8
include_flags = -O3 -std=c99 -fopenmp -lm -lstdc++ -march=native
include_flags_c = $(include_flags) $(avx1) $(avx2) # -v -ftime-report

include_flags_pgcc = -c99 -lm -lstdc++ -acc -ta=nvidia -mp -O4
report_pgcc = -Minfo=time  #-Minfo=accel

all: message

q%: main.o
	gcc-8 -o "compile-$@" \
    main.o callgen.c \
    $(include_dirs)    \
    $(include_libs)    \
    $(include_flags_c) \
    $(debug) $(report)

main.o: main.c
	gcc-8 -c main.c \
    ${include_flags_c} \
    ${include_dirs} \
    ${include_libs}

# q%:
# 	CUDA_HOME=/usr/local/cuda OMP_NUM_THREADS=1 \
# 	pgcc -o "compile-$@" \
#     $(include_files)   \
#     $(include_dirs)    \
#     $(include_libs)    \
#     $(include_flags_pgcc) \
#     $(debug) $(report_pgcc)

message:
	@echo "Please use ./make.sh"

