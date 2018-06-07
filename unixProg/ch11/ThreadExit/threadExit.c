// This example is used to show how to fetch exit status of threads

// To run : $gcc -pthread -o exitEg threadExit.c (create exe files)
// $./exitEg  (for output)

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
// pthread_t,pthread_self,pthread_create() are pre-defined in "pthread.h"
#include<string.h>


void * threadFun1(void *arg){
    printf("Returning from Thread1\n");
	return((void*)1);
}

void * threadFun2(void *arg){
    printf("Exiting from Thread2\n");
	pthread_exit((void*)2);
}


int main(int argc, char const *argv[])
{
	int error;
	pthread_t tid1,tid2;
	void * tret;

	error = pthread_create(&tid1,NULL,threadFun1,NULL);
	if(error!=0){
		printf("Can't create thread %s\n",strerror(error));
		exit(-1);
	}
	
	error = pthread_create(&tid2,NULL,threadFun2,NULL);
	if(error!=0){
		printf("Can't create thread %s\n",strerror(error));
		exit(-1);
	}
	
	error = pthread_join(tid1,&tret);
	if(error!=0){
		printf("Thread join error %s\n",strerror(error));
		exit(-1);
	}
	printf("Thread1 exit : %d\n",(int)tret);

	error = pthread_join(tid2,&tret);
	if(error!=0){
		printf("Thread join error %s\n",strerror(error));
		exit(-1);
	}
	printf("Thread2 exit : %d\n",(int)tret);

	return 0;
}
