#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int i=5;
int j=0;

int main()
{ 
	pid_t pid;

	if((pid=fork())<0){
		printf("fork error");
		exit(-1);
	}
	if(pid==0){         //Child process         
          i++;               
          j++;
	}
	else{              //Parent process
	 	sleep(3);
	}
	// Increment in values of i and j are seen in child, but parent's values
	// are same
	printf("i=%d and j=%d\n",i,j);
    
	return 0;
}