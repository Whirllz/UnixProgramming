#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	int c;

	while(c= getchar()!=EOF){
		if(isupper(c))
			c=tolower(c);
		if(putchar(c)==EOF){
			printf("Output error");
			exit(-1);
		}
		if(c=='\n')
			fflush(stdout);
	}
	return 0;
}
