#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
// getpid() is pre-defined in "unistd.h"

int main(){
	printf("The process id is: %d\n",getpid());
	exit(0); 
}