all: serial openmp_critical openmp_reduction

openmp_reduction: openmp_reduction.cpp
	g++ -fopenmp openmp_reduction.cpp timer.cpp -o openmp_reduction.out

openmp_critical: openmp_critical.cpp
	g++ -fopenmp openmp_critical.cpp timer.cpp -o openmp_critical.out

serial: serial.cpp
	g++ serial.cpp timer.cpp -o serial.out

timer.o: timer.cpp timer.h
	g++ -fopenmp -c -o timer.o timer.c

clean:
	rm -rf *.o
	rm -rf *.out
	rm -rf ./generated_data/*.txt
	rm -rf *.txt
