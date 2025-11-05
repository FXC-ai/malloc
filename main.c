#include <pthread.h>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/mman.h>
// #include "inc/malloc.h"

int main()
{

	char *p = mmap
    (
        NULL,
        4096,
        PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANONYMOUS,
        -1,
        0
    );

	p = "Hello world !!!";



	printf("%ld\n %s\n", sizeof(size_t), p);



	return 0;
}