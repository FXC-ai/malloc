#include <pthread.h>
#include <stdio.h>
#include "../../inc/malloc.h"

#define NB_ROUTINE 10

void *routine(void *value)
{
	size_t		i;
	char	*addr;

	size_t v = *((size_t *) value);
	i = 0;
	while (i < 10)
	{
		addr = (char*)malloc(128);
		addr[0] = 42;
		//free(addr);
		i++;

		show_alloc_mem();	
	}
	return NULL;
}

int main(void)
{
	pthread_t	tid[NB_ROUTINE];

	size_t		thread_ids[NB_ROUTINE];

	for (size_t i = 0; i < NB_ROUTINE; i++)
		thread_ids[i] = i + 1;

	for (size_t i = 0; i < NB_ROUTINE; i++)
		pthread_create(&tid[i], NULL, routine, &thread_ids[i]);

	for (size_t i = 0; i < NB_ROUTINE; i++)
		pthread_join(tid[i], NULL);

	ft_putstr_fd("\n",1);
	
	show_alloc_mem();

	return 0;
}