OLD  := MMult_1x4_7
NEW  := MMult_1x4_8 
all: matrix

matrix: dgemm.c timer.o
	icc dgemm.c -o matrix timer.o

timer.o: timer.c timer.h
	icc timer.c -c

clean:
	rm -rf *.o
	rm -rf cachegrind.out.*
	rm -rf cg.out
	rm -rf matrix
