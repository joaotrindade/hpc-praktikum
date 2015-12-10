all: clean naive optimised

naive: naive_dgemm.c
	gcc -g -o naive_app naive_dgemm.c

optimised: optimized_dgemm.c
	gcc -g -o optimized_app optimized_dgemm.c

clean:
	rm -rf *.o
	rm -rf cachegrind.out.*
	rm -rf cg.out
	rm -rf *.out
	rm -rf *.txt
	rm -rf *.png
