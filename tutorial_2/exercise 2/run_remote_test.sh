#!/bin/bash

export KMP_AFFINITY="granularity=core,explicit,proclist=[0,8,9,10,11,1,2,3],verbose"
./stream_omp_remote.o

