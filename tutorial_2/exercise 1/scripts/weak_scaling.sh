#!/bin/bash

div=10
num_th=2
while [ "$div" -lt 15000 ]
do
   export OMP_NUM_THREADS=$num_th
   ./exe $num_th $div
   num_th=`expr $num_th "*" 2 `
   div=`expr $div "*" 2 `
done
