#include <pthread.h>
#include <stdio.h>
#include "../inc/malloc.h"


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
	pthread_t	tid[10];
	size_t		thread_ids[10];

	for (size_t i = 0; i < 10; i++)
		thread_ids[i] = i + 1;

	for (size_t i = 0; i < 10; i++)
		pthread_create(&tid[i], NULL, routine, &thread_ids[i]);

	for (size_t i = 0; i < 10; i++)
		pthread_join(tid[i], NULL);

	show_alloc_mem();

	return 0;
}