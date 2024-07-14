#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#import <stddef.h>
#include <stdbool.h>

void *heap_start = NULL;


typedef struct s_block_meta
{
	int size_previous;
	int size;
	struct s_block_meta *previous;
	struct s_block_meta *next;
	bool is_free;
	
} block_meta;


void *find_last_block_meta (block_meta *start)
{
	block_meta *current = start;

	while (current->next != NULL)
	{
		current = current->next;
	}
	return current;
}


void *ft_malloc (int size)
{

	if (heap_start == NULL)
	{
		void *ptr_tiny = NULL;
		void *ptr_small = NULL;
		void *ptr_large = NULL;
		/*Inutile d'allouer systematiquement...*/
		ptr_tiny = mmap(NULL, 384000000, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
		if (ptr_tiny == MAP_FAILED)
		{
			perror("mmap");
			return NULL;
		}	
		ptr_small = mmap(ptr_tiny, 1024000000, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
		if (ptr_small == MAP_FAILED)
		{
			perror("mmap");
			return NULL;
		}
		ptr_large = mmap(ptr_small, 8192000000, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
		if (ptr_large == MAP_FAILED)
		{
			perror("mmap");
			return NULL;
		}	

		heap_start = ptr_tiny;

		if (size <= 512)
		{
			block_meta *initial_block_tiny = (block_meta *) ptr_tiny;
			initial_block_tiny->size = size;
			initial_block_tiny->size_previous = 0;
			initial_block_tiny->previous = NULL;
			initial_block_tiny->next = NULL;
			initial_block_tiny->is_free = false;
			void* r = (void *) (initial_block_tiny + sizeof(block_meta));
			return (void *) (ptr_tiny + sizeof(block_meta));
		}
		else if (size <= 8192)
		{
			block_meta *initial_block_small = (block_meta *) ptr_small;
			initial_block_small->size = size;
			initial_block_small->size_previous = 0;
			initial_block_small->previous = NULL;
			initial_block_small->next = NULL;
			initial_block_small->is_free = false;
			return (void *) (ptr_small + sizeof(block_meta));
		}
		else if (size <= 131072)
		{
			block_meta *initial_block_large = (block_meta *) ptr_small;
			initial_block_large->size = size;
			initial_block_large->size_previous = 0;
			initial_block_large->previous = NULL;
			initial_block_large->next = NULL;
			initial_block_large->is_free = false;
			return (void *) (ptr_large + sizeof(block_meta));

		}

	}
	else
	{
		if (size <= 512)
		{	
			block_meta *last = find_last_block_meta((block_meta *) heap_start);
			block_meta *new = (void *) last + sizeof(block_meta) + last->size;
			// printf("last = %p\n", last);
			// printf("new = %p\n", new);
			// printf("diff = %ld\n", (void *) new - (void *) last);

			new->size_previous = last->size;
			new->size = size;
			new->previous = last;
			new->next = NULL;
			new->is_free = false;

			last->next = new;

			return (void *) (new + sizeof(block_meta));
		}

	}
	return NULL;
}


int main()
{

    // printf("Size of block_meta: %lu\n", sizeof(block_meta));
    // printf("Offset of size_previous: %lu\n", offsetof(block_meta, size_previous));
    // printf("Offset of size: %lu\n", offsetof(block_meta, size));
    // printf("Offset of previous: %lu\n", offsetof(block_meta, previous));
    // printf("Offset of next: %lu\n", offsetof(block_meta, next));
    // printf("Offset of is_free: %lu\n", offsetof(block_meta, is_free));
	// printf("sizeof block meta = %ld\n", sizeof(block_meta));

	char *ptr_test0 = (char *) ft_malloc(10);
	printf("TEST 0 : %p\n", heap_start);

	ptr_test0[0] = 'a';
	ptr_test0[1] = 'a';
	ptr_test0[2] = 'a';
	ptr_test0[3] = 'a';
	ptr_test0[4] = 'a';
	ptr_test0[5] = 'a';
	ptr_test0[6] = 'a';
	ptr_test0[7] = 'a';
	ptr_test0[8] = 'a';
	ptr_test0[9] = '\0';


	printf("%p %p\n",  ptr_test0, &ptr_test0[9]);



	char *ptr_test1 = (char *) ft_malloc(10);
	printf("ptr_test1 = %p\n",ptr_test1);



	return 0;
}