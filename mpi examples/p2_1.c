#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define MAXCHAR 1000

int main(int argc, char** argv)
{
    int size, rank;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    int *arr = (int*)(malloc(sizeof(int)*64));
    FILE *fp;
       char str[MAXCHAR];
       char* filename = "number.txt";
       fp = fopen(filename, "r");
       if (fp == NULL){
           printf("Could not open file %s",filename);
           return 1;
       }
    int i = 0;
    while (fgets(str, MAXCHAR, fp) != NULL){
        int num = atoi(str);
        arr[i] = num;
        i += 1;
    }
    fclose(fp);
    
    
    if(rank == 0){
        
    }
    else if(rank == 1){
        MPI_Recv(&message, 1, MPI_INT, 0, 200, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        message += 1;
        MPI_Send(&message, 1, MPI_INT, 2, 200, MPI_COMM_WORLD);
        printf("Process: %d. Message: %d \n", rank, message);
    }
    else if(rank == 2){
        MPI_Recv(&message, 1, MPI_INT, 1, 200, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        message += 1;
        MPI_Send(&message, 1, MPI_INT, 3, 200, MPI_COMM_WORLD);
        printf("Process: %d. Message: %d \n", rank, message);
    }
    else if(rank == 3){
        MPI_Recv(&message, 1, MPI_INT, 2, 200, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        message += 1;
        MPI_Send(&message, 1, MPI_INT, 0, 200, MPI_COMM_WORLD);
        printf("Process: %d. Message: %d \n", rank, message);
    }
    
    
    MPI_Finalize();
    return 0;
}

