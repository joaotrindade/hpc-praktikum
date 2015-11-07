#!/bin/bash

prblm_size=2000000000
nthreads=2
while [ "$nthreads" -lt 28 ]
do
   nthreads=`expr $nthreads + 2 `
   ./sequential.out $prblm_size $nthreads
done
