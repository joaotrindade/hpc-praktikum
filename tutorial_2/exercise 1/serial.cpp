#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "timer.h"

using namespace std;

int main (int argc, char *argv[])
{

	double area, pi, x;
	int i, n;
	char c;
	time_marker_t time;
	cout << "Number of divisions ? "; 
	cin >> n; 
	area = 0.0;
	
	time = get_time();
	for (i = 0; i < n; i++) {
	   x = (i+0.5)/n;
	   area += 1.0/(1.0 + x*x);
	}
	pi = area * 4 / n;
	printf("Time elapsed. time: %f   ticks: %f\n", get_ToD_diff_time(time), get_ticks_diff_time(time));		
	cout << setprecision(18) << "PI = " << pi << endl;
}