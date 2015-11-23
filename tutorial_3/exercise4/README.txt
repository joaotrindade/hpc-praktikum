***** Execute folliwng commands to build and run the application manually *****

 $ make
 $ sh run.sh
 $ mpirun -np 196 ./mpi_app 2000 1000 0.0001 14 14


***** for automation script run following commands *****
 $ make
 $ sh run.sh
 $ sh collect_data.sh


*******************************************************************************************************
NOTE 1: Generated performance analysis will be stored in performance_analysis.txt in current directory.
NOTE 2: Result that we had generated while testing on cluster has been processed in arranged way in 
        COLLECTED_DATA_AND_GRAPH.pdf in current directory

NOTE 3: Generated files:
	* b.gnuplot
	* initial_condition_parallel.gnuplot
	* mpi_app
	* performance_analysis.txt
	* serial_app
	* serial_b.gnuplot
	* serial_initial_condition.gnuplot
	* serial_solution.gnuplot
	* solution_parallel.gnuplot
*******************************************************************************************************

