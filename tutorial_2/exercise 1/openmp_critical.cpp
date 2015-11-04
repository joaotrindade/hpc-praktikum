#include <omp.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main (int argc, char *argv[])
{

	double area, pi, x;
	int i, n;
	char c;

	cout << "Number of divisions ? "; 
	cin >> n; 
	area = 0.0;

	#pragma omp parallel for private(x)
	for (i = 0; i < n; i++) {
	   x = (i+0.5)/n;
	   #pragma omp critical
	   area += 1.0/(1.0 + x*x);
	}
	
	pi = area * 4 / n;

	cout << setprecision(18) << "PI = " << pi << endl << endl;
	
	cout << "Press enter to continue ...";
	cin.get(c);
	cin.get(c);
		
}