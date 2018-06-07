// This program implements of user-made pause() function -- myPause()

/* Suspends execution of the calling thread. The thread does not resume execution
   until a signal is delivered, executing a signal handler or ending the thread.*/ 
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
// signal() is pre-defined in "signal.h"

static volatile int done = 0;

static void handler()
{
  printf("Signal caught\n");
  done = 1;
}

void myPause()
{
  signal(SIGINT, handler);   // user interrupt -- press Ctrl-C for signal 
  done = 0;
  while (!done);
}

int main()
{
  myPause();
  printf("First call to myPause returned !\n");
  myPause();
  printf("Second call to myPause returned !\n");
  return (0);
}