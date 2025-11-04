#include <pthread.h>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
// #include "inc/malloc.h"

int main()
{

	printf("%lu\n", SIZE_MAX);

	size_t size = 1024 * 1024 * 1024 * 1024;

	printf("size = %lu\n", size);

	void *ptr = malloc(size);

	if (ptr == NULL)
	{
		printf("Echec de l allocation\n");
	}

	printf("ptr = %p\n", ptr);

	return 0;
}