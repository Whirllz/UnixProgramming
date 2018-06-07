// Unlike exit() function, abort() may not close files that are open.
// It may also not delete temporary files and may not flush stream buffer.
// Also, it does not call functions registered with atexit().

// This function actually terminates the process by raising a SIGABRT signal, 
// and your program can include a handler to intercept this signal (see this).

// So programs like below might not write “NITPY” to “myfile.txt”

#include<stdio.h>
#include<stdlib.h>
int main()
{
  FILE *fp = fopen("myfile.txt", "w");
   
  if(fp == NULL)
  {
    printf("\n could not open file ");
    exit(EXIT_FAILURE);
  }  
   
  fprintf(fp, "%s", "NITPY");
   
  /* ......*/
  /* Something went wrong so terminate here */ 
  abort();
  return 0;  
}

// If we want to make sure that data is written to files and/or buffers are flushed 
// then we should either use exit() or include a signal handler for SIGABRT.