// This program creates a file foo with umask as provided by the user
// (all bits are "on" in file mode)
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
//umask is pre-defined in "sys/stat.h"
#include<fcntl.h>
// run "umask" command on command line and check parent process umask is not affected before 
// or after this program (child-process) is run
int main(){

	mode_t uMask;
	
	printf("Enter the umask value you want(in octal[0xxx]): ");
	scanf("%i",&uMask);             // Give file Mode creation mask for file

	umask(uMask);  

	if( creat("foo",0777) < 0){   // All bits are 'on' for the file foo in file mode 
		printf("Creat error ");
		exit(0);
	}

    printf("File succesfully made with provided umask value \n");
	exit(0);
}