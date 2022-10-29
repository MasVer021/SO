#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>




int main(void)
{
	pid_t pid,pid2;

	pid =fork();

	if(pid < 0) //in caso di errore pid <0
	{
		fprintf(stderr, "errore nella creazione della fork\n");
	}
	else if (pid == 0) //processo figlio1
	{  
  		printf("my PID: %d, My Parent PID: %d\n",getpid(),getppid());
		
	}
	else if(pid > 0) //processo padre
	{
		pid2 =fork();
		if(pid2 < 0) //in caso di errore pid <0
		{
			fprintf(stderr, "errore nella creazione della fork\n");
		}
		else if (pid2 == 0) //processo figlio2
		{  
  			printf("Somma PID: %d\n",getpid()+getppid());
		}
		else{ //processo padre
			printf("Processo con PID: %d terminato\n",wait(NULL));
			printf("Processo con PID: %d terminato\n",wait(NULL));
		}
	}
}