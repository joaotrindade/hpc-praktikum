all: clean broadcast

broadcast: mpi_poisson.cpp
	mpicc mpi_poisson.cpp -o mpi_app

clean:
	rm -rf *.o
	rm -rf cachegrind.out.*
	rm -rf cg.out
	rm -rf mpi_app
