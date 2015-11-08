all: clean stream stream_remote stream_l1 stream_l2 stream_l3

stream_l3: stream_omp_l3_cache.c
	icc -openmp stream_omp_l3_cache.c -o stream_omp_l3_cache.o

stream_l2: stream_omp_l2_cache.c
	icc -openmp stream_omp_l2_cache.c -o stream_omp_l2_cache.o

stream_l1: stream_omp_l1_cache.c
	icc -openmp stream_omp_l1_cache.c -o stream_omp_l1_cache.o

stream_remote: stream_omp_remote.c
	icc -openmp stream_omp_remote.c -o stream_omp_remote.o

stream: stream_omp.c
	icc -openmp stream_omp.c -o stream_omp.o

clean:
	rm -rf *.o
	rm -rf cachegrind.out.*
	rm -rf cg.out
	rm -rf matrix
