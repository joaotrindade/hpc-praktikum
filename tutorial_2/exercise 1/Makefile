all: serial openmp_critical openmp_reduction

openmp_reduction: openmp_reduction.cpp
	g++-4.9 -fopenmp openmp_reduction.cpp timer.cpp -o openmp_reduction.out

openmp_critical: openmp_critical.cpp
	g++-4.9 -fopenmp openmp_critical.cpp timer.cpp -o openmp_critical.out

serial: serial.cpp
	g++ serial.cpp timer.cpp -o serial.out

timer.o: timer.cpp timer.h
	icc timer.cpp -c

clean:
	rm -rf *.o
	rm -rf cachegrind.out.*
	rm -rf cg.out
	rm -rf matrix
