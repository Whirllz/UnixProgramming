
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
// wait() is pre-defined in "sys/wait.h"

void waitexample()
{
    int stat;
 
    // This status 3 is reported by WEXITSTATUS
    if (fork() == 0)
        exit(3);
    else
        wait(&stat);
    if (WIFEXITED(stat))
        printf("Exit status: %d\n", WEXITSTATUS(stat));
    else if (WIFSIGNALED(stat))
        printf("Exit signal: %d\n",WTERMSIG(stat));
}
 
// Driver code
int main()
{
    waitexample();
    return 0;
}