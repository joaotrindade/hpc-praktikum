/** 
 * optimised matrix matrix multiplication using loop nest interchange algo for practical course
 **/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

/// store begin timestep
struct timeval begin;
/// store end timestep
struct timeval end;

///matrix variables
int mem_size; /* total memory bytes occupied by a matrix*/
int n = 500; /* dim of matrix */
double *a, *b, *c;  /* c = a * b */

/**
 * initialize and start timer
 */
void timer_start()
{
	gettimeofday(&begin,(struct timezone *)0);
}

/**
 * stop timer and return measured time
 *
 * @return measured time
 */
double timer_stop()
{
	gettimeofday(&end,(struct timezone *)0);
	double seconds, useconds;
	double ret, tmp;

	if (end.tv_usec >= begin.tv_usec)
	{
		seconds = (double)end.tv_sec - (double)begin.tv_sec;
		useconds = (double)end.tv_usec - (double)begin.tv_usec;
	}
	else
	{
		seconds = (double)end.tv_sec - (double)begin.tv_sec;
		seconds -= 1;					// Correction
		useconds = (double)end.tv_usec - (double)begin.tv_usec;
		useconds += 1000000;			// Correction
	}

	// get time in seconds
	tmp = (double)useconds;
	ret = (double)seconds;
	tmp /= 1000000;
	ret += tmp;

	return ret;
}


int max(int a, int b){
	if(a >= b) return a;
	else return b;
}

int min(int a, int b){
	if(a <= b) return a;
	else return b;
}

void initialize_matrices()
{
     int i, j;
     for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
	       	   *(a + i * n + j) = (double)i + (double)j;
		   *(b + i * n + j) = (double)(n - i) + (double)(n - j);
	    }
     }

     memset(c, 0, mem_size);
}
                              
/*
 * Function Name     : optimized_matrix_multiplication_algo
 * Algorithm Analysis: The index variables j and k change the most frequently and the access pattern through 
 *                     the two operand matrices is sequential using a small physical stride (4 bytes.) 
 *                     These changes improve access to memory data via the data cache. Data TLB behavior is improved, too, 
 *                     since long strides are eliminated.
 */

void optimized_matrix_multiplication_algo()
{
        int i, j, k;
	double flops, time;

	timer_start();

	// Loop nest interchange algorithm
	for(i = 0; i < n; i++){
		for(k = 0; k < n; k++){
			for(j = 0; j < n; j++){
				c[i * n + j] += a[i * n + k] * b[k * n + j];
			}
		}
	}

       	time = timer_stop();

	flops = 2.0 * n * n * n;
	printf("Optimized Needed time(n = %d): %g seconds\n",n, time);

}

int main(int argc, char **argv)
{

	/*char logfile_name[100];
	FILE *logfile_handle;*/

	//n = 500;
	if(argc > 1){
		n = atoi(argv[1]);
	}

	//sprintf(logfile_name, "logfile_dgemm.txt");
	//logfile_handle = freopen(logfile_name, "w", stdout);

	mem_size = n * n * sizeof(double);
	a = (double*)malloc(mem_size);
	b = (double*)malloc(mem_size);
	c = (double*)malloc(mem_size);
	if(0 == a || 0 == b || 0 == c){
		printf("memory allocation failed");
		return 0;
	}

	/* matrices initialisation */
        initialize_matrices();


	/* naive matrix multiplication */  
        optimized_matrix_multiplication_algo();


	return(0);
}

