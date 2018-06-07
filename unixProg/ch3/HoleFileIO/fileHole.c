// Compare files fileHole.c to fileNoHole.c to see that holes in a file does 
// not take disk space. Rather they are stored as meta data info. of the file.

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
// creat(), open() are pre-defined in "fcntl.h"
#include<unistd.h>
// read(), write(), lseek(), close() are pre-defined in "unistd.h"
int main(){
    
    char buf1[] = "abcdefghij";
    char buf2[] = "ABCDEFGHIJ";

    int fd;
    int fromBegGap = 1024;
    int count1 = sizeof(buf1);
    int count2 = sizeof(buf2);


    if((fd = creat("file.hole",00777)) < 0)
    	printf("creat error");
    
    if( write(fd,buf1,count1) != count1)
    	printf("buf1 Write error");

    if( lseek(fd,fromBegGap,SEEK_SET) == -1)
    	printf("lseek error");

    if( write(fd,buf2,count2) != count2)
    	printf("buf2 write error");

	exit(0);
}