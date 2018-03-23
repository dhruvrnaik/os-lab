#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#define MAX 100
void selectionSort(char arr[][MAX], int n);
void bubsort(char arr[][MAX], int n);
int main()
{
	int x,y,i,j;
	int status;
	char arr[][100] = {"hello","my","name"};
	int n = sizeof(arr)/sizeof(arr[0]);
	x = fork();
	y=fork();
	 if(x==0 && y>0 ){
		bubsort(arr,n);
		  printf("\nStrings in sorted order for child 1 : ");
    for ( i=0; i<n; i++)
        printf("\n %s",  arr[i]);
	}
	
else if(y==0 && x>0){	
		selectionSort(arr,n);
		  printf("\nStrings in sorted order for child 2 : ");
    for ( i=0; i<n; i++)
        printf("\n %s",  arr[i]);
	}
	printf("\n");
	return 0;
}

void bubsort(char arr[][MAX], int n)
{
    char temp[MAX];
    int i,j;
    // Sorting strings using bubble sort
    for ( j=0; j<n-1; j++)
    {
        for ( i=j+1; i<n; i++)
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

void selectionSort(char arr[][MAX], int n)
{
    int i, j, min_idx;
  
    // One by one move boundary of unsorted subarray
    char minStr[MAX];
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        int min_idx = i;
        strcpy(minStr, arr[i]);
        for (j = i+1; j < n; j++)
        {
            // If min is greater than arr[j]
            if (strcmp(minStr, arr[j]) > 0)
            {
                // Make arr[j] as minStr and update min_idx
                strcpy(minStr, arr[j]);
                min_idx = j;
            }
        }
  
        // Swap the found minimum element with the first element
        if (min_idx != i)
        {
            char temp[MAX];
            strcpy(temp, arr[i]); //swap item[pos] and item[i]
            strcpy(arr[i], arr[min_idx]);
            strcpy(arr[min_idx], temp);
        }
    }
}
