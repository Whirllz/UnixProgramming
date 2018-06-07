#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
//atexit() is pre-defined in "stdlib.h"

void fun1(){
	printf("In First function\n");
}


void fun2(){
	printf("In Second function\n");
}


int main(){

	printf("main() Started\n");

	if(atexit(fun1)!=0){
		printf("At exit failed on fun1!");
	}

	if(atexit(fun2)!=0){
		printf("At exit failed on fun2!");
	}

	printf("main() ends\n");
	exit(0);
}