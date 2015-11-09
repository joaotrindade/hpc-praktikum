#include <omp.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "timer.h"

using namespace std;

int main (int argc, char *argv[])
{

	double area, pi, x;
	int i,
	    num_th = 4, /* number of threads */
	    n = 20; /* number of division */

	time_marker_t time;

	if(argc > 1) {
		num_th = atoi(argv[1]);
	}

	if(argc > 2) {
		n = atoi(argv[2]);
	}
	
	omp_set_num_threads(num_th);

	area = 0.0;

	cout << "OpenMP critical strats here\n";
	cout << "---------------------------\n";

	time = get_time();
	#pragma omp parallel for private(x)
	for (i = 0; i < n; i++) {
	   x = (i+0.5)/n;
	   #pragma omp critical
	   area += 1.0/(1.0 + x*x);
	}
	pi = area * 4 / n;
	printf("Time elapsed. time: %g   ticks: %g\n", get_ToD_diff_time(time), get_ticks_diff_time(time));		
	cout << setprecision(18) << "PI = " << pi << endl;	

	cout << "OpenMP critical ends here\n";
	cout << "---------------------------\n";
	
}
