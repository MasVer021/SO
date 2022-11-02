#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>


void input(char ** strvet );
void input2(char ** strvet);

int main(void)
{
	pid_t pid;
	char  *arg [256] ;
		
	do
	{

		printf("%%");
		input2(arg);

		pid=fork();

		switch(pid)
		{
			case -1: //errore fork
				fprintf(stderr,"errore nella creazione della fork");
				break;

			case 0: // figlio		
				if(execvp(arg[0],arg)==-1)
				{
					//fprintf(stderr,"Errore nell esecuzione della funzione exec");
					exit(0);
				}			
		}
		wait(NULL);

	}while(1);

}


void input(char ** strvet )
{
	char buffer [256] ={0};
	char c;
	int i,index;

	c = getchar();
	i=0;
	index = 0;


	while(c!='\n')
	{
		
		if(c!=' ')
		{
			
			buffer[i]=c;
			i++;
		}
		else
		{			
			strvet[index] = calloc(strlen(buffer)+1,sizeof(char)); // andrebbe controllata la corretta
			strncpy(strvet[index],buffer,strlen(buffer));
			//strvet[index][strlen(buffer)] = '\0';  //funziona anche senza carattere terminatore
			index ++;
			
			for(int j=0;j<i;j++)
			{
				buffer[j]='\0';
			}
			i=0;
		}
		c = getchar();
	}
	strvet[index] = calloc(strlen(buffer)+1,sizeof(char));
	strncpy(strvet[index],buffer,strlen(buffer));
	//strvet[index][strlen(buffer)] = '\0';  //funziona anche senza carattere terminatore
	index ++;
	strvet[index] = NULL;

}

void input2(char ** strvet)
{
	char buffer [256] ={0};
	char c;
	int index;

	index = 0;

	while(c!='\n')
	{
		scanf("%[^ \n]",buffer);
		strvet[index] = calloc(strlen(buffer)+1,sizeof(char)); // andrebbe controllata la corretta
		strncpy(strvet[index],buffer,strlen(buffer));
		//printf("%s\n",strvet[index]);
		index++;
		c = getchar();
		
	}
	strvet[index] = NULL;
}