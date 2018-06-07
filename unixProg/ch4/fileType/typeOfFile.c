#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
// File type Macros are pre-defined in "sys/stat.h"
// stat(), fstat(), lstat() are pre-defined in "sys/stat.h" 

int main(int argc, char const *argv[])
{
	int i;
	struct stat buf;
	char * type;

    if(argc!=2){                     // argv[0] is ./a.out and argv[1] is fileName
    	printf("provide a file");
    	exit(0);
    }

    if( lstat(argv[1],&buf) < 0){    // lstat returns -1 on error and 0 if OK
    	printf("lstat error");
    	exit(-1);
    }
    if(S_ISREG(buf.st_mode))
    	type = "regular file";
    else if(S_ISDIR(buf.st_mode))
    	type = "directory";
    else if(S_ISCHR(buf.st_mode))
    	type = "character special file";
    else if(S_ISBLK(buf.st_mode))
    	type = "block special file";
    else if(S_ISFIFO(buf.st_mode))
    	type = "FIFO or pipe";
    //else if(S_ISLINK(buf.st_mode))
    //	type = "symbolic link";
    else if(S_ISSOCK(buf.st_mode))
    	type = "socket";
    else 
    	type = "unknown mode";
    
   printf("%s\n ", type);
	
 exit(0);
}
