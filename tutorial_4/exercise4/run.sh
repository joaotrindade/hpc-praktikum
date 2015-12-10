#!/bin/bash
source /etc/profile.d/modules.sh
export OMP_NUM_THREADS=22
#cd $HOME/hpc-praktikum/tutorial_3/exercise3
salloc --partition=bdz --ntasks=400
#mpirun -np 196 ./mpi_app 2000 1000 0.0001 14 14
#mpirun -np 196 ./mpi_app 2000 1000 0.0001 14 14
