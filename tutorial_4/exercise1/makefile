ex1: clean lu gauss-vecto gauss

lu: lu-factorization.c
	icc  -std=c99 -O3 -qopt-report=5 -qopt-report-phase=vec lu-factorization.c timer.c -o gauss_lu_factorization_app

gauss-vecto: gauss-vecto.c
	icc  -std=c99 -O3 -qopt-report=5 -qopt-report-phase=vec gauss-vecto.c timer.c -o gauss_vector_app

gauss: gauss.c
	icc gauss.c timer.c -o gauss_app

timer.o: timer.c timer.h
	icc timer.c -c

clean:
	rm -rf *.o
	rm -rf cachegrind.out.*
	rm -rf cg.out
