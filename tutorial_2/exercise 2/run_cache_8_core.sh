#!/bin/bash
export OMP_NUM_THREADS=8
KMP_AFFINITY="granularity=thread,compact,1,0"
./stream_omp.o

export OMP_NUM_THREADS=8
KMP_AFFINITY="granularity=core,explicit,proclist=[0,1,2,3,8,9,10,11],verbose"
./stream_omp.o
