#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main(){
	printf("Hello");
	int i = fork();
	printf("\nBye");
}
