#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char **argv) {

	int rank, size, error;
	MPI_Init( &argc, &argv );
	MPI_Comm_size( MPI_COMM_WORLD, &size );
	MPI_Comm_rank( MPI_COMM_WORLD, &rank );
	
	if (rank == 0 ) {
		cout << "main process" << endl;
	}
	else {
		cout << "rank: " << rank << endl;	
	}

	return 0;
}