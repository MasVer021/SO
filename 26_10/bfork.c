#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


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
			printf("pid #1 figlio%d\n",getpid());
			for(i=1;i<=50;i++)
			{
				printf("%d\n",i);
			}
			break;
		default: // padre
			pid2 = fork(); // creazione pid 2 figlio
			switch(pid2)
			{
				case -1: //errore 2 fork
					fprintf(stderr,"errore nella creazione della fork");
					break;
				case 0: // figlio 2
					printf("pid #2 figlio%d\n",getppid());
					for(i=101;i<=150;i++)
					{
						printf("%d\n",i);
					}
					break;
				default: // padre
					printf("il figlio con pid %d e terminto\n",waitpid(-1,NULL,0));
					printf("il figlio con pid %d e terminto\n",waitpid(-1,NULL,0));
					break;
			}
			break;
	}
}