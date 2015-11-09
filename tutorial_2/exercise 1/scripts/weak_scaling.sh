#!/bin/bash

gcc -g -O0 -fopenmp -c -o timer.o timer.c
gcc -g -O0 -fopenmp -c -o dgemm.o sequential_dgemm.c
gcc -g -fopenmp -o sequential.out dgemm.o timer.o
gcc -g -O0 -fopenmp -c -o parallelize_dgemm.o parallelize_dgemm.c
gcc -g -fopenmp -o parallelize.out parallelize_dgemm.o timer.o


prblm_size=10
block_size=16
num_th=2
while [ "$prblm_size" -lt 1200 ]
do
   export OMP_NUM_THREADS=$num_th
   ./parallelize.out $prblm_size $block_size
   num_th=`expr $num_th "*" 2 `
   prblm_size=`expr $prblm_size "*" 2 `
done
