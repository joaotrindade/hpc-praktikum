This file contains the documentation of how to build and use our code.

Generated Data will be stored in "generated_data" directory. Generated files will be following:
	1. "log_non_opemp_time_vs_prblmSize.txt" : for non-OpenMP : Problem size -  computational time
	2. "log_openmp_eff_vs_prblm_sz.txt" : for OpenMP: problem size - efficiency
	3. "log_openmp_eff_vs_threads.txt" : for OpenMP: num of threads - Efficiency
	4. "log_openmp_ideal_eff.txt" : for OpenMP: number of threads - ideal efficiency
	5. "log_openmp_ideal_speedup.txt" : for OpenMP: number of threads - ideal speedup
	6. log_openmp_speedup_vs_prblm_sz.txt" : for OpenMP: problem size - speedup
	7. log_openmp_speedup_vs_threads.txt" : for OpenMP: number of threads - speedup
	8. log_openmp_time_prlm_sz.txt" : for OpenMP : Problem size vs computational time
	9. log_openmp_time_vs_threads.txt": for OpenMP: num of threads - computational time


Steps to compile execute and produce results and plots
-------------------------------------------------------------
-------------------------------------------------------------

$ cp scripts/* .

# For OpenMP vs Non-OpenMP
-------------------------------------------------------------
$ make clean
$ sh seq_vs_parallel_diff_prob_sizes_vs_matrix_size.sh
$ python    plot_1.py

Generated Plot:    “./generated_plots/sacaling_time_eff_speedup_VS_size.png”


# For OpenMP Weak Scaling
-------------------------------------------------------------
$ make clean
$ sh weak_scaling.sh
$ python    plot_1.py
$ python    plot_3.py

Generated Plots:
	“./generated_plots/scaling_time_eff_speedup_VS_size.png”
	“./generated_plots/scaling_time_eff_speedup_VS_threads.png”


# For OpenMP Weak Scaling
-------------------------------------------------------------
$ make clean
$ sh strong_scaling.sh
$ python    plot_3.py

Generated Plots:   "./generated_plots/scaling_time_eff_speedup_VS_threads.png"



