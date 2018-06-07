// Example on assert() 
// If expression evaluates to 0 (false), then the expression, sourcecode filename,
// and line number are sent to the standard error, and then abort() function is called

// Following program illustrates assert() 

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
// assert() is pre-defined in "assert.h"

void open_record(char *record_name)
{
	/* some code */
    assert(record_name != NULL);
    /* Rest of code */
}
 
int main(void)
{
   open_record(NULL);
}