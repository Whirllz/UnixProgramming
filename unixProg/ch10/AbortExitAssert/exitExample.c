// exit() terminates the process normally.

// status: Status value returned to the parent process.
// Generally, a status value of 0 or EXIT_SUCCESS indicates success,
// and any other value or the constant EXIT_FAILURE is used to indicate an error.

/* exit() performs following operations.
* Flushes unwritten buffered data.
* Closes all open files.
* Removes temporary files.
* Returns an integer exit status to the operating system.
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100  
int main ()
{
  FILE * fp;
  char buf[SIZE];
  fp = fopen ("myfile.txt", "r");
  if (fp == NULL)
  {
    printf ("Error opening file");
    exit (EXIT_FAILURE);
  }
  else
  {
    fread(buf,SIZE,1,fp);
    printf("%s\n",buf);
  }

  exit(EXIT_SUCCESS);   // same as return 0
}