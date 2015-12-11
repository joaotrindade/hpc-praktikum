/** 
 * matrix matrix multiplication pattern for practical course
 * Reference for parallelization while ensuring that each cache-block is handled by only one thread : 
 * 	http://www.netlib.org/utk/papers/autoblock/node2.html
 **/

#include "timer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int max(int a, int b){
	if(a >= b) return a;
	else return b;
}

int min(int a, int b){
	if(a <= b) return a;
	else return b;
}

int main(int argc, char **argv)
{
	int n; //problem size
	double *a, *b, *c;

	int mem_size;

	int i, j, k;
	int ii, jj, kk;
	 
	double para_time_result;


	int block_size = 16;
	int num_thread = 0;


	n = 500; /* default problem size */
	double flops;

	/* Default values if nothing is given by command prompt */
	if(argc > 1){
		n = atoi(argv[1]);
	}
	if(argc > 2){
		block_size = atoi(argv[2]);
	}



	/* Dynamic memory allocation */
	mem_size = n * n * sizeof(double);
	a = (double*)malloc(mem_size);
	b = (double*)malloc(mem_size);
	c = (double*)malloc(mem_size);
	if(0 == a || 0 == b || 0 == c){
		printf("memory allocation failed");
		return 0;
	}

	/* initialisation */
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			*(a + i * n + j) = (double)i + (double)j;
			*(b + i * n + j) = (double)(n - i) + (double)(n - j);
		}
	}


	memset(c, 0, mem_size);


	/* Parallelizing matrix multiplication with OpenMP where each cache-block is handled by only one thread starts here*/
	time_marker_t time = get_time();
	#pragma omp parallel default(none) shared(block_size, n, a, b, c) private(i, j, k, ii, jj, kk) reduction(+:num_thread)
	{
		num_thread += 1;

		#pragma omp for schedule(dynamic)
		for(i = 0; i < n; i += block_size){
			for(j = 0; j < n; j += block_size){
				for(k = 0; k < n; k += block_size){

					for(ii = i; ii < min(i + block_size, n); ii++) {
						for(jj = j; jj < min(j + block_size, n); jj++) {
							for(kk = k; kk < min(k + block_size, n); kk++) {
								c[ii * n + jj] += a[ii * n + kk] * b[kk * n + jj];
							}
						}
					}
				}
			}
		}


		#pragma omp barrier
  	}

	flops = 2.0 * n * n * n;

	para_time_result = print_flops(flops, time);
	printf("\nOpenMP: Problem size = %d, cache block size = %d, num_threads = %d, time=%g\n",
                                         n, block_size, num_thread, para_time_result);
	printf("****************************************************************************************\n");

	/* matrix multiplication with OpenMP ends here */


	return(0);
}

