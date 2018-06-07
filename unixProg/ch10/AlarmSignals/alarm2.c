// Beautiful example on alarm()
// Here the child process exits when alarm calls handler despite the process 
// still needs to do some work, but it exits in handler

// Parent waits till child terminates then it runs till alarm signal is caught
// and parent gets terminated

#include <stdio.h>
#include <stdlib.h> //for exit() function
#include <unistd.h>
#include <signal.h>
#include <wait.h>
#include <sys/types.h>

static void catchAlarm(int signo){
    printf("Caught an SIGALRM signal.\n");
    printf("Signal value = %d\n", signo);

    printf("Exiting from process...\n");

    exit(EXIT_SUCCESS);      // same as exit(0)
 
}

int main(void){

    int status;
    pid_t pid;
    
    signal(SIGALRM, catchAlarm);
    pid = fork();

    if(pid < 0){
        printf("Problem forking process.\n");
        printf("Exiting now...\n");
        exit(EXIT_FAILURE);
    }

    if(pid==0){
        alarm(5);
        for(int i = 0; i < 7; i++){
            printf("In child process... %d\n", i);
            sleep(1);
        }
    } else     {
        wait(&status);
        alarm(7);
        for(int i = 0; i < 15; i++){
            printf("In parent process... %d\n", i);
            sleep(1);
        } 
    }

}