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
	 
	double para_time_result,
	       seq_time_result;

	double speedup,
	       eff;

	int block_size = 8;
	int num_thread = 0;

	//char logfile_name[1000];
	FILE *log_non_opemp_time_vs_prblmSize,
	     *log_openmp_prblmSize_vs_time, 
	     *log_openmp_time_vs_threads,
	     *log_openmp_speedup_vs_threads,
	     *log_openmp_eff_vs_threads;

	n = 500;
	double flops;

	if(argc > 1){
		n = atoi(argv[1]);
	}
	if(argc > 2){
		block_size = atoi(argv[2]);
	}

	//sprintf(logfile_name, "logfile_dgemm.txt");
	log_non_opemp_time_vs_prblmSize = fopen("./log_non_opemp_time_vs_prblmSize.txt", "a+"); //for non-OpenMP : Problem size vs time
	log_openmp_prblmSize_vs_time = fopen("./log_openmp_time_prlm_sz.txt", "a+"); //for weak OpenMP : Problem size vs time
	log_openmp_time_vs_threads = fopen("./log_openmp_time_vs_threads.txt", "a+"); //for weak OpenMP: time vs num of threads
	log_openmp_speedup_vs_threads = fopen("./log_openmp_speedup_vs_threads.txt", "a+"); //for weak OpenMP: speedup vs num of threads
	log_openmp_eff_vs_threads = fopen("./log_openmp_eff_vs_threads.txt", "a+"); //for weak OpenMP: speedup vs num of threads

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

	/* matrix multiplication with Non-OpenMP starts here */
	time_marker_t seq_time = get_time();
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			for(k = 0; k < n; k++){
				c[i * n + j] += a[i * n + k] * b[k * n + j];
			}
		}
	}

	flops = 2.0 * n * n * n;

	printf("Non OpenMP: Problem size = %d :\n",n);
	seq_time_result = print_flops(flops, seq_time);
	printf("---------------------------------\n");
	fprintf(log_non_opemp_time_vs_prblmSize, "%d %e\n", n, seq_time_result); //x: problem size, y: time
	fclose(log_non_opemp_time_vs_prblmSize);
	/* matrix multiplication with Non-OpenMP ends here */



	/* Parallelizing matrix multiplication with OpenMP where each cache-block is handled by only one thread starts here*/
	printf("OpenMP: Problem size = %d, cache block size = %d, number of threads = %d\n",n, block_size, num_thread);
	memset(c, 0, mem_size);
	time_marker_t time = get_time();
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

	
	para_time_result = print_flops(flops, time);
	/* matrix multiplication with OpenMP ends here */



	/* calculation for parallelizaed measurements */
	speedup = seq_time_result / para_time_result;
	eff = speedup / (double)num_thread;
	printf("speedup = %e, efficiency = %e\n",speedup, eff);
	printf("---------------------------------\n");

	/* writing the results in txt files that will be used for plot generation */
	fprintf(log_openmp_prblmSize_vs_time, "%d %e\n", n, para_time_result); //x: problem size, y: time
	fprintf(log_openmp_time_vs_threads, "%d %e\n", num_thread, para_time_result); //x: num_thread, y: time
	fprintf(log_openmp_speedup_vs_threads, "%d %e\n", num_thread, speedup); //x: num_thread, y: speedup
	fprintf(log_openmp_eff_vs_threads, "%d %e\n", num_thread, eff); //x: num_thread, y: effieciency

	fclose(log_openmp_prblmSize_vs_time);
	fclose(log_openmp_time_vs_threads);
	fclose(log_openmp_speedup_vs_threads);
	fclose(log_openmp_eff_vs_threads);

	return(0);
}

