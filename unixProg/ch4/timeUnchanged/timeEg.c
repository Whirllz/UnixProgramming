#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<utime.h>
// utime() is pre-defined in "utime.h"
#include<sys/stat.h>

int main(int argc, char const *argv[])
{
	int i,fd;

	struct stat statbuf;
	struct utimbuf timebuf;


	for( i=1;i<argc;i++){

		if( stat(argv[i],&statbuf) < 0){              // current time taken in statbuf
			printf("%s : Stat error\n",argv[i] );
			continue;
		}
		if((fd = open(argv[i],O_RDWR | O_TRUNC)) < 0 ){    // truncate the file
			printf("%s : Open error",argv[i]);
			continue;
		}
		close(fd);

		timebuf.actime = statbuf.st_atime;        
		timebuf.modtime  = statbuf.st_mtime;

		if(utime(argv[i], &timebuf)< 0){            //reset times to old values taken from statbuf
			printf("%s : utime error",argv[i]);
			continue;
		}

	}
	exit(0);
}
