#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main()
{
	printf("A");
	int pid = fork();
	if(pid ==0)
	{
		printf("B");
		int pid1 = fork();
		if(pid == 0)
		{
			printf("C");
			int pid2 = fork();
			if (pid2==0)
				printf("D");
			else
				printf("D")
		}
		else
		{
			printf("C");
			int pid3 = fork();
			if (pid3==0)
				printf("D");
			else
				printf("D")
		}	
	}			
	else
	{
		printf("B");
		int pid4 = fork();
		if(pid4 == 0)
		{
			printf("C");
			int pid5 = fork();
			if (pid5==0)
				printf("D");
			else
				printf("D")
		}
		else
		{
			printf("C");
			int pid6 = fork();
			if (pid6==0)
				printf("D");
			else
				printf("D")
		}
	}
}

		
				
		

	
		
			




