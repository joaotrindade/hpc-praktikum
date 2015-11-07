/*
 * timer.c
 *
 * @date   18/09/09
 * @author Wolfgang Eckhardt
 * @mailto eckhardw@in.tum.de
 *
 */

#include "timer.h"


time_marker_t get_time() {
	time_marker_t retval;
	gettimeofday(&retval.tv, NULL);
	retval.ticks = clock();
	return retval;
}


double get_ToD_diff_time(time_marker_t time) {
	double res;
	struct timeval tmp;
	gettimeofday(&tmp, NULL);
	tmp.tv_sec -= time.tv.tv_sec;
	tmp.tv_usec -= time.tv.tv_usec;
	res = (double)tmp.tv_sec + (double)tmp.tv_usec*1e-6;
	//return ((double)tmp.tv_sec + (double)(tmp.tv_usec)*1e-6);
	//return (double)tmp.tv_sec + (double)tmp.tv_usec*1e-6;
	return res;
}


double get_ticks_diff_time(time_marker_t time) {
	clock_t tmp = clock();
	return ((double)(tmp - time.ticks) / (double)CLOCKS_PER_SEC);
}

double print_flops(int flop, time_marker_t time) {
	//double val =  (double) flop / get_ToD_diff_time(time);
	double val =  (double) flop / get_ticks_diff_time(time);
	printf("FLOPS with clock(): %e \n", (double) flop / get_ticks_diff_time(time));
	printf("FLOPS with timeofday(): %e \n", val);
	return val;
}
