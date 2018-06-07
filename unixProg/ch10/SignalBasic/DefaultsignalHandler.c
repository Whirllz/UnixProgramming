// Example on defualt signal handler -- the defualt action is to terminate
// the process on a signal(here SIGINT -- user keyboard interrupt signal)
#include<stdio.h>
#include<signal.h>
// signal() is pre-defined in "signal.h"
#include<unistd.h>
// sleep() is pre-defined in "unistd.h"

 
int main()
{
    signal(SIGINT, SIG_DFL);  // The default action is to terminate the process
    while (1)
    {
        printf("Hello NITPY\n");
        sleep(1);
    }
    return 0;
}