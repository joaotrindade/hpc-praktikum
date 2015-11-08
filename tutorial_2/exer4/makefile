all: sequential.out parallelize.out

parallelize.out: parallelize_dgemm.o timer.o
	gcc -g -fopenmp -o parallelize.out parallelize_dgemm.o timer.o

parallelize_dgemm.o: parallelize_dgemm.c timer.o
	gcc -g -O0 -fopenmp -c -o parallelize_dgemm.o parallelize_dgemm.c

sequential.out: dgemm.o timer.o
	gcc -g -fopenmp -o sequential.out dgemm.o timer.o

dgemm.o: sequential_dgemm.c timer.o
	gcc -g -O0 -fopenmp -c -o dgemm.o sequential_dgemm.c

timer.o: timer.c
	gcc -g -O0 -fopenmp -c -o timer.o timer.c

clean:
	rm -rf *.o
	rm -rf cachegrind.out.*
	rm -rf cg.out
	rm -rf *.out
	rm -rf *.txt
	rm -rf *.png
	rm -rf ./generated_data/*
