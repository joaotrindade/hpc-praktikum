#!/bin/bash
source /etc/profile.d/modules.sh
export OMP_NUM_THREADS=22
#cd $HOME/hpc-praktikum/tutorial_3/exercise3
#salloc --ntasks=40
./serial_app 5000 1000 0.0001
#mpirun -np 64 ./mpi_app 1994 1000 0.0001 8 8
mpirun -np 64 ./mpi_app 5000 1000 0.0001 8 8
#mpirun -np 4 ./mpi_app 998 1000 0.0001 2 2

#mpirun -np 16 ./mpi_app 998 1000 0.0001 4 4
