#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
// chmod() is pre-defined in "sys/stat.h"
#include<fcntl.h>
#include<unistd.h>
// Note that we have created the file foo with all file permssions, but if we do "ls -l" on 
// command line after running this program "foo" has file permissions specified in chmod()

int main(){

	int fd;

	if((fd = open("foo",0777)) == -1){
		printf("Error open");
		exit(0);
	}
    
    if(chmod("foo",S_IRWXU|S_IRGRP|S_IROTH) < 0){
    	printf("Error in chmod");
    	exit(0);
    }
    
    return 0;
}