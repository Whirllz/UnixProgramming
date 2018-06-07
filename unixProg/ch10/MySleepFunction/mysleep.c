#include <stdio.h>
#include <time.h>
// To use time library of C --> clock()

void mysleep(int number_of_seconds)
{
    // Converting time into micro_seconds
    long int micro_sec = 1000000 * number_of_seconds;
 
    // Storing time
    clock_t start_time = clock();
 
    // looping till required time is not acheived
    while (clock() < start_time + micro_sec);
}
 
int main()
{
    int i;
    for (i = 0; i < 10; i++) {
        // sleep for one second
        mysleep(1);
        printf("%d seconds have passed\n", i + 1);
    }
    printf("Exiting main() \n");
    return 0;
}