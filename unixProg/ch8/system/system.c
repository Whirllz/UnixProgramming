#include<stdio.h>
#include<stdlib.h>
// system() is used to execute command strings from within the program
int main(){

	if(system("who")<0){
		printf("system() Error");
		exit(-1);
	}
	if(system("echo I am Raje")<0){
		printf("system() Error");
		exit(-1);
	}
	if(system("pwd")<0){
		printf("system() Error");
		exit(-1);
	}
	if(system("date")<0){
		printf("system() Error");
		exit(-1);
	}

	return 0;
}