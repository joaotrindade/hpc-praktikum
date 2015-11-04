all: serial openmp_critical openmp_reduction

openmp_reduction: openmp_reduction.cpp
	g++-4.9 -fopenmp openmp_reduction.cpp -o openmp_reduction.out

openmp_critical: openmp_critical.cpp
	g++-4.9 -fopenmp openmp_critical.cpp -o openmp_critical.out

serial: serial.cpp
	g++ serial.cpp -o serial.out

timer.o: timer.c timer.h
	icc timer.c -c

clean:
	rm -rf *.o
	rm -rf cachegrind.out.*
	rm -rf cg.out
	rm -rf matrix
