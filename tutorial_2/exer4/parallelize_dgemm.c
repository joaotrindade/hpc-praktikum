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
	 
	double result;

	int block_size = 8;
	int num_thread = 0;

	//char logfile_name[1000];
	FILE *logfile_handle, 
	     *log_time_vs_threads;

	n = 500;
	if(argc > 1){
		n = atoi(argv[1]);
	}
	if(argc > 2){
		block_size = atoi(argv[2]);
	}

	//sprintf(logfile_name, "logfile_dgemm.txt");
	logfile_handle = fopen("./log_openmp_time_prlm_sz.txt", "a+"); //for OpenMP Vs NonOpenMP: Problem size vs time
	if(logfile_handle == NULL)
	{
		printf("\nWarning : Fix path of log file, nothing is being recorded\n");
	}

	log_time_vs_threads = fopen("./log_time_vs_threads.txt", "a+"); //for OpenMP Vs NonOpenMP: time vs num of threads
	if(log_time_vs_threads == NULL)
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

	//#pragma omp parallel for schedule(dynamic) default(none) shared(block_size, n, a, b, c) private(i, j, k, ii, jj, kk)
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

	printf("OpenMP: Problem size = %d, cache block size = %d, number of threads = %d:\n",n, block_size, num_thread);
	
	result = print_flops(flops, time);
	printf("---------------------------------");

	fprintf(logfile_handle, "%d %e\n", n, result); //x: problem size, y: time
	fprintf(log_time_vs_threads, "%d %e\n", num_thread, result); //x: num_thread, y: time

	fclose(logfile_handle);
	fclose(log_time_vs_threads);

	return(0);
}

