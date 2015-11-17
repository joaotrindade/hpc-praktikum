#!/bin/bash

prblm_size=100000000
nprocesses=2
while [ "$nprocesses" -lt 28 ]
do
    nprocesses=`expr $nprocesses + 2 `	
    mpirun -np $nprocesses ./broadcast.o $prblm_size
done
