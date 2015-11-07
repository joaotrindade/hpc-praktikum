#!/bin/bash

gcc -g -O0 -fopenmp -c -o timer.o timer.c
gcc -g -O0 -fopenmp -c -o dgemm.o dgemm.c
gcc -g -fopenmp -o sequential.out dgemm.o timer.o

export OMP_NUM_THREADS=2

prblm_size=20
while [ "$prblm_size" -lt 2001 ]
do
   prblm_size=`expr $prblm_size + 20 `
   ./sequential.out $prblm_size
done
