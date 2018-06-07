#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
// waitpid is pre-defined in "sys/wait.h"
#include<unistd.h>
// fork() and execlp() are pre-defined in "unistd.h"
#include<string.h>
// strlen() is pre-defined in "string.h"
#define MAXLINE 1024
// maximum lines to be read by fgets()

// Following code does not allow to pass arguments to a Command

int main(){
	
	char buf[MAXLINE];
    pid_t pid;
    int status;

    printf(" *Command* : ");                          // To prompt for command

    while(fgets(buf,MAXLINE,stdin) != NULL){            
    	if(buf[strlen(buf)-1] == '\n')
    		buf[strlen(buf)-1] = 0;                 // Replace newLine with NULL

        if((pid = fork())< 0)                      // fork returns -1 on failure
        	printf("Error in fork"); 

        // child process    
        else if( pid == 0){                      // A child process executes command
        	printf("Child-pid : %d \n",getpid());
        	execlp(buf,buf,(char *)0);
        	
        	printf("%s execution failed",buf);
        	exit(1);
        }

        // parent process
        // Note that the parent remains same while a child is created and dies in each loop
        printf("Parent-pid : %d \n",getpid());
        if((pid = waitpid(pid,&status,0)) < 0) // Parent waits till child process completes. Check child pid.
        	printf("Error in waitpid");
        printf(" *Command* : ");
    }
    exit(0);
}
