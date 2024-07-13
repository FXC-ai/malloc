#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

#include <stdbool.h>

void *heap_start = NULL;


typedef struct s_block_meta
{
	int size;
	void *previous;
	void *next;
	bool is_free;
	
} block_meta;


void *ft_malloc (int size)
{
	void *ptr_tiny = NULL;
	void *ptr_small = NULL;
	void *ptr_large = NULL;



	if (heap_start == NULL)
	{
		ptr_tiny = mmap(NULL, 384000000, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
		printf("ptr_tiny = %p\n", ptr_tiny);
		ptr_small = mmap(ptr_tiny, 1024000000, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
		printf("ptr_small = %p\n", ptr_small);
		ptr_large = mmap(ptr_small, 8192000000, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
		printf("ptr_large = %p\n", ptr_large);

		// printf ("%ld %ld\n", ptr_large - ptr_small, ptr_small - ptr_tiny);

		printf("sizeof(block_meta) = %lu\n", sizeof(block_meta));
		block_meta *initial_block = (block_meta *) ptr_tiny;
		initial_block->size = size;
		initial_block->previous = NULL;
		initial_block->next = NULL;
		initial_block->is_free = false;

		heap_start = ptr_tiny;

		return (void *) ptr_tiny + sizeof(block_meta);
	}



	return ptr_tiny;
}


int main()
{

	printf("TEST 0\n");

	char *ptr_test0 = (char *) ft_malloc(12);





	return 0;
}