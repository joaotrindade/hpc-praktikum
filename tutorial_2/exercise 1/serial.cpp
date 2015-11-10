#include <iostream>
#include <iomanip>
#include "timer.h"

using namespace std;

void serial(
		int num_th, // number of threads 
		int n,      // number of division 
		file_ptrs *ptr//structure of file ptrs
	   )
{

	double area = 0.0, pi, x;
	int i; 
	double seq_time_result; // Non-OpenMP computational time in seconds

	time_marker_t time;
	
	printf("Non-OpenMP strats here\n");
	

	time = get_time();
	for (i = 0; i < n; i++) {
	   x = (i+0.5)/n;
	   area += 1.0/(1.0 + x*x);
	}

	pi = area * 4 / n;
	printf("Time elapsed. time: %g  ticks: %g\n", get_ToD_diff_time(time), get_ticks_diff_time(time));
	seq_time_result = get_ToD_diff_time(time);	
	cout << setprecision(18) << "PI = " << pi << endl;
	fprintf(ptr->log_non_openmp_time_vs_prblmSize, "%d %e\n", n, seq_time_result); //x: problem size, y: time
	fclose(ptr->log_non_openmp_time_vs_prblmSize);


	printf("Non-OpenMP ends here\n");
	cout << "---------------------------\n";


	/* Calling OpenMP functions */
	openmp_critical(num_th, n, seq_time_result, ptr);
	openmp_reduction(num_th, n, seq_time_result,ptr);


	return;
}
