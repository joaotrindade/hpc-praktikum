#!/bin/bash
source /etc/profile.d/modules.sh
export OMP_NUM_THREADS=22
#cd $HOME/hpc-praktikum/tutorial_3/exercise3
#salloc --ntasks=80


echo -e "\nserial time for ngrid_points_per_dimension=1250:" >> performance_analysis.txt
./serial_app 1250 1000 0.0001
echo -e "\ngrid_points_per_dimension=1250:" >> performance_analysis.txt
mpirun -np 20 ./mpi_app 1250 1000 0.0001 5 4
mpirun -np 81 ./mpi_app 1250 1000 0.0001 9 9
mpirun -np 289 ./mpi_app 1250 1000 0.0001 17 17




