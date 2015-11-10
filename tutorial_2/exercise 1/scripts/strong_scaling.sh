#!/bin/bash

div=8000000
num_th=2

while [ "$num_th" -lt 35 ]
do
   export OMP_NUM_THREADS=$num_th
   ./exe $num_th $div
   num_th=`expr $num_th "+" 2 `
done
