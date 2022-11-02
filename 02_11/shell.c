#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>



int main(void)
{
	pid_t pid;
	char string [20] = {0};
	do
	{
		
		printf("%%");
		scanf("%s",string);
		pid=fork();

		switch(pid)
		{
			case -1: //errore 1 fork
				fprintf(stderr,"errore nella creazione della fork");
				break;

			case 0: // figlio
								
				execlp(string,string,NULL);	
				


					
		}	
		wait(NULL);

	}while(1);

}