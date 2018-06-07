#include  <stdio.h>
#include  <unistd.h>
// fork() is pre-defined in "unistd.h"

// Number of processes created after fork() = 2^(Number of fork() calls)
// Hence, number of times NITPY is printed  = 2^(Number of fork() calls) 

int main()
{
    fork();
    fork();
    fork();
    printf("NITPY\n");
    return 0;
}