#!/bin/bash
source /etc/profile.d/modules.sh
export OMP_NUM_THREADS=22

gprof gauss.out gmon.out > LOG
#prblm_size=1000
#while [ "$prblm_size" -lt 5010 ]
#do
#   echo -e "\n problem size(naive algo) = $prblm_size"
#   echo -e "\n *****************************************************************************"
#   perf stat -e cache-misses,L1-dcache-load-misses,LLC-load-misses,dTLB-load-misses  ./naive_app $prblm_size

#   echo -e "\n Perf: problem size(optimized algo) = $prblm_size"
#   echo -e "\n *****************************************************************************"
#   perf stat -e cache-misses,L1-dcache-load-misses,LLC-load-misses,dTLB-load-misses  ./optimized_app $prblm_size

#   echo -e "\n valgrind: problem size(optimized algo) = $prblm_size"
#   echo -e "\n *****************************************************************************"
#   valgrind --tool=cachegrind ./optimized_app $prblm_size

#   prblm_size=`expr $prblm_size + 1000 `
#done
