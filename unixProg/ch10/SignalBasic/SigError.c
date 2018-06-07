// This program illustrates use of SIG_ERR and raise() 

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
 
void signal_handler(int signal)
{
    printf("Received signal %d\n", signal);
}
 
int main(void)
{
    if (signal(SIGTERM, signal_handler) == SIG_ERR)
    {
        printf("Error installing signal handler.\n");
        exit(-1);
    }
 
    printf("Sending signal %d\n", SIGTERM);
    if (raise(SIGTERM) != 0)                //raise() is used to raise a signal
    {
        printf("Raise error the SIGTERM signal.\n");
        exit(-1);
    }
 
    printf("Exit main()\n");
    return 0;
}