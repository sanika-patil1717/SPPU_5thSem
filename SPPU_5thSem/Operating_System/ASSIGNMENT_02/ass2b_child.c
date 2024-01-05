// #include <sys/types.h>
// #include <sys/wait.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// void binarysearch(long int [10], int n);

// void main(int argc, char *argv[],char *envp[])
// {
// 	int i, n=0;
// 	long ret[10];

// 	for(i=1; argv[i]!=NULL; i++)
// 	{
// 		ret[i] = strtol(argv[i], NULL, 10);
// 		n++;
// 	}

// 	printf("SEARCH: In second child process. My process-id is %d.\n", getpid());
// 	printf("SEARCH: My parent's process-id is %d.\n\n", getppid());

// 	binarysearch(ret, n);
// }

// void binarysearch(long int a[10], int n)
// {
// 	int c, first, last, middle, search;

// 	printf("Enter value to search: \n");
// 	scanf("%d",&search);

//  	printf("\n\n=================In Binary Search Program=================== \n");
// 	first = 0;
// 	last = n - 1;
// 	middle = (first+last)/2;

// 	while( first <= last )
// 	{
// 		if ( a[middle] < search )
// 	 		first = middle + 1;
// 		else if ( a[middle] == search )
// 		{
// 	 		printf("%d found at location %d.\n", search, middle);
// 	 		break;
// 		}
// 		else
// 		last = middle - 1;

// 		middle = (first + last)/2;
// 	}
// 	if ( first > last )
// 	printf("%d is not present in the list.\n", search);

// }

// #include <stdio.h>
// #include <stdlib.h>
// int main(int argc, char *argv[])
// {
// 	printf("\nChild process is running...\n");
// 	printf("Array elements in received: ");
// 	for (int i = 1; i < argc; i++)
// 	{
// 		printf("%s ", argv[i]);
// 	}
// 	printf("\nArray elements in reverse order: ");
// 	for (int i = argc - 1; i >= 1; i--)
// 	{
// 		printf("%s ", argv[i]);
// 	}
// 	printf("\n");
// 	return 0;
// }