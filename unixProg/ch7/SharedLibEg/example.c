
// Benefits of shared Libraries can be seen in this program
// By default, shared libraries are used

#include<stdio.h>
int main(){
	printf("hello world!\n");
}

// 1.

// "gcc -static example.c"     : prevents gcc from using shared libraries
// check size a.out

// 2.

// "gcc example.c"     : Normally, gcc using shared libraries
// check size a.out

// check size of a.out in 1 and 2 (see the difference in sizes)