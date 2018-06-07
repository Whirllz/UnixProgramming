#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
// Race condition is true when the output depends on the sequence of execution of the 
// program at run-time

int main(){
  
  pid_t pid;
  pid=fork();
  if(pid<0){
  	printf("Fork error");
  	exit(-1);
  }
  if(pid==0){
  	printf("In child\n");
  }
  else{
  	printf("In parent\n");
  }
  return 0;
}