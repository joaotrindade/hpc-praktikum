#!/bin/bash
#SBATCH -o /home/hpc/t1221/t1221ag/Tutorial3/exercise2/myjob.%j.%N.out 
#SBATCH -D /home/hpc/t1221/t1221ag/Tutorial3/exercise2/ 
#SBATCH -J Jobname 
#SBATCH --get-user-env 
#SBATCH --clusters=mpp2
# alternatively, use mpp1 
#SBATCH --ntasks=1000
# multiples of 28 for mpp2
# multiples of 16 for mpp1
#SBATCH --mail-type=end 
#SBATCH --mail-user=joao.ferreira.trindade@gmail.com 
#SBATCH --export=NONE 
#SBATCH --time=00:20:00 
source /etc/profile.d/modules.sh
cd $SCRATCH/mydata
mpiexec $HOME/Tutorial3/exercise2/imb/src/IMB-NBC ireduce
