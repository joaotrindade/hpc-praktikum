all: clean poisson openmp serial

poisson: mpi_poisson.cpp
	scalasca -instrument --mpp=mpi mpiicc mpi_poisson.cpp -o mpi_app

openmp: mpi_openmp_poisson.cpp
	scalasca -instrument --mpp=mpi --thread=omp mpiicc -openmp mpi_openmp_poisson.cpp -o mpi_app_openmp

serial: serial_poisson.cpp
	scalasca -instrument icc serial_poisson.cpp -o serial_app


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
