#include<stdio.h>
#include <sys/types.h>
#include<unistd.h>

void example() 
{
    // child process because return value is zero
    if (fork()==0)
        printf("Hello from Child!\n");
 
    // parent process because return value non-zero(process id of child)
    else    
        printf("Hello from Parent!\n"); 
}
int main()
{ 
    example();
    return 0; 
}