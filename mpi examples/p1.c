#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
int main(int argc, char** argv)
{
    int message, size, rank;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    
    if(rank == 0){
        message = 451;
        printf("Initially Process: %d. Message: %d \n", rank, message);
        MPI_Send(&message, 1, MPI_INT, 1, 200, MPI_COMM_WORLD);
        MPI_Recv(&message, 1, MPI_INT, 3, 200, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        printf("Process: %d. Message: %d Done\n", rank, message);
    }
    else if(rank == 1){
        MPI_Recv(&message, 1, MPI_INT, 0, 200, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        message += 1;
        printf("Process: %d. Message: %d \n", rank, message);
        MPI_Send(&message, 1, MPI_INT, 2, 200, MPI_COMM_WORLD);
    }
    else if(rank == 2){
        MPI_Recv(&message, 1, MPI_INT, 1, 200, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        message += 1;
        printf("Process: %d. Message: %d \n", rank, message);
        MPI_Send(&message, 1, MPI_INT, 3, 200, MPI_COMM_WORLD);
    }
    else if(rank == 3){
        MPI_Recv(&message, 1, MPI_INT, 2, 200, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        message += 1;
        printf("Process: %d. Message: %d \n", rank, message);
        MPI_Send(&message, 1, MPI_INT, 0, 200, MPI_COMM_WORLD);
    }
    
    
    MPI_Finalize();
    return 0;
}

