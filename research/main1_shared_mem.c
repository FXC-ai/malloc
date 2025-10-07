#include "libft/libft.h"
#include <stdio.h>

int main()
{

	char *shared_mem = (char *) 0x10b0a9000;

	printf("processus 1 : le processus 0 a ecrit à la l'adresse %p : %s\n", shared_mem, shared_mem);



	return 0;
}