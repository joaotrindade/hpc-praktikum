#!/bin/bash
#SBATCH -o /home/hpc/t1221/t1221ag/Tutorial4/exercise3/myjob.%j.%N.out 
#SBATCH -D /home/hpc/t1221/t1221ag/Tutorial4/exercise3
#SBATCH -J poisson_openmp
#SBATCH --get-user-env 
#SBATCH --clusters=mpp2
# alternatively, use mpp1 
#SBATCH --ntasks=16
#SBATCH --cpus-per-task=7
# the above is a good match for the
# CooLMUC2 architecture.
# For mpp1, thread counts of 2, 4 or 8
# are recommended
#SBATCH --mail-type=end 
#SBATCH --mail-user=joao.ferreira.trindade@gmail.com
#SBATCH --export=NONE 
#SBATCH --time=00:03:00 
source /etc/profile.d/modules.sh
cd mydir
export OMP_NUM_THREADS=7
module load scalasca
mpirun -n 16 --perhost 4 ./mpi_app_openmp 6000 1000 0.0001 4 4
# 28 is the maximum reasonable value for CooLMUC2, and 16 for the MPP cluster 
