#!/bin/bash
source /etc/profile.d/modules.sh
export OMP_NUM_THREADS=22

prblm_size=1000
while [ "$prblm_size" -lt 5010 ]
do
   perf stat -e cache-misses,L1-dcache-load-misses,LLC-load-misses,dTLB-load-misses  ./naive_app $prblm_size
   perf stat -e cache-misses,L1-dcache-load-misses,LLC-load-misses,dTLB-load-misses  ./optimized_app $prblm_size
   prblm_size=`expr $prblm_size + 1000 `
done
