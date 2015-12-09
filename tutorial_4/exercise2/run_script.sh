#!/bin/bash
#SBATCH -o /home/hpc/t1221/t1221ag/Tutorial4/exercise2/myjob.%j.%N.out 
#SBATCH -D /home/hpc/t1221/t1221ag/Tutorial4/exercise2/ 
#SBATCH -J quicksort-analysis
#SBATCH --get-user-env 
#SBATCH --clusters=mpp2
#SBATCH --nodes=1-1 
#SBATCH --cpus-per-task=28 
# in the line above:
#  replace 28 by 16 to use the MPP cluster
#SBATCH --mail-type=end 
#SBATCH --mail-user=joao.ferreira.trindade@gmail.com 
#SBATCH --export=NONE 
#SBATCH --time=00:05:00 
source /etc/profile.d/modules.sh
cd mydir
export OMP_NUM_THREADS=28 
# 28 is the maximum reasonable value for CooLMUC2, and 16 for the MPP cluster 
/lrz/mnt/sys.x86_64/intel/amplifier_xe_2015/vtune_amplifier_xe_2015.1.0.367959/bin64/amplxe-cl -collect hotspots -app-working-dir /home/hpc/t1221/t1221ag/Tutorial2/Exercise3 -- /home/hpc/t1221/t1221ag/Tutorial2/Exercise3/quicksort.out 500000000 28