all: sequential.out

sequential.out: dgemm.o timer.o
	gcc -g -fopenmp -o sequential.out dgemm.o timer.o
	rm -rf *.o

dgemm.o: dgemm.c timer.o
	gcc -g -O0 -fopenmp -c -o dgemm.o dgemm.c

timer.o: timer.c
	gcc -g -O0 -fopenmp -c -o timer.o timer.c

clean:
	rm -rf *.o
	rm -rf cachegrind.out.*
	rm -rf cg.out
	rm -rf sequential.out
	rm -rf *.txt
