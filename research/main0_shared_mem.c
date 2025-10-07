#include "libft/libft.h"
#include <stdio.h>
#include <sys/mman.h>


struct memory_bloc
{
	int size;
}

struct memory_block_free
{

}

void *ft_malloc (int size)
{
	void *ptr;

	ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	if (ptr == MAP_FAILED) {
		return NULL;
	}
	return ptr;
}


int main()
{

	printf("PID = %d\n", getpid());
	size_t len = 1024;

	char *shared_mem = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	if (shared_mem == MAP_FAILED) {
		perror("mmap");
		exit(EXIT_FAILURE);
	}

	int i = 0;

	// shared_mem[12] = 'a';

	printf("shared_mem = %p", shared_mem);
	for (i = 0; i < 20; i++)
	{
		printf("%d : %c \n", i, shared_mem[i]);
	}


	char *test_mem = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	if (shared_mem == MAP_FAILED) {
		perror("mmap");
		exit(EXIT_FAILURE);
	}


	test_mem[11] = 'a';

	printf("test_mem = %p", test_mem);
	for (i = 0; i < 20; i++)
	{
		printf("%d : %c \n", i, test_mem[i]);
	}


	printf("shared_mem - test_mem = %ld\n", shared_mem - test_mem);

	printf("sizeof = %ld\n", sizeof(char));


	int *test_mem2 = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	if (test_mem2 == MAP_FAILED)
	{
		perror("mmap");
		exit(EXIT_FAILURE);
	}

	printf("sizeof = %ld\n", sizeof(test_mem2[2]));

	// char * cpy_ptr = shared_mem;

	// void *ptr = malloc(128);

	// printf("ptr = %p\n", ptr);

	// printf("processus 0 a ecrit à la l'adresse %p : %s\n", cpy_ptr, cpy_ptr);



	// while (1)
	// {}

	return 0;
}