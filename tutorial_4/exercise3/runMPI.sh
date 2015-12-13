#!/bin/bash
#SBATCH -o /home/hpc/t1221/t1221ag/Tutorial4/exercise3/myjob.%j.%N.out 
#SBATCH -D /home/hpc/t1221/t1221ag/Tutorial4/exercise3/ 
#SBATCH -J scalasca 
#SBATCH --get-user-env 
#SBATCH --clusters=mpp2
#SBATCH --ntasks=16
#SBATCH --mail-type=end 
#SBATCH --mail-user=joao.ferreira.trindade@gmail.com 
#SBATCH --export=NONE 
#SBATCH --time=00:05:00 
source /etc/profile.d/modules.sh
cd $SCRATCH/mydata
mpirun -np 16 ./mpi_app 6000 1000 0.0001 4 4
