#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PERCORSO "/home/theflag/Documents/unisa/II/so/git_syn/provaExec/ciao"


int main(void)
{
	pid_t pid;
	int i;

	

	for(int i = 0;i<20;i++)
	{
		pid = fork();// creazione pid figlio
			
		switch(pid)
		{
			case -1: //errore 1 fork
				fprintf(stderr,"errore nella creazione della fork");
				break;

			case 0: // figlio 1
				int x = execl(PERCORSO,"ciao",NULL);
				printf("%d",x);
				break;		
		}	
	}
	

	for(int i = 0;i<20;i++)
		wait(NULL);
	
	printf("\nCiao sono il padre con il pid %d\n",getpid());
}