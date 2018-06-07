#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
// Note that the process ids of both the processes are same
int main()
{
      	printf("process id is : %d\n",getpid());	
        //A null terminated array of character 
        //pointers
        char *args[]={"./exec",NULL};
        fflush(NULL);
        execvp(args[0],args);
     
        /*All statements are ignored after execvp() call as this whole 
        process is replaced by another process (exec.c)
        */
        printf("This statement is not executed");
     
    return 0;
}