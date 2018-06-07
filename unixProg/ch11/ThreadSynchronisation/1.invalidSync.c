// This example shows the synchronization problem when two threads want
// to access a shared variable "counter" 

// Run to see the undesired output

//To run:$gcc invalidSyn.c -lpthread (Since we need to link with multi-thread library)
// ./a.out (for output)


#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

// The actual problem is the usage of the variable ‘counter’ by second thread
// when the first thread was using or about to use it. 
pthread_t tid[2];
int counter;
 
void* fun(void *arg)
{
    unsigned long i = 0;
    counter += 1;
    printf("\n Job %d has started\n", counter);
 
    for(i=0; i<(0xFFFFFFFF);i++);
    printf("\n Job %d has finished\n", counter);
 
    return NULL;
}
 
int main()
{
    int i = 0;
    int error;
 
    while(i < 2)
    {
        error = pthread_create(&(tid[i]), NULL, &fun, NULL);
        if (error != 0)
            printf("\nThread can't be created : [%s]", strerror(error));
        i++;
    }
 
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
 
    return 0;
}