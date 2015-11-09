/*
 * timer.h
 *
 * Small library for time measurement.
 *
 * @date   18/09/09
 * @author Wolfgang Eckhardt
 * @mailto eckhardw@in.tum.de
 *
 */

#include <stdio.h>
#include <time.h>
#include <sys/time.h>


#ifndef TIMER_H
#define TIMER_H

/**
 * This struct encapsulates all the different data of various timing functions.
 * Although one precise function should be enough, the overhead of using several
 * functions should not be too large, so it should be alright for an evaluation of
 * these functions.
 */
typedef struct {
	/** used by gettimeofday() */
	struct timeval tv;
	/** used by clock()  */
	clock_t ticks;
} time_marker_t;

/**
 * returns a struct time with all data initialized to the current time.
 */
time_marker_t get_time();

/**
 * returns the time difference in seconds between the time which is represented by the parameter
 * and the current time, using gettimeofday().
 * precision: up to micro seconds, hardware dependent.
 */
double get_ToD_diff_time(time_marker_t time);

/**
 * returns the time difference in seconds between the time which is represented by the parameter
 * and the current time, using clock().
 * precision: milli seconds.
 */
double get_ticks_diff_time(time_marker_t time);

/**
 * calculate and print the FLOPS, taking the number of floating point operations and the time.
 */
void print_flops(int flop, time_marker_t time);

typedef struct	
{	
		FILE *log_non_openmp_time_vs_prblmSize;   /* for non-OpenMP : div vs time */


		FILE *log_r_prblmSize_vs_time;       /* for Reduction OpenMP : div vs time */
		FILE *log_r_time_vs_threads;         /* for Reduction OpenMP: time vs num of threads */
		FILE *log_r_speedup_vs_threads;      /* for Reduction OpenMP: speedup vs number of threads */
		FILE *log_r_eff_vs_threads;          /* for Reduction OpenMP: Efficiency vs num of threads */ 
		FILE *log_r_ideal_speedup;           /* for ReductionOpenMP: ideal speedup vs threads*/
		FILE *log_r_ideal_eff;               /* for Reduction OpenMP: ideal efficiency vs threads */
		FILE *log_r_eff_vs_prblm_size;       /* for Reduction OpenMP: eff vs div */
		FILE *log_r_speedup_vs_prblm_size;   /* for Reduction OpenMP: speedup vs div */


		FILE *log_c_prblmSize_vs_time;       /* for Critical OpenMP : div vs time */
		FILE *log_c_time_vs_threads;         /* for critical OpenMP: time vs num of threads */
		FILE *log_c_speedup_vs_threads;      /* for critical OpenMP: speedup vs number of threads */
		FILE *log_c_eff_vs_threads;          /* for critical OpenMP: Efficiency vs num of threads */ 
		FILE *log_c_ideal_speedup;           /* for critical OpenMP: ideal speedup vs threads*/
		FILE *log_c_ideal_eff;               /* for critical OpenMP: ideal efficiency vs threads */
		FILE *log_c_eff_vs_prblm_size;       /* for critical OpenMP: eff vs div */
		FILE *log_c_speedup_vs_prblm_size;   /* for critical OpenMP: speedup vs div */
}file_ptrs;

/**
 * PI calculation functions
 */
void serial(int num_th, int n, file_ptrs *ptr);
void openmp_critical(int num_th, int n, double seq_time_result, file_ptrs *ptr);
void openmp_reduction(int num_th, int n, double seq_time_result, file_ptrs *ptr);

#endif /* TIMER_H */
