#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "timer.h"

using namespace std;

int main (int argc, char *argv[])
{

	double area = 0.0, pi, x;
	int i, 
	    n = 20; /* number of division */

	time_marker_t time;
	
	if(argc > 1) {
		n = atoi(argv[1]);
	}
	
	cout << "Non-OpenMP strats here\n";
	cout << "---------------------------\n";
	
	time = get_time();
	for (i = 0; i < n; i++) {
	   x = (i+0.5)/n;
	   area += 1.0/(1.0 + x*x);
	}
	pi = area * 4 / n;
	printf("Time elapsed. time: %g  ticks: %g\n", get_ToD_diff_time(time), get_ticks_diff_time(time));		
	cout << setprecision(18) << "PI = " << pi << endl;

	cout << "Non-OpenMP ends here\n";
	cout << "---------------------------\n";
}
