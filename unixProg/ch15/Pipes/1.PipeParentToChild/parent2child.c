// This example illustrates use of pipe for IPC between parent and child.

/* Parent-child communicate through the pipe,for pipe from parent to child :-
   parent writes on write end of the pipe and closes the read end 
   and child reads from read end of the pipe and closes the write end
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define MAX 100

int main()
{
	int fd[2];
	pid_t pid;
	char bufin[MAX];
	char * bufout;
	int n;

	if(pipe(fd)==-1){               // pipe returns 0 if OK, -1 on error
		printf("pipe error\n");
		exit(EXIT_FAILURE);
	}

	if((pid=fork())<0){
		printf("fork error\n");
		exit(EXIT_FAILURE);
	}

	if(pid>0){                       // parent process   
       close(fd[0]);                // close read end, write through write end of pipe
       bufout = "Hello world\n";
       write(fd[1],bufout,strlen(bufout));
	}
	else{                           //child process
       close(fd[1]);               // close write end,read through read end of pipe
       n = read(fd[0],bufin,MAX);
       write(1,bufin,n);          // Write on stardard output to display to user
	}
	return 0;
}