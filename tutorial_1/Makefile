OLD  := MMult_1x4_7
NEW  := MMult_1x4_8 
all: matrix

matrix: dgemm.c timer.o
	icc dgemm.c -o matrix timer.o

lu: lu-factorization.c
	icc  -std=c99 -O3 -qopt-report=5 -qopt-report-phase=vec lu-factorization.c timer.c -o lu-factorization

gauss-vecto: gauss-vecto.c
	icc  -std=c99 -O3 -qopt-report=5 -qopt-report-phase=vec gauss-vecto.c timer.c -o gauss-vecto

gauss: gauss.c
	icc gauss.c timer.c -o gauss

timer.o: timer.c timer.h
	icc timer.c -c

clean:
	rm -rf *.o
	rm -rf cachegrind.out.*
	rm -rf cg.out
	rm -rf matrix
