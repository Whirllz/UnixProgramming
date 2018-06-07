// This program makes a deamon processs.
// The Log.txt file is written with ecertain line of text
// The 6 steps to make a deamon are shown clearly 

// TO run : gcc -Wall deamonEg.c deamon
// ./deamon
// Now go and check the file Log.txt
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/resource.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<syslog.h>
#include<signal.h>

void daemonize(const char *cmd){
	int i,fd0,fd1,fd2;
	pid_t pid;
    FILE *fp;
	struct rlimit rl;
	struct sigaction sa;

    // 1.clear file mode creation mask to 0
	umask(0);           

	if(getrlimit(RLIMIT_NOFILE,&rl)<0){      // Get max file descritors
		printf("file limit not found ");
		exit(0);
	}
 
    // 2.Become a session leader to lose control with terminal,TTY
	if((pid=fork())<0){
		printf("fork error");
		exit(-1);
	}

	else if(pid!=0)              // end parent process
	   exit(0);
    
    // 3.Create a new session
    setsid();

    // Assure any future open wont allocate controllinh TTY

    sa.sa_handler = SIG_IGN; 
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if(sigaction(SIGHUP,&sa,NULL)<0){
    	printf("Can't ignore SIGHUP");
    	exit(-1);
    }
    if((pid=fork())<0){
		printf("fork error");
		exit(-1);
	}

	else if(pid!=0)              // end parent process
	   exit(0);

    // 4.Change cuurent working directory to root directory
    if(chdir("/")<0){
    	printf("Can't change directory\n");
    	exit(-1);
    }

    // 5.Close all open file descriptors
    if(rl.rlim_max == RLIM_INFINITY)
    	rl.rlim_max = 512;

    for(i=0;i<rl.rlim_max;i++)
    	close(i);

    // 6.Open file descriptors 1,2,3 to /dev/null for NO read,write,error effect

    fd0 = open("/dev/null",O_RDWR);
    fd1 = dup(0);
    fd2 = dup(0);

    // Initialize log files

    fp = fopen ("/home/raje/Desktop/Log.txt", "w+");
    while (1){
      //Dont block context switches, let the process sleep for some time
      sleep(1);
      fprintf(fp, "Logging info...\n");
      fflush(fp);
      // Implement and call some function that does core work for this daemon.
      /* ...... */
      }
    fclose(fp);
 }

int main(int argc, char const *argv[])
{
	daemonize("./a.out");
	return 0;
}


