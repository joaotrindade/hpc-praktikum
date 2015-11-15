all: clean broadcast

broadcast: broadcast.cpp
	mpicc broadcast.cpp -o broadcast.o

clean:
	rm -rf *.o
	rm -rf cachegrind.out.*
	rm -rf cg.out
	rm -rf matrix
