#!/bin/bash

div=1000000
num_th=1
while [ "$num_th" -lt 35 ]
do
   export OMP_NUM_THREADS=$num_th
   ./exe $num_th $div
   num_th=`expr $num_th "*" 2 `
   div=`expr $div "*" 2 `
done
