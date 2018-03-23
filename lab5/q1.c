#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>

int main(void){
	int status;
	pid_t x;
	x = fork();
	if(x>0){
		wait(&status);
		printf("parent\n");
		printf("%dpid\n",getpid() );
		printf("%dppid\n",getppid() );
	}
	else if(x==0){
		printf("child\n");
		printf("%dpid\n",getpid() );
		printf("%dppid\n",getppid() );
	}

	return 0;
}