#include <omp.h>
#include <iostream>
#include <iomanip>
#include "timer.h"

using namespace std;

void openmp_reduction(
			int num_thread, // number of threads 
			int n,      // number of division  
			double seq_time_result, // Non-OpenMP computational time in seconds
		        file_ptrs *ptr//structure of file ptrs
		    )
{

	double area, pi, x;
	int i; 

	double para_time_result, speedup, eff;
	time_marker_t time;
	
	area = 0.0;

	cout << "OpenMP reduction starts here\n";
	time = get_time();
	#pragma omp parallel for private(x) reduction(+:area)
	for (i = 0; i < n; i++) {
	   x = (i+0.5)/n;
	   area += 1.0/(1.0 + x*x);
	}
	pi = area * 4 / n;
	printf("Time elapsed. time: %g   ticks: %g\n", get_ToD_diff_time(time), get_ticks_diff_time(time));		
	cout << setprecision(18) << "PI = " << pi << endl;


	/* calculation for parallelizaed measurements */
	para_time_result = get_ticks_diff_time(time);	
	speedup = seq_time_result / para_time_result;
	eff = speedup / (double)num_thread;
	printf("speedup = %g, efficiency = %g\n",speedup, eff);


	/* writing the results of parallelizaed calculations in txt files that will be used for plot generation */
	fprintf(ptr->log_r_prblmSize_vs_time, "%d %g\n", n, para_time_result); //x: division, y: time
	fprintf(ptr->log_r_time_vs_threads, "%d %g\n", num_thread, para_time_result); //x: num_thread, y: time

	fprintf(ptr->log_r_speedup_vs_threads, "%d %g\n", num_thread, speedup); //x: num_thread, y: speedup
	fprintf(ptr->log_r_ideal_speedup, "%d %d\n", num_thread, num_thread); //x: num_thread, y: ideal speedup=no of processing units

	fprintf(ptr->log_r_eff_vs_threads, "%d %g\n", num_thread, eff); //x: num_thread, y: effieciency
	fprintf(ptr->log_r_ideal_eff, "%d %d\n", num_thread, 1); //x: num_thread, y: ideal effieciency

	fprintf(ptr->log_r_eff_vs_prblm_size, "%d %g\n", n, eff); //x: division, y: effieciency
	fprintf(ptr->log_r_speedup_vs_prblm_size, "%d %g\n", n, speedup); //x: division, y: speedup

	cout << "OpenMP reduction ends here\n";
	printf("----------------------------------------------------\n");


	/* closing file descriptors */
	fclose(ptr->log_r_prblmSize_vs_time);
	fclose(ptr->log_r_time_vs_threads);
	fclose(ptr->log_r_speedup_vs_threads);
	fclose(ptr->log_r_eff_vs_threads);
	fclose(ptr->log_r_ideal_speedup);
	fclose(ptr->log_r_ideal_eff);
	fclose(ptr->log_r_eff_vs_prblm_size);
	fclose(ptr->log_r_speedup_vs_prblm_size);


	return;
}
