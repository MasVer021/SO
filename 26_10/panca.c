#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main(void)
{
	printf("\n\n\n");

	printf("sopra la panca\n");

	execl("/bin/echo","echo","la","capra","campa",NULL);

	printf("prova prova");
}