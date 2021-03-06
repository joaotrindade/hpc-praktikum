#!/bin/bash
source /etc/profile.d/modules.sh
export OMP_NUM_THREADS=22
#cd $HOME/hpc-praktikum/tutorial_3/exercise3
#salloc --ntasks=80


echo -e "\nserial time for ngrid_points_per_dimension=3000:" >> performance_analysis.txt
./serial_app 3000 1000 0.0001
echo -e "\ngrid_points_per_dimension=3000:" >> performance_analysis.txt
mpirun -np 1 ./mpi_app 3000 1000 0.0001 1 1
mpirun -np 2 ./mpi_app 3000 1000 0.0001 2 1
mpirun -np 4 ./mpi_app 3000 1000 0.0001 2 2
mpirun -np 9 ./mpi_app 3000 1000 0.0001 3 3
mpirun -np 16 ./mpi_app 3000 1000 0.0001 4 4
mpirun -np 20 ./mpi_app 3000 1000 0.0001 5 4
mpirun -np 36 ./mpi_app 3000 1000 0.0001 6 6
mpirun -np 49 ./mpi_app 3000 1000 0.0001 7 7
mpirun -np 81 ./mpi_app 3000 1000 0.0001 9 9
mpirun -np 169 ./mpi_app 3000 1000 0.0001 13 13
mpirun -np 289 ./mpi_app 3000 1000 0.0001 17 17




echo -e "\nserial time for ngrid_points_per_dimension=2000:" >> performance_analysis.txt
./serial_app 2000 1000 0.0001
echo -e "\ngrid_points_per_dimension=2000:" >> performance_analysis.txt
mpirun -np 1 ./mpi_app 2000 1000 0.0001 1 1
mpirun -np 2 ./mpi_app 2000 1000 0.0001 2 1
mpirun -np 4 ./mpi_app 2000 1000 0.0001 2 2
mpirun -np 9 ./mpi_app 2000 1000 0.0001 3 3
mpirun -np 16 ./mpi_app 2000 1000 0.0001 4 4
mpirun -np 20 ./mpi_app 2000 1000 0.0001 5 4
mpirun -np 36 ./mpi_app 2000 1000 0.0001 6 6
mpirun -np 49 ./mpi_app 2000 1000 0.0001 7 7
mpirun -np 81 ./mpi_app 2000 1000 0.0001 9 9
mpirun -np 169 ./mpi_app 2000 1000 0.0001 13 13
mpirun -np 289 ./mpi_app 2000 1000 0.0001 17 17



echo -e "\nserial time for ngrid_points_per_dimension=1250:" >> performance_analysis.txt
./serial_app 1250 1000 0.0001
echo -e "\ngrid_points_per_dimension=1250:" >> performance_analysis.txt
mpirun -np 1 ./mpi_app 1250 1000 0.0001 1 1
mpirun -np 2 ./mpi_app 1250 1000 0.0001 2 1
mpirun -np 4 ./mpi_app 1250 1000 0.0001 2 2
mpirun -np 9 ./mpi_app 1250 1000 0.0001 3 3
mpirun -np 16 ./mpi_app 1250 1000 0.0001 4 4
mpirun -np 20 ./mpi_app 1250 1000 0.0001 5 4
mpirun -np 36 ./mpi_app 1250 1000 0.0001 6 6
mpirun -np 49 ./mpi_app 1250 1000 0.0001 7 7
mpirun -np 81 ./mpi_app 1250 1000 0.0001 9 9
mpirun -np 169 ./mpi_app 1250 1000 0.0001 13 13
mpirun -np 289 ./mpi_app 1250 1000 0.0001 17 17


echo -e "\nserial time for ngrid_points_per_dimension=500:" >> performance_analysis.txt
./serial_app 500 1000 0.0001
echo -e "\ngrid_points_per_dimension=500:" >> performance_analysis.txt
mpirun -np 1 ./mpi_app 500 1000 0.0001 1 1
mpirun -np 2 ./mpi_app 500 1000 0.0001 2 1
mpirun -np 4 ./mpi_app 500 1000 0.0001 2 2
mpirun -np 9 ./mpi_app 500 1000 0.0001 3 3
mpirun -np 16 ./mpi_app 500 1000 0.0001 4 4
mpirun -np 20 ./mpi_app 500 1000 0.0001 5 4
mpirun -np 36 ./mpi_app 500 1000 0.0001 6 6 
mpirun -np 49 ./mpi_app 500 1000 0.0001 7 7
mpirun -np 81 ./mpi_app 500 1000 0.0001 9 9 
mpirun -np 169 ./mpi_app 500 1000 0.0001 13 13
mpirun -np 289 ./mpi_app 500 1000 0.0001 17 17


echo -e "\nserial time for ngrid_points_per_dimension=200:" >> performance_analysis.txt
./serial_app 200 1000 0.0001 
echo -e "\ngrid_points_per_dimension=200:" >> performance_analysis.txt
mpirun -np 1 ./mpi_app 200 1000 0.0001 1 1
mpirun -np 2 ./mpi_app 200 1000 0.0001 2 1
mpirun -np 4 ./mpi_app 200 1000 0.0001 2 2
mpirun -np 9 ./mpi_app 200 1000 0.0001 3 3
mpirun -np 16 ./mpi_app 200 1000 0.0001 4 4
mpirun -np 20 ./mpi_app 200 1000 0.0001 5 4
mpirun -np 36 ./mpi_app 200 1000 0.0001 6 6
mpirun -np 49 ./mpi_app 200 1000 0.0001 7 7
mpirun -np 81 ./mpi_app 200 1000 0.0001 9 9
mpirun -np 169 ./mpi_app 200 1000 0.0001 13 13
mpirun -np 289 ./mpi_app 200 1000 0.0001 17 17


echo -e "\nserial time for ngrid_points_per_dimension=100:" >> performance_analysis.txt
./serial_app 100 1000 0.0001
echo -e "\ngrid_points_per_dimension=100:" >> performance_analysis.txt
mpirun -np 1 ./mpi_app 100 1000 0.0001 1 1
mpirun -np 2 ./mpi_app 100 1000 0.0001 2 1
mpirun -np 4 ./mpi_app 100 1000 0.0001 2 2
mpirun -np 9 ./mpi_app 100 1000 0.0001 3 3
mpirun -np 16 ./mpi_app 100 1000 0.0001 4 4
mpirun -np 20 ./mpi_app 100 1000 0.0001 5 4
mpirun -np 36 ./mpi_app 100 1000 0.0001 6 6
mpirun -np 49 ./mpi_app 100 1000 0.0001 7 7
mpirun -np 81 ./mpi_app 100 1000 0.0001 9 9 
mpirun -np 169 ./mpi_app 100 1000 0.0001 13 13
mpirun -np 289 ./mpi_app 100 1000 0.0001 17 17



echo -e "\nserial time for ngrid_points_per_dimension=50:" >> performance_analysis.txt
./serial_app 50 1000 0.0001
echo -e "\ngrid_points_per_dimension=50:" >> performance_analysis.txt
mpirun -np 1 ./mpi_app 50 1000 0.0001 1 1 
mpirun -np 2 ./mpi_app 50 1000 0.0001 2 1
mpirun -np 4 ./mpi_app 50 1000 0.0001 2 2 
mpirun -np 9 ./mpi_app 50 1000 0.0001 3 3 
mpirun -np 16 ./mpi_app 50 1000 0.0001 4 4
mpirun -np 20 ./mpi_app 50 1000 0.0001 5 4 
mpirun -np 36 ./mpi_app 50 1000 0.0001 6 6 
mpirun -np 49 ./mpi_app 50 1000 0.0001 7 7
mpirun -np 81 ./mpi_app 50 1000 0.0001 9 9 
mpirun -np 169 ./mpi_app 50 1000 0.0001 13 13
mpirun -np 289 ./mpi_app 50 1000 0.0001 17 17



echo -e "\nserial time for ngrid_points_per_dimension=10:" >> performance_analysis.txt
./serial_app 10 1000 0.0001
echo -e "\ngrid_points_per_dimension=10:" >> performance_analysis.txt
mpirun -np 1 ./mpi_app 10 1000 0.0001 1 1
mpirun -np 2 ./mpi_app 10 1000 0.0001 2 1
mpirun -np 4 ./mpi_app 10 1000 0.0001 2 2
mpirun -np 9 ./mpi_app 10 1000 0.0001 3 3
mpirun -np 16 ./mpi_app 10 1000 0.0001 4 4
mpirun -np 20 ./mpi_app 10 1000 0.0001 5 4
mpirun -np 36 ./mpi_app 10 1000 0.0001 6 6
mpirun -np 49 ./mpi_app 10 1000 0.0001 7 7
mpirun -np 81 ./mpi_app 10 1000 0.0001 9 9
mpirun -np 169 ./mpi_app 10 1000 0.0001 13 13
mpirun -np 289 ./mpi_app 10 1000 0.0001 17 17



