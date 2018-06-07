
//Example on malloc,calloc,realloc and free for heap memory allocation
// All mem allocation functions are pre-defined in "stdlib.h" 
#include<stdio.h>
#include<stdlib.h>


int main(){

   int i;

   int * ptr = (int *)malloc(sizeof(int)*5);

   int * ptr1 = (int *)calloc(5,sizeof(int));

   free(ptr1);

   ptr1 = (int *)realloc(ptr,sizeof(int)*10);

   free(ptr);
   free(ptr1);

   return 0;
}