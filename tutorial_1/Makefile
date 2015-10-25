all: gauss 

gauss: gauss.c timer.o
	icc gauss.c -o gauss timer.o

timer.o: timer.c timer.h
	icc timer.c -c