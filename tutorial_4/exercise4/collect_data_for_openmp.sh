#!/bin/bash

prblm_size=1000
block_size=16
num_th=2
while [ "$num_th" -lt 35 ]
do
   export OMP_NUM_THREADS=$num_th
   perf stat -e instructions,cache-misses,branch-misses,page-faults,cpu-migrations,stalled-cycles-frontend,stalled-cycles-backend,L1-dcache-load-misses,L1-dcache-prefetch-misses,LLC-prefetch-misses,dTLB-load-misses,branch-load-misses ./openmp_app $prblm_size $block_size
   num_th=`expr $num_th "*" 2 `
   prblm_size=`expr $prblm_size "*" 2 `
done
