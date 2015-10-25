/* row wise gaus algorithm
 * pattern for practical course
 * -------------------------
 * autor: Markus Brenk
 * date: 2002-09-25
 * =================================================== */

//#define NGLS 32768
#define NGLS 32800

#define NUM_LOOPS 4

#include <stdio.h>
#include <math.h>
#include "timer.h"


/* print a 3x3 matrix */
void print_matrix(char* name, double matrix[3][3]);

void lu_2nd(double A[3][3], double L[3][3], double U[3][3]);

/* print a 3d vector */
void print_vector(char* name, double vec[3]);

void decomposeSerial(double A[3][3], long n);

/**
 *  initialisation: generates the following LGS:
 *  ( 3  1  1)       (5)                         (1)
 *  ( 1  4  1) * X = (6)        => solution  X = (1)
 *  ( 1  1  5)       (7)                         (1)
 */
void init(double a[3][3], double b[3], double x[3]);

/** performs gauss elimination */
void gauss_elimination(double a[3][3], double b[3], double x[3]);

int lu_decomposition(double a[3][3], double l[3][3], double u[3][3]);

double a[NGLS][3][3];
double b[NGLS][3];
double x[NGLS][3];
double L[3][3], U[3][3];
double y[3];

int main() {

	int i, j;
	int n=3;
	double sum;
	time_marker_t time;

	for (i = 0; i < NGLS; i++) {
		init(a[i], b[i], x[i]);
	}

	time = get_time();
	/*for (i = 0; i < NGLS; i++) {
		gauss_elimination(a[i], b[i], x[i]);
	}*/
	
	
	//gauss_elimination(a[0], b[0], x[0]);
	//init(a[0], b[0], x[0]);
	lu_decomposition(a[0],L,U);

	
	y[0]=1;
	y[1]=1;
	y[2]=1;
	
	
	// THIS CAN BE VECTORIZED
	// L x Y = B
	for(i=0; i<n; i++)
    {
        sum = 0; 
        for(j=0; j<=i; j++)
        {
        	printf("L[%d][%d] = %f --- y[%d] = %f\n",i,j,L[i][j],j,y[j]);
            sum+=L[i][j]*y[j]; 
			printf("entrou i:%d j:%d sum:%f\n",i,j,sum);
        }
        y[i]=b[0][i] / sum;
        printf("y[i] = %f\n",y[i]);
    }

	print_vector("Y solved", y);
	
	
	// THIS CAN BE VECTORIZED
	// U x X = Y
	for(i=n-1; i>=0; i--)
    {
        x[0][i]= y[i];
        for(j=i+1; j<n; j++)
        {
            x[0][i]-=U[i][j]*x[0][j];
        }
        x[0][i]/=U[i][i];
    }
	
	print_vector("X solved", x[0]);
	
	printf("NAIV: Time elapsed. time: %f   ticks: %f\n", get_ToD_diff_time(time), get_ticks_diff_time(time));
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
	print_matrix("gauss before", a);
	
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
	
	print_matrix("gauss mid", a);
	

	for (i = n-1; i >= 0; i--) {
		x[i] = b[i];
		for(j = i+1; j < n; j++) {
			x[i] -= a[i][j] * x[j];
		}
	}
	print_matrix("gauss after", a);
	print_vector("x after gauss",x);
}

int lu_decomposition(double a[3][3], double l[3][3], double u[3][3]) {
	int i, j, k;
	int n=3;
	print_matrix("LU Before",a);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j < i)
                l[j][i] = 0;
            else
            {
                l[j][i] = a[j][i];
                for (k = 0; k < i; k++)
                {
                    l[j][i] = l[j][i] - l[j][k] * u[k][i];
                }
            }
        }
        for (j = 0; j < n; j++)
        {
            if (j < i)
                u[i][j] = 0;
            else if (j == i)
                u[i][j] = 1;
            else
            {
                u[i][j] = a[i][j] / l[i][i];
                for (k = 0; k < i; k++)
                {
                    u[i][j] = u[i][j] - ((l[i][k] * u[k][j]) / l[i][i]);
                }
            }
        }
    }



	print_matrix("L After 1st",l);
	print_matrix("U After 1st",u);
	
    return 0;
}

void lu_2nd(double A[3][3], double L[3][3], double U[3][3]) {

	int i, j, k;
	int n=3;
	//print_matrix("LU Before",A);
	
	for(j=0; j<n; j++)
    {
        for(i=0; i<n; i++)
        {
            if(i<=j)
            {
                U[i][j]=A[i][j];
                for(k=0; k<i-1; k++)
                    U[i][j]-=L[i][k]*U[k][j];
                if(i==j)
                    L[i][j]=1;
                else
                    L[i][j]=0;
            }
            else
            {
                L[i][j]=A[i][j];
                for(k=0; k<=j-1; k++)
                    L[i][j]-=L[i][k]*U[k][j];
                L[i][j]/=U[j][j];
                U[i][j]=0;
            }
        }
    }
    print_matrix("L After 2nd",L);
	print_matrix("U After 2nd",U);
}


void decomposeSerial(double A[3][3], long n)
{
	printf("DECOMPOSE SEQUENTIAL CALLED");
	long i,j,k;
	for(k=0;k<n;k++){
		for(j=k+1;j<n;j++)
			A[k][j]=A[k][j]/A[k][k];

		for(i=k+1;i<n;i++)
			for(j=k+1;j<n;j++)
				A[i][j]=A[i][j] - A[i][k] * A[k][j];
	}
	
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(i==j){
				k=i+1;
				A[i][j]=4*k-3;
			}
			else{
				A[i][j]=A[i][i]+1;
				A[j][i]=A[i][i]+1;
			}
		}
	}
	
		print_matrix("A After",A);
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

