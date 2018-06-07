#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
	int val;

	if(argc !=2)
		printf("Provide a file Descriptor");

	if((val = fcntl(atoi(argv[1]),F_GETFL,0)) < 0 )
		printf("fcntl error");

	switch(val & O_ACCMODE){
		
		case O_RDONLY : printf("read only"); break;

		case O_WRONLY : printf("write only"); break;
		 
		case O_RDWR : printf("read-write"); break;
	}

	if(val & O_APPEND)
		printf(", append");
	if(val & O_NONBLOCK)
		printf(", nonblocking");
    
    printf("\n");
	exit(0);
}