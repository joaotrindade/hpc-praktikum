#!/bin/bash

export KMP_AFFINITY="granularity=core,explicit,proclist=[0,1,2,3,8,9,10,11],verbose"
./stream_omp_remote.o

