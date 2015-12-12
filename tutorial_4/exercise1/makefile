#https://www.lrz.de/services/compute/supermuc/tuning/gprof/
ex1: clean gauss

gauss: gauss.c timer.c timer.h
	icc gauss.c timer.c -o gauss_icc_enable_profile.exe -pg -O0 
	icc gauss.c timer.c -o gauss_icc_disable_profile.exe -g -O0
	gcc gauss.c timer.c -o gauss_gcc_enable_profile.exe -pg -O0
	gcc gauss.c timer.c -o gauss_gcc_disable_profile.exe -g -O0

clean:
	rm -rf *.o
	rm -rf *.out
	rm -rf *.exe
	rm -rf *.txt
