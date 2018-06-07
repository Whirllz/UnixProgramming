// Example to implement one side of FIFO
// This side writes first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define ARRSIZE 80;

int main()
{
    int fd;
 
    // FIFO file path
    char * myfifo = "/tmp/myfifo";
 
    // Creating the named file(FIFO)
    // mkfifo(<pathname>, <permission>)
    mkfifo(myfifo, 0666);
    char arr1[ARRSIZE], arr2[ARRSIZE];
   
    while (1)
    {
        // Open FIFO for write only
        fd = open(myfifo, O_WRONLY);
 
        // Take an input arr2ing from user.
        // ARRSIZE is maximum length
        fgets(arr2, ARRSIZE, stdin);
 
        // Write the input arr2ing on FIFO
        // and close it
        write(fd, arr2, strlen(arr2)+1);
        close(fd);
 
        // Open FIFO for Read only
        fd = open(myfifo, O_RDONLY);
 
        // Read from FIFO
        read(fd, arr1, sizeof(arr1));
 
        // Print the read message
        printf("User2: %s\n", arr1);
        close(fd);
    }
    return 0;
}