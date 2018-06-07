#include<stdio.h>
// getc() and putc() are pre-defined in "stdio.h"
// ferror is pre-defined in "stdio.h"
#include<stdlib.h>

int main(){

	int c;

    // For every Enter u type there is a line read and written 
    // For quiting from the output press (CTRL+D)
	while( (c = getc(stdin)) != EOF)
		if( putc(c,stdout) == EOF )
			printf("Error in Output");
	
	if(ferror(stdin))
		printf("Error in Input");
    // ferror() checks error indicated by stream.Returns non-zero if it is 1
	
	exit(0);
}