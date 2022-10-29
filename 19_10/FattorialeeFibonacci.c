#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int fib (int n)
{
	if(n<=1)
		return n;
	return fib(n-1)+fib(n-2);
}

int fattoriale (int n)
{
	if(n<=1)
		return 1;
	return n*fattoriale(n-1);
}

int main(void)
{
	pid_t pid;

	pid =fork();

	if(pid < 0) //in caso di errore pid <0
	{
		fprintf(stderr, "errore nella creazione della fork\n");
	}
	else if (pid == 0) //processo figlio
	{  
  		for(int i=0;i<10;i++) 
  		{	
      		printf("%d\n",fib(i+1));
 		}
		
	}
	else if(pid > 0) //processo padre
	{
		for(int i=0;i<10;i++) 
  		{	
      		printf("%d\n",fattoriale(i+1));
 		}
	}
}