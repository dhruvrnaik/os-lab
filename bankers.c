#include<stdio.h>
#include<stdbool.h>
int i,j,max[50][50],alloc[50][50],need[50][50],avail[1][50];
int m,n;

void safety();
void req();
bool comp(int x);

int main(){

printf("\nEnter values for no. of processes and no. of resource types");
//m processes, n-resources
scanf("%d\n%d",&m,&n);
printf("Enter max values process-wise");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&max[i][j]);
				
		}
	}

printf("Enter allocation values process-wise");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&alloc[i][j]);
				
		}
	}
printf("Enter available values process-wise");
		for(j=0;j<n;j++){
			scanf("%d",&avail[0][j]);
				
		}

	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			need[i][j]=max[i][j]-alloc[i][j];
				
		}
	}
int choice;
while(1){
	printf("\n1.Safety Check\n2.Request\n3.Exit\n");
	scanf("%d",&choice);
	if(choice==1)
		safety();
	if(choice==2)
		req();
	if(choice==3)
		exit(1);

}

	
	
}

void safety(){
	int count=0;
	i=0;
	int work[1][n];
	bool finish[m];
	while(i<m){
		finish[i]=false;
		i++;
	}
	while(count<m+1){
		for(i=0;i<m;i++){
			if(finish[i]==false){

				if(comp(i)){
					int w;
					for(w=0;w<n;w++){
						avail[0][w]+=alloc[i][w];
						alloc[i][w]=0;					
					}
					finish[i]=true;
				}

			}

		}			

				count++;
	}
	int check=0;
	for(i=0;i<m;i++)
		if(finish[i]==true)
			check++;
	if(check==m)
		printf("\nSafe state");
	else
		printf("\nIn unsafe state");
}
bool comp(int x){
	int q,flag=0;
	for(q=0;q<n;q++){
		if(need[x][q]<=avail[0][q])
			flag++;
	
	}

	if(flag==m)
		return true;
	else
		return false;

}

void req(){
	int x,w,arr_req[10],counter=0;
	printf("\nEnter process no:\n");
	scanf("%d",&x);
	printf("Enter request\n");
	for(w=0;w<n;w++){
		scanf("%d",&arr_req[w]);
		if(arr_req[w]<=need[x][w] && arr_req[w]<=avail[0][w])
			counter++;

	}
	if(counter==n)
		printf("Request Granted\n" );
	else
		printf("Request Not Granted\n");

}