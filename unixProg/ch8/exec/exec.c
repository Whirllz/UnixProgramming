#include<stdio.h>
#include<unistd.h>
 
int main()
{
    int i;
    
    printf("I am exec.c called by execvp() ");
    printf("\n");
    printf("process id is : %d\n",getpid()); 
    return 0;
}