#!/bin/bash

export OMP_NUM_THREADS=16

div=50
num_th=32

while [ "$div" -lt 10500 ]
do
   ./exe $num_th $div
   div=`expr $div "*" 2`
done
