#!/bin/bash

prblm_size=1000
nprocesses=32
iterator=1
while [ "$iterator" -lt 6 ]
do
	iterator= `expr $iterator + 1 `	
    prblm_size=`expr $prblm_size \* 10 `	
    mpirun -np $nprocesses ./broadcast.o $prblm_size
done
