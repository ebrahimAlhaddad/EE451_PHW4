#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char** argv){
    int size, rank;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    int b;
	
	if (rank == 0) {
        buf = 451;
        MPI_Send( &buf, 1, MPI_INT, 1, 200, MPI_COMM_WORLD);
    }
    else if (rank == 1) {
        MPI_Recv( &buf, 1, MPI_INT, 0, 200, MPI_COMM_WORLD, &status);
        printf( “Received %d\n”, buf );
    }

    printf("Process %d: %d \n",  rank, b);

    MPI_Finalize();
    return 0;
}
