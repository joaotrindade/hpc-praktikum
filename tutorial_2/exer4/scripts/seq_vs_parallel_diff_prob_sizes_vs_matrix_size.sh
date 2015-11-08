#!/bin/bash

gcc -g -O0 -fopenmp -c -o timer.o timer.c
gcc -g -O0 -fopenmp -c -o dgemm.o sequential_dgemm.c
gcc -g -fopenmp -o sequential.out dgemm.o timer.o
gcc -g -O0 -fopenmp -c -o parallelize_dgemm.o parallelize_dgemm.c
gcc -g -fopenmp -o parallelize.out parallelize_dgemm.o timer.o

export OMP_NUM_THREADS=8

prblm_size=10
block_size=8

while [ "$prblm_size" -lt 1500 ]
do
   prblm_size=`expr $prblm_size + 50 `
   ./sequential.out $prblm_size
   ./parallelize.out $prblm_size $block_size
done
