#include<stdio.h>
#include<setjmp.h>
//setjump() and longjump() are pre-defined in "setjmp.h" header
jmp_buf buffer;

//setjump(jmp_buf buffer) : uses buffer to remember current position and returns 0
//longjump(jmp_buf buffer, i) : Go back to place buffer is pointing to and return
//its second argument,i(1 in this example) 

void fun(){
	printf("Hello ");
    longjmp(buffer,1);                 // go to position in buffer and return 1
    printf("Studying unix Programming!");
}

int main()
{
	if(setjmp(buffer)){                // setup jump position using buffer and return 0
		printf("Students at NITPY!\n");
	}
	else{
      fun();
      printf("NITPY");
	}
	return 0;
}