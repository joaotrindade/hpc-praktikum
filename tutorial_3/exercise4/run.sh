#!/bin/bash
#source /etc/profile.d/modules.sh
#cd $HOME/hpc-praktikum/tutorial_3/exercise3
#salloc --ntasks=40
mpirun -np 16 ./mpi_app 10 100 0.0001 4 4
