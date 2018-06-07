#include <stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#define MAX 100

int main(int argc, char const *argv[])
{
	char line[MAX];
	FILE * fp;

	if((fp=popen("filter","r"))==NULL){
		printf("popen error");
		exit(-1);
	}

	while(1){
		fputs("prompt> ",stdout);
		fflush(stdout);

		if(fgets(line,MAX,fp)==NULL)
			break;
		if(fputs(line,stdout)==EOF){
			printf("fputs error");
			exit(-1);
		}
	}
	fclose(fp);
	putchar('\n');
	return 0;
}
