#!/bin/bash

gcc -g -O0 -fopenmp -c -o timer.o timer.c
gcc -g -O0 -fopenmp -c -o dgemm.o sequential_dgemm.c
gcc -g -fopenmp -o sequential.out dgemm.o timer.o
gcc -g -O0 -fopenmp -c -o parallelize_dgemm.o parallelize_dgemm.c
gcc -g -fopenmp -o parallelize.out parallelize_dgemm.o timer.o


export OMP_NUM_THREADS=20

prblm_size=100
block_size=16

while [ "$prblm_size" -lt 1050 ]
do
   ./parallelize.out $prblm_size $block_size
   prblm_size=`expr $prblm_size + 100`
done
