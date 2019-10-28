
#include <stdlib.h>
#include <stdio.h>
#define MAXCHAR 1000

int main(int argc, char** argv)
{
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
    for(int j = 0; j < 64; j++){
        printf("index %d = %d\n",j,arr[j]);
    }
    
}
    
    
