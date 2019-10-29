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

    
    int *sum0,*sum1;
   
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
    
    int *array = (int*)(malloc(sizeof(int)*64));
    
    if(rank == 0)
      {
          array = arr;
      }
    MPI_Bcast(&array, 64, MPI_INT, 0, MPI_COMM_WORLD);

    if(rank == 0){
       
        sum0 = 0;
        int i;
        for(i = 0; i < 16; i++){
            sum0 += array[i];
        }
        
    }
    if(rank == 1){
        
        sum0 = 0;
        int j;
        for(j = 16; j < 32; j++){
            sum0 += array[j];
        }
    }
    else if(rank == 2){
        
        sum0 = 0;
        int k;
        for(k = 32; k < 48; k++){
            sum0 += array[k];
        }
    }
    else if(rank == 3){
     
      sum0 = 0;
      int r;
      for(r = 48; r < 64; r++){
          sum0 += array[r];
      }
    }
    
    MPI_Reduce(sum0,sum1,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
    if(rank == 0){
        printf("Sum: %d",sum1);
    }
    
    
    MPI_Finalize();
    return 0;
}

