#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
    while(1) {
        int i;
        printf("1.Non-Preemptive SJF\n2.RR\n3.Non-preemptive Priority\n4.FCFS(Same Arrival Time)\n6.Exit\n");
        scanf("%d", &i);
	system("clear");
        switch(i) {
            case 1:
                system("./SJF");
                break;
            case 2:
                system("./RR");
                break;
            case 3:
                system("./PRIORITY");
                break;
            case 4:
                system("./FCFS");
                break;

            case 6:
                exit(0);
        }
	
	 
    }   
      
}                       



