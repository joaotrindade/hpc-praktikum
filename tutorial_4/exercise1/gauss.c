/* row wise gaus algorithm
 * pattern for practical course
 * -------------------------
 * autor: Markus Brenk
 * date: 2002-09-25
 * =================================================== */

//#define NGLS 32768

//total number of systems of equations (this is max both compiler can handle), exceed this compiler relocation will fail
#define NGLS   1000000 

//a hack to increase the number of system of equations: so real_total_num_of_sys_eq = NGLS*REPEAT
#define REPEAT 300


#define NUM_LOOPS 4 

#include <stdio.h>
#include <math.h>
#include "timer.h"


/* print a 3x3 matrix */
void print_matrix(char* name, double matrix[3][3]);


/* print a 3d vector */
void print_vector(char* name, double vec[3]);


/**
 *  initialisation: generates the following LGS:
 *  ( 3  1  1)       (5)                         (1)
 *  ( 1  4  1) * X = (6)        => solution  X = (1)
 *  ( 1  1  5)       (7)                         (1)
 */
void init(double a[3][3], double b[3], double x[3]);

/** performs gauss elimination */
void gauss_elimination(double a[3][3], double b[3], double x[3]);


double a[NGLS][3][3];
double b[NGLS][3];
double x[NGLS][3];

int main() {

	int i, j;
	int n=3;

        int m;
        double total_elapsed_time = 0;

	time_marker_t time;

        for(m = 0; m < REPEAT; m++) {
		for (i = 0; i < NGLS; i++) {
			init(a[i], b[i], x[i]);
		}

		time = get_time();
		for (i = 0; i < NGLS; i++) {
			gauss_elimination(a[i], b[i], x[i]);
	                //print_vector("solution :", x[i]);
		}
		
		total_elapsed_time += get_ToD_diff_time(time);
        }

	printf("NAIV: Time elapsed. time: %g\n", total_elapsed_time);
	return(0);
}



void init(double a[3][3], double b[3], double x[3]) {
	int i,j;
	int n = 3;

	for (j=0;j<n;j++)
	{
		b[j]=(float)(2*n-2)+(float)(j+1);
		a[j][j]=(float)(n-1)+(float)(j+1);
		x[j]=0.;

		for (i=j+1;i<n;i++) {
			a[i][j]=1.;
		}
		for (i=0;i<j;i++) {
			a[i][j]=1.;
		}
	}
}


void gauss_elimination(double a[3][3], double b[3], double x[3]) {
	int n = 3;
	int i,j,k;

        /* converting to echelon form */
	for (i = 0; i < n; i++) {

		for (j = i+1; j < n; j++) {
		  	a[i][j] = a[i][j] / a[i][i];
		}
		b[i] = b[i] / a[i][i];

		for (j = i+1; j < n; j++) {
			double factor = a[j][i];
			for (k = i; k < n; k++) {
				a[j][k] = a[j][k] - a[i][k] * factor;
			}
			b[j] = b[j] - factor * b[i];
		}
	}


        /* back-substituting */
	for (i = n-1; i >= 0; i--) {
		x[i] = b[i];
		for(j = i+1; j < n; j++) {
			x[i] -= a[i][j] * x[j];
		}
	}
}


void print_matrix(char* name, double matrix[3][3]) {
	int i, j;
	printf("Matrix %s: \n", name);
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf(" %f ", matrix[i][j]);
		}
		printf(" ;\n");
	}
}

void print_vector(char* name, double vec[3]) {
	int i;
	printf("vector %s: \n", name);
	for (i=0;i<3;i++)
	{
		printf(" %f \n",vec[i]);
	}
}

