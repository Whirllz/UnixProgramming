#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
// read() and write() are pre-defined in "unistd.h"

#define BUFFSIZE 1024

int main(){
	int n;
	char buf[BUFFSIZE];
    
    // For every Enter u type there is a line read and written 
    // For quiting from the output press (CTRL+D)
	while((n=read(STDIN_FILENO,buf,BUFFSIZE))>0){
		if(write(STDOUT_FILENO,buf,n)!=n){
			printf("Error writing");
		}
	}
	if(n<0){
		printf("Error reading");
	}
	exit(0);
}