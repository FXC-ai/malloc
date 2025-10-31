#include <pthread.h>
#include <stdio.h>
#include "../inc/malloc.h"

#define NB_ROUTINE 6

void *routine(void *value)
{
    size_t v = *((size_t *)value);
    void *ptr = malloc(v);
    //ft_putstr_fd("routine = ",1);
	//printf("Routine %lu\n", v);
	return ptr;
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

	show_alloc_mem();

	return 0;
}