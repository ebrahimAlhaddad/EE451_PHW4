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

    
    int sum0,sum1,sum2,sum3;
    if(rank == 0){
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
        MPI_Bcast(&, 10, MPI_CHAR, 0, MPI_COMM_WORLD);

    }
    else if(rank == 1){
        int* array = arr;
        sum1 = 0;
        int i;
        for(i = 0; i < 16; i++){
            sum1 += array[i];
        }
        MPI_Send(&sum1, 1, MPI_INT, 0, 200, MPI_COMM_WORLD);
    }
    else if(rank == 2){
        int* array = arr;
        sum2 = 0;
        int i;
        for(i = 32; i < 48; i++){
            sum2 += array[i];
        }
        MPI_Send(&sum2, 1, MPI_INT, 0, 200, MPI_COMM_WORLD);
    }
    else if(rank == 3){
      int* array = arr;
      sum3 = 0;
      int i;
      for(i = 48; i < 64; i++){
          sum3 += array[i];
      }
      MPI_Send(&sum3, 1, MPI_INT, 0, 200, MPI_COMM_WORLD);
    }
    
    
    MPI_Finalize();
    return 0;
}

