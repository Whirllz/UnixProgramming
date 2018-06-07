// This program writes two char arrays in a file file.NoHole and the file is closed.
// The file is again opened to seek till start of second char array and written in STDOUT.
#include<stdio.h>
// perror() is pre-defined in "stdio.h"
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
//errno is specified in "errno.h" 

#define BMAX 100

int main(){
    
    char buf1[] = "theWorldIs";
    char buf2[] = "WhatUMake!";
    char buf3[BMAX];
    int count;
    int fd,n;

    if((fd = creat("file.NoHole",0777)) < 0)
    {
    	printf("creat error");
        exit(0);
    }
   

    count = sizeof(buf1);

    if( write(fd,buf1,count) < count)
    	printf("Write error");

    if( write(fd,buf2,count) < count)
    	printf("buf2 write error");
    
    close(fd);

    if(( fd = open("file.NoHole",O_RDWR)) < 0)
    {
        printf("Open error");
        printf("ERRNO : %d\n",errno);
        perror("Open Error :");
        exit(0);
    }

    if( lseek(fd,count,SEEK_SET) == -1 )
        printf("Seek error");
    
    while( (n = read(fd,buf3,BMAX)) >  0){
        if( write(STDOUT_FILENO,buf3,n) < n)
            printf("Write error");
    }
    if(n < 0)
        printf("Read error");

	exit(0);
}