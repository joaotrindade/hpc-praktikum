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
	int n;
	double *a, *b, *c;

	int mem_size;

	int i, j, k;
	int ii, jj, kk;
	 
	double result;

	int block_size = 8;

	//char logfile_name[1000];
	FILE *logfile_handle;

	n = 500;
	if(argc > 1){
		n = atoi(argv[1]);
	}
	if(argc > 2){
		block_size = atoi(argv[2]);
	}

	//sprintf(logfile_name, "logfile_dgemm.txt");
	logfile_handle = fopen("./parallelize_result.txt", "a+");
	if(logfile_handle == NULL)
	{
		printf("\nWarning : Fix path of log file, nothing is being recorded\n");
	}

	mem_size = n * n * sizeof(double);
	a = (double*)malloc(mem_size);
	b = (double*)malloc(mem_size);
	c = (double*)malloc(mem_size);
	if(0 == a || 0 == b || 0 == c){
		printf("memory allocation failed");
		return 0;
	}

	/* initialisation */
	//#pragma omp parallel for default(none) shared(n, a, b) private(i, j)
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			*(a + i * n + j) = (double)i + (double)j;
			*(b + i * n + j) = (double)(n - i) + (double)(n - j);
		}
	}

	//#pragma omp barrier

	memset(c, 0, mem_size);

	time_marker_t time = get_time();
	double flops;

	#pragma omp parallel for schedule(dynamic) default(none) shared(block_size, n, a, b, c) private(i, j, k, ii, jj, kk)
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

	flops = 2.0 * n * n * n;

	printf("OpenMP: Problem size = %d, cache block size = %d :\n",n, block_size);
	result = print_flops(flops, time);
	fprintf(logfile_handle, "%d %e\n", n, result);

	fclose(logfile_handle);

	return(0);
}

