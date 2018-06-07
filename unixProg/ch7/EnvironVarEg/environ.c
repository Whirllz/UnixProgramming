//Example on getenv() and setenv() for Environment Variables
#include<stdio.h>
#include<stdlib.h>
// All set and get env functions are pre-defined in "stdlib.h"
int main(){
	char *name = "RAJE";
	char *val = "/home/raje";

	if(setenv(name,val,1)!=0){
		printf("Error in setenv\n");
		exit(0);
	}
	printf("The value for name %s is %s\n",name,getenv(name));

	return 0;
}