#include "malloc.h"

/* pre-allocate” the first heap  */
t_heap *ft_init_heap(t_heap_size heap_size)
{
	t_heap *ptr_zone;

	/* MAP_SHARED */
	ptr_zone = (t_heap *) mmap(NULL, 16384, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ptr_zone == MAP_FAILED)
	{
		perror("mmap");
		return NULL;
	}

	ptr_zone->previous = NULL;
	ptr_zone->next = NULL;
	switch (heap_size)
	{
		case TINY_HEAP_ALLOCATION_SIZE:
			ptr_zone->group = TINY;
			break;
		case SMALL_HEAP_ALLOCATION_SIZE:
			ptr_zone->group = SMALL;
			break;
		default :
			ptr_zone->group = LARGE;
	}
	ptr_zone->total_size = heap_size;


	ptr_zone->free_size = heap_size - sizeof(t_heap); //-16 bytes !!!!
	ptr_zone->block_count = 0;


	return (ptr_zone);
}

/* add a new heap */
t_heap *ft_add_new_heap (t_heap *first_heap)
{	
	t_heap *ptr_new_heap = first_heap;

	return ptr_new_heap;
}