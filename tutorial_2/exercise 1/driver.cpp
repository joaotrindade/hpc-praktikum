#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "timer.h"

using namespace std;

int main (int argc, char *argv[])
{

	int num_th = 4, /* number of threads */
	    n = 20; /* number of division */


	if(argc > 1) {
		num_th = atoi(argv[1]);
	}

	if(argc > 2) {
		n = atoi(argv[2]);
	}

	file_ptrs ptr;
	/* Opening file descriptor for non openmp */
	ptr.log_non_openmp_time_vs_prblmSize = fopen("./generated_data/log_non_opemp_time_vs_prblmSize.txt", "a+");

	/* Opening file descriptors for reduction openmp */
	ptr.log_r_prblmSize_vs_time = fopen("./generated_data/log_r_time_prlm_sz.txt", "a+");
	ptr.log_r_time_vs_threads = fopen("./generated_data/log_r_time_vs_threads.txt", "a+");
	ptr.log_r_speedup_vs_threads = fopen("./generated_data/log_r_speedup_vs_threads.txt", "a+");
	ptr.log_r_eff_vs_threads = fopen("./generated_data/log_r_eff_vs_threads.txt", "a+");
	ptr.log_r_ideal_speedup = fopen("./generated_data/log_r_ideal_speedup.txt", "a+");
	ptr.log_r_ideal_eff = fopen("./generated_data/log_r_ideal_eff.txt", "a+");
	ptr.log_r_eff_vs_prblm_size = fopen("./generated_data/log_r_eff_vs_prblm_sz.txt", "a+");
	ptr.log_r_speedup_vs_prblm_size = fopen("./generated_data/log_r_speedup_vs_prblm_sz.txt", "a+");


	/* Opening file descriptors for critical openmp */
	ptr.log_c_prblmSize_vs_time = fopen("./generated_data/log_c_time_prlm_sz.txt", "a+");
	ptr.log_c_time_vs_threads = fopen("./generated_data/log_c_time_vs_threads.txt", "a+");
	ptr.log_c_speedup_vs_threads = fopen("./generated_data/log_c_speedup_vs_threads.txt", "a+");
	ptr.log_c_eff_vs_threads = fopen("./generated_data/log_c_eff_vs_threads.txt", "a+");
	ptr.log_c_ideal_speedup = fopen("./generated_data/log_c_ideal_speedup.txt", "a+");
	ptr.log_c_ideal_eff = fopen("./generated_data/log_c_ideal_eff.txt", "a+");
	ptr.log_c_eff_vs_prblm_size = fopen("./generated_data/log_c_eff_vs_prblm_sz.txt", "a+");
	ptr.log_c_speedup_vs_prblm_size = fopen("./generated_data/log_c_speedup_vs_prblm_sz.txt", "a+");


	printf("----------------------------------------------------\n");
	printf("----------------------------------------------------\n");
	printf("num of threads = %d number of division = %d\n", num_th, n);
	printf("----------------------------------------------------\n");

	/* calling PI calculation methods */
	serial(num_th, n, &ptr);	
	printf("----------------------------------------------------\n");
}
