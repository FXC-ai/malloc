#include <pthread.h>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
// #include "inc/malloc.h"

int main()
{
	char *test[12];

	ft_bzero(test, 12);

	int *ptr = calloc(10, sizeof(int));

	printf("p = %p\n", ptr);

	int *ptr1 = malloc(10 * sizeof(int));

	printf("p1 = %p\n", ptr);

	return 0;
}