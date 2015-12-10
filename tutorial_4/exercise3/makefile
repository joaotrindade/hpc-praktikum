all: clean poisson

poisson: mpi_poisson.cpp
	mpiicc mpi_poisson.cpp -o mpi_app
	icc serial_poisson.cpp -o serial_app

clean:
	rm -rf *.o
	rm -rf cachegrind.out.*
	rm -rf serial_app
	rm -rf mpi_app
	rm -rf *.gnuplot
	rm -rf a.out
	rm -rf performance_analysis.txt
	touch performance_analysis.txt
	rm -rf compare_result.txt
