all: clean naive optimised openmp

naive: naive_dgemm.c
	gcc -g -o naive_app naive_dgemm.c

optimised: optimized_dgemm.c
	gcc -g -o optimized_app optimized_dgemm.c

openmp: timer.c timer.h openmp_dgemm.c 
	gcc -g -O0 -fopenmp -c -o timer.o timer.c
	gcc -g -O0 -fopenmp -c -o openmp_dgemm.o openmp_dgemm.c
	gcc -g -fopenmp -o openmp_app openmp_dgemm.o timer.o
	rm -rf *.o

clean:
	rm -rf *.o
	rm -rf cachegrind.out.*
	rm -rf *.txt
