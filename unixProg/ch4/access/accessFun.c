#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>	
int main(int argc, char const *argv[])
{
	if( argc != 2){
		printf("provide the pathname \n");
		exit(0);
	}

	if(access(argv[1],R_OK) < 0)
		printf("Access error for %s\n",argv[1]);
	else
		printf("Read access OK\n");
	if(open(argv[1],O_RDONLY) < 0)
		printf("Open error for %s\n",argv[1]);
	else
		printf("Open for reading OK \n");

	exit(0);
}