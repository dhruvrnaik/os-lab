#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define MAX 100
int main()
{
	int x;
	int status;
	char arr[][100] = {"hello","my","name","is","apple","asia","dog"};
	int n = sizeof(arr)/sizeof(arr[0]);
	x = fork();
	if(x>0){
		wait(&status);
		  printf("Strings in sorted order are : ");
    for (int i=0; i<n; i++)
        printf("\n String %d is %s", i+1, arr[i]);
	}
	else if(x==0){
		bubsort(arr,n);
		  printf("Strings in sorted order are : ");
    for (int i=0; i<n; i++)
        printf("\n String %d is %s", i+1, arr[i]);
	}
	
	return 0;
}

void bubsort(char arr[][MAX], int n)
{
    char temp[MAX];
 
    // Sorting strings using bubble sort
    for (int j=0; j<n-1; j++)
    {
        for (int i=j+1; i<n; i++)
        {
            if (strcmp(arr[j], arr[i]) > 0)
            {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[i]);
                strcpy(arr[i], temp);
            }
        }
    }
}