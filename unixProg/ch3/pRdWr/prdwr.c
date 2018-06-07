#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
// pread() and pwrite() are pre-defined in "unistd.h" 
#include<fcntl.h>

#define BUFMAX 100

int main(){
	
	int fd,n;
	char buf[BUFMAX];

	if( (fd = open("Eg1.txt",O_RDWR)) < 0)
		printf("Open error");

    while( (n = pread(fd,buf,BUFMAX,0)) > 0){
      if( pwrite(STDOUT_FILENO,buf,n,0) != n )
        printf("Write error");
    }
    if(n<0)
    	printf("Read error");

    exit(0);
}
