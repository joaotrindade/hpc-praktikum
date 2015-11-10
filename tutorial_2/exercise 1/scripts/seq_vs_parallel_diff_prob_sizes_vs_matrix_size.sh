#!/bin/bash

export OMP_NUM_THREADS=16

div=100000
num_th=22

while [ "$div" -lt 4000000 ]
do
   ./exe $num_th $div
   div=`expr $div "*" 2`
done
