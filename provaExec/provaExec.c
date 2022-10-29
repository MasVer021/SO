#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PERCORSO "/home/theflag/Documents/unisa/II/so/git_syn/prova/ciao"


int main(void)
{
	pid_t pid1,pid2;
	int i;

	pid1 = fork();// creazione pid 1 figlio

	switch(pid1)
	{
		case -1: //errore 1 fork
			fprintf(stderr,"errore nella creazione della fork");
			break;

		case 0: // figlio 1
				execl(PERCORSO,"ciao",NULL);
			break;		
	}

	pid2 = fork();// creazione pid 2 figlio

	switch(pid2)
	{
		case -1: //errore 1 fork
			fprintf(stderr,"errore nella creazione della fork");
			break;

		case 0: // figlio 1
				execl(PERCORSO,"ciao",NULL);
			break;		
	}

	
	wait(NULL);
	printf("\nCiao sono il padre con il pid %d\n",getpid());
}