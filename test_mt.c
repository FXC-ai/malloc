#include <pthread.h>
#include "inc/malloc.h"


void *routine(void *value)
{
    size_t v = *((size_t *)value);
    void *ptr = malloc(12);
    ft_putstr_fd("routine = ",1);
    ft_putnb_hex((uintptr_t) ptr);
    ft_putstr_fd(" ",1);
    ft_putsize_t(v);
    write(1, "\n", 1);
	return ptr;
}

int main()
{
	pthread_t	tid1;
	pthread_t	tid2;

	size_t	thread_1;
	size_t	thread_2;

	thread_1 = 1;
	thread_2 = 2;

    ft_putstr_fd("A", 1);
	pthread_create(&tid1, NULL, routine, &thread_1);
    ft_putstr_fd("B", 1);

	//pthread_create(&tid2, NULL, routine, &thread_2);
    ft_putstr_fd("C", 1);

	pthread_join(tid1, NULL);
    ft_putstr_fd("D", 1);

    show_alloc_mem();

	return 0;
}