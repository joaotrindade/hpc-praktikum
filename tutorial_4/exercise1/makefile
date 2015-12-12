ex1: clean gauss

gauss: gauss.c timer.c timer.h
	icc -O3 gauss.c timer.c -o gauss_icc_enable_profile.exe -pg -g
	icc -O3 gauss.c timer.c -o gauss_icc_disable_profile.exe -g
	gcc -O3 gauss.c timer.c -o gauss_gcc_enable_profile.exe -pg -g
	gcc -O3 gauss.c timer.c -o gauss_gcc_disable_profile.exe -g

clean:
	rm -rf *.o
	rm -rf *.out
	rm -rf *.exe
