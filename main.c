#include <pthread.h>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

int main()
{

	int *ptr = calloc(10, sizeof(int));

	printf("p = %p\n", ptr);

	int *ptr1 = malloc(10 * sizeof(int));

	printf("p1 = %p\n", ptr);

	return 0;
}