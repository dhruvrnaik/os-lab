
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	execlp("/bin/ls", "", NULL);
	return 0;
}