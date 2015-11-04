all: quicksort seq

seq: quicksort-seq.c
	icc quicksort-seq.c timer.c -o quicksort-seq.out

quicksort: quicksort.c
	icc -openmp quicksort.c timer.c -o quicksort.out

timer.o: timer.c timer.h
	icc timer.c -c

clean:
	rm -rf *.o
	rm -rf cachegrind.out.*
	rm -rf cg.out
	rm -rf matrix
