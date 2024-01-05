#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include<sys/wait.h>

void input(int arr[],int n){
	int i,j;
	printf("Enter the elements:-\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
}

int split(int a[],int l,int m,int h){
	int i,j,k,pivot,flag=1,c1=0,c2=0;
	static int count = 1;
	pivot = l;
	i = l+1;
	j = h;

	while(flag){
		while((a[i] < a[pivot]) && a[i]!=NULL){
			i--;
			c1++;//Comparison count
		}

		while(a[j] > a[pivot]){
			j--;
			c1++;//Comparison count
		}

		if(i<j){
			swap(a,i,j);
			c2++;//Swap count
		}
		else{
			flag = 0;
		}

	}

	if(flag == 0){
		c2++;
		swap(a,j,pivot);//Swap count
	}

	return j;
}

void quickSort(int a[],int l,int h){
	int i,m;

	if(l<h){
		m = (l+h)/2;
		i = split(a,l,m,h);

		quickSort(a,l,i-1);
		quickSort(a,i+1,h);
	}
}

void swap(int arr[],int a,int b){
	int temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;

}

void display(int a[],int n){
	int i;
	printf("\n");
	printf("Sorted array:- ");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

int main (void) {
	pid_t pid;
	int a[10],size,choice;
	
	printf("Enter the size of the array:- ");
	scanf("%d",&size);	
	printf("Enter the elements in the array:-");	
	
	for(int i=0; i < size; i++){
		scanf("%d",&a[i]);
	}	
	
	printf("Enter the choice:-\n1.Orphan\n2.Zombie");
	scanf("%d",&choice);

	// fork current process 
	if (choice == 1) {
		printf("*************Forking**********\n");
		pid = fork();
		
		if(pid > 0)	{
			// make sure we are in the parent process
			printf("In Parent Process\n");	
			printf("Running quick sort!!!\n");
			
			quickSort(a, 0, size-1);
			display(a, size);
			
			// shows parent info
			printf("PARENT -- PID: %d PPID: %d, CHILD PID: %d\n",getpid(), getppid(), pid);
			system("ps -elf | grep a.out");
			printf("\nParent process exited\n\n");
		}
		else if (pid == 0) {
            sleep(10);
			// make sure we are in the child process
			printf("In Child Process\n");	
			printf("Running quick sort!!!\n");
			
			quickSort(a, 0, size-1);
			display(a, size);			
			
			// shows child info
			printf("Child Process in sleep\n");						
			printf("Child process is awake\n");
			printf("CHILD -- PID: %d PPID: %d\n", getpid(), getppid());
			system("ps -elf | grep a.out");
			printf("\nChild process exited\n\n");
		}
	}
	else if (choice == 2){
			printf("*************Forking**********\n");
			pid = fork();
		
		if(pid > 0)		
		{
            sleep(10);
			// make sure we are in the parent process
			printf("In Parent Process\n");
			printf("Running quick sort!!!\n");
			
			quickSort(a, 0, size-1);
			display(a, size);
			
			// sleep so parent doesn’t die before child 
			printf("PARENT -- PID: %d PPID: %d, CHILD PID: %d\n",getpid(), getppid(), pid);
			printf("Parent Process in sleep\n");			
			printf("Parent process is awake\n");
			system("ps -elf | grep a.out");
			printf("\nParent process exited\n\n");
		}
		else if (pid == 0){
			// make sure in the child process
			printf("In Child Process\n");
			printf("Running quick sort!!!\n");
			
			quickSort(a, 0, size-1);
			display(a, size);		
			
			// shows child info
			printf("CHILD -- PID: %d PPID: %d\n", getpid(), getppid());
			system("ps -elf | grep a.out");
			printf("\nChild process exited\n\n");
		}
	}
	
	exit(0);
	// in both processes 
}
