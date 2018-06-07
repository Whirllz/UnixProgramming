#include<dirent.h>
// DIR and dirent structures are pre-defined in "dirent.h"
#include<stdio.h>
//printf() is pre-defined in "stdio.h>"

// argv[0] is ./a.out
// argc has a count of no. of arguments including ./a.out
int main(int argc, char const *argv[])
{
    DIR *dp;
    struct dirent *dirp;
   
    if((dp=opendir(argv[1]))==NULL){      // argv[1] is 2nd argument in command line
    	printf("Cant open %s",argv[1]);
    }

    while((dirp=readdir(dp))!=NULL)
     	printf("%s\n",dirp->d_name);    //d_name is a variable in dirent structure
    
    closedir(dp);                     
	return 0;
}