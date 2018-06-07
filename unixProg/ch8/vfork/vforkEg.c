#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int i=5;
int j=0;

int main()
{ 
	pid_t pid;

	if((pid=vfork())<0){
		printf("vfork error");
		exit(-1);
	}
	if(pid==0){    // Child works on parent's memory until it calls exit() or exec()
          i++;               
          j++;
          exit(0);
	}
	else{    // Parent waits automatically for child's exit() or exec() by default
		
	}
	// Child had exited before this is run by parent on the modified data by child
	printf("i=%d and j=%d\n",i,j);
    
	return 0;
}