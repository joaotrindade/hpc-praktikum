#include <iostream>
#include <stdlib.h>
#include <string>
#include <mpi.h>

using namespace std;
long ARRAY_SIZE;

int main(int argc, char **argv) {

	int rank, size, error;
	char processor_name[250];
    int name_len;
	MPI_Init( &argc, &argv );
	
	MPI_Comm_size( MPI_COMM_WORLD, &size );
	MPI_Comm_rank( MPI_COMM_WORLD, &rank );
	MPI_Get_processor_name(processor_name, &name_len);
	
	if ((argc < 2) && (rank==0)) {
		cout << "ERROR. Please specify array size" << endl;
		return 0;
	}
	else {
		ARRAY_SIZE = atol(argv[1]);
	}
	
	if (rank == 0 ) {
		cout << "main process" << " name: " << processor_name  << endl;	
		cout << "ARRAY_SIZE: " << ARRAY_SIZE << endl;
	}
	else {
		cout << "rank: " << rank << " name: " << processor_name  << endl;	
	}

	return 0;
}