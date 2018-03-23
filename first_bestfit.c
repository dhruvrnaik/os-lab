#include<stdio.h>

int choice;
int *arr_holes,*arr_proc;
struct table *best;
int n_holes ;
int n_proc;
int i,j;
int allot[50];
void best_fit();
//void first_fit();

int main()
{
while(1){
	printf("\n1.Best Fit\n2.First Fit\n3.Exit\n");
	scanf("%d",&choice);
	if(choice==1)
		best_fit();
	else if(choice==2)
		first_fit();
	else
		exit(1);
}

return 0;
}
struct table
{
	int hole_size;
	int hole_no;
};

void best_fit(){

	input();	

	for(i=0;i<n_proc;i++){
		int flag=0;

		
		for(j=0;j<n_holes;j++){
			if(flag==0 && arr_proc[i]<=*(arr_holes+j) && allot[j]==0){
				flag=1;
				(best+i)->hole_size = *(arr_holes+j);
				(best+i)->hole_no = j+1;
				allot[j] = 1;
			}
			else if(flag==1 && arr_proc[i]<=*(arr_holes+j) && allot[j]==0 && *(arr_holes+j)<(best+i)->hole_size){
				allot[((best+i)->hole_no)-1] = 0;
				(best+i)->hole_size= *(arr_holes+j);
				(best+i)->hole_no = j+1;
				allot[j] = 1;
			}
		}
	}
	display();	
}

void first_fit(){

	input();	

	for(i=0;i<n_proc;i++){
		int flag=0;

		for(j=0;j<n_holes;j++){
			if(flag==0 && arr_proc[i]<=*(arr_holes+j) && allot[j]==0){
				flag=1;
				(best+i)->hole_size = *(arr_holes+j);
				(best+i)->hole_no = j+1;
				allot[j] = 1;
				break;
			}
			
		}	
	}
	display();	
}

void display(){

	printf("\n\tProcess No.\tProcess size\tHole No.\tHole Size\n\t---------------------------------------------------------");
	
	for(i=0;i<n_proc;i++){
		printf("\n\t%d\t\t%d\t\t%d\t\t%d",(i+1),arr_proc[i],(best+i)->hole_no,(best+i)->hole_size);
	}


}

void input(){

	printf("\nEnter no. of holes\n");
	scanf("%d",&n_holes);
	arr_holes = (int *) malloc (n_holes*sizeof(int));
	
	
	printf("\nEnter no. of processes\n");
	scanf("%d",&n_proc);
	arr_proc = (int *) malloc (n_proc*sizeof(int));
	
	best = (struct table *) malloc(n_proc*sizeof(struct table));
	
	for(i=0;i<n_holes;i++)
		allot[i] = 0;
	
	printf("\nEnter process sizes\n");
	for(i=0;i<n_proc;i++)
		scanf("%d",(arr_proc+i));
	
	printf("\nEnter hole sizes\n");
	for(i=0;i<n_holes;i++)
		scanf("%d",(arr_holes+i));


	
	for(i=0;i<n_holes;i++)
		printf("%d",(arr_proc[i]));

	for(i=0;i<n_proc;i++){

		(best+i)->hole_size=-1;
		(best+i)->hole_no =-1;}

}

