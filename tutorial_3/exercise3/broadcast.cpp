#include <iostream>
#include <stdlib.h>
#include <string>
#include <mpi.h>

using namespace std;
#define TRIVIAL_TAG 1
#define TREE_TAG 2

long ARRAY_SIZE;
int mpi_rank, comm_size;
MPI_Status status;


void trivial_send(double *array) {
	if (mpi_rank == 0) {
		for (int i = 1; i < comm_size; i++) {
			MPI_Send(array, ARRAY_SIZE, MPI_DOUBLE, i,TRIVIAL_TAG,MPI_COMM_WORLD);
		}
	} else {
		MPI_Recv(array,ARRAY_SIZE,MPI_DOUBLE,0,TRIVIAL_TAG,MPI_COMM_WORLD, &status);
	}
}


int main(int argc, char **argv) {

	char processor_name[250];
    int name_len;
    double start_time, end_time;
    
    
	MPI_Init( &argc, &argv );
	
	MPI_Comm_size( MPI_COMM_WORLD, &comm_size );
	MPI_Comm_rank( MPI_COMM_WORLD, &mpi_rank );
	MPI_Get_processor_name(processor_name, &name_len);
	
	if ((argc < 2) && (mpi_rank==0)) {
		cout << "ERROR. Please specify array size" << endl;
		return 0;
	}
	else {
		ARRAY_SIZE = atol(argv[1]);
	}
	
	MPI_Request request_array[comm_size];
    MPI_Status status_array[comm_size];
	double array[ARRAY_SIZE];
	
	/*
	if (mpi_rank == 0 ) {
		cout << "main process" << " name: " << processor_name  << endl;	
		cout << "ARRAY_SIZE: " << ARRAY_SIZE << endl;
	}
	else {
		cout << "rank: " << mpi_rank << " name: " << processor_name  << endl;	
	}*/
	
	if (mpi_rank==0) start_time = MPI_Wtime();
	trivial_send(array);
	
	if (mpi_rank==0) {
		end_time = MPI_Wtime();
		printf("Size of dataset: %d, elapsed time[s] %e \n", ARRAY_SIZE, end_time-start_time);
	}
	
	MPI_Finalize();
}