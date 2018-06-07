// Example on user-defined signal handler 
// Here SIGINT -- user keyboard interrupt signal
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
// signal() is pre-defined in "signal.h"
#include<unistd.h>
// sleep() is pre-defined in "unistd.h"

static void handler(int sno){            // prints signal no on receipt of signal
	printf("Signal caught : %d\n",sno);
	exit(0);
}
 
int main()
{
    signal(SIGINT, handler);  // The default action is to terminate the process
    while (1)
    {
        printf("Hello NITPY\n");
        sleep(1);
    }
    return 0;
}