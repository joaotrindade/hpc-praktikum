exe: driver.o openmp_reduction.o openmp_critical.o serial.o timer.o
	g++ -fopenmp -o exe driver.o openmp_reduction.o openmp_critical.o serial.o timer.o

driver.o: driver.cpp timer.o
	g++ -fopenmp -c -o driver.o driver.cpp

openmp_reduction.o: openmp_reduction.cpp timer.o
	g++ -fopenmp -c -o openmp_reduction.o openmp_reduction.cpp

openmp_critical.o: openmp_critical.cpp timer.o
	g++ -fopenmp -c -o openmp_critical.o openmp_critical.cpp

serial.o: serial.cpp timer.o
	g++ -fopenmp -c -o serial.o serial.cpp

timer.o: timer.cpp
	g++ -fopenmp -c -o timer.o timer.cpp

clean:
	rm -rf *.o
	rm -rf ./exe
	rm -rf ./generated_data/*.txt
	rm -rf *.txt
