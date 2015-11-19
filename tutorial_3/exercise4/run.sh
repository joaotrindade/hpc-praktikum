#!/bin/bash
#source /etc/profile.d/modules.sh
cd $HOME/hpc-praktikum/tutorial_3/exercise3
salloc --ntasks=40
mpirun -np 32 ./broadcast.o 1000000
