// This example prints process IDs and thread IDs
// Note that process Ids are same, while the thread Ids diifer

// To run : $gcc -pthread -o threadid ThreadID.c (create exe files)
// $./threadid  (for output)

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
// pthread_t,pthread_self,pthread_create() are pre-defined in "pthread.h"
#include<string.h>

pthread_t ntid;

void printId(const char *str){
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();

	printf("%u --> pid %u --> tid \n",(unsigned int)pid,(unsigned int)tid);
}

void * threadFun(void *arg){
	printId("New Thread : ");
	return((void*)0);
}

int main(int argc, char const *argv[])
{
	int error;
	error = pthread_create(&ntid,NULL,threadFun,NULL);
	
	if(error!=0){
		printf("Can't create thread %s\n",strerror(error));
		exit(-1);
	}
	
	printId("Main Thread : ");
	
	sleep(1);
	return 0;
}

