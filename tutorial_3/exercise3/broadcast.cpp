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
		for (long i = 1; i < comm_size; i++) {
			MPI_Send(array, ARRAY_SIZE, MPI_DOUBLE, i,TRIVIAL_TAG,MPI_COMM_WORLD);
		}
	} else {
		MPI_Recv(array,ARRAY_SIZE,MPI_DOUBLE,0,TRIVIAL_TAG,MPI_COMM_WORLD, &status);
	}
}

void tree(double *array, long start_index, long final_index) {
	if (start_index == final_index) return;
	long middle_index = (start_index + final_index + 1)/2;
	
	if (mpi_rank == start_index){
		MPI_Send(array, ARRAY_SIZE, MPI_DOUBLE, middle_index,TREE_TAG,MPI_COMM_WORLD);
	}
	else if (mpi_rank == middle_index) {
		MPI_Recv(array,ARRAY_SIZE,MPI_DOUBLE,start_index,TREE_TAG,MPI_COMM_WORLD, &status);
	}
	
	tree(array,start_index,middle_index-1);
	tree(array,middle_index,final_index);
}

void tree_send(double *array)
{
	tree(array, 0, comm_size-1);
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
	
	/** TEST TRIVIAL SEND **/
	MPI_Barrier(MPI_COMM_WORLD);
	if (mpi_rank==0) start_time = MPI_Wtime();
	trivial_send(array);
	MPI_Barrier(MPI_COMM_WORLD);
	if (mpi_rank==0) {
		end_time = MPI_Wtime();
		printf("[TRIVIAL]Dataset: %d, P= %d,elapsed time[s] %e \n", ARRAY_SIZE,comm_size,end_time-start_time);
	}
	
	/** TEST TREE SEND **/
	MPI_Barrier(MPI_COMM_WORLD);
	if (mpi_rank==0) start_time = MPI_Wtime();
	tree_send(array);
	MPI_Barrier(MPI_COMM_WORLD);
	if (mpi_rank==0) {
		end_time = MPI_Wtime();
		printf("[TREE]   Dataset: %d, P= %d,elapsed time[s] %e \n", ARRAY_SIZE,comm_size,end_time-start_time);
	}
	
	/** TEST MPI_BCAST SEND **/
	MPI_Barrier(MPI_COMM_WORLD);
	if (mpi_rank==0) start_time = MPI_Wtime();
	MPI_Bcast(array,ARRAY_SIZE,MPI_DOUBLE,0,MPI_COMM_WORLD);
	MPI_Barrier(MPI_COMM_WORLD);
	if (mpi_rank==0) {
		end_time = MPI_Wtime();
		printf("[MPI_BCAST]   Dataset: %d, P= %d,elapsed time[s] %e \n", ARRAY_SIZE,comm_size,end_time-start_time);
	}
	
	MPI_Finalize();
}