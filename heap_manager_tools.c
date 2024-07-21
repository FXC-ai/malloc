#include "malloc.h"

/* pre-allocate” the first heap  */
t_heap *ft_init_heap(t_heap_size heap_size)
{
	t_heap *first_heap;

	/* MAP_SHARED */
	first_heap = (t_heap *) mmap(NULL, heap_size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (first_heap == MAP_FAILED)
	{
		perror("mmap");
		return NULL;
	}

	first_heap->previous = NULL;
	first_heap->next = NULL;
	switch (heap_size)
	{
		case TINY_HEAP_ALLOCATION_SIZE:
			first_heap->group = TINY;
			break;
		case SMALL_HEAP_ALLOCATION_SIZE:
			first_heap->group = SMALL;
			break;
		default :
			first_heap->group = LARGE;
	}
	first_heap->total_size = heap_size;


	first_heap->free_size = heap_size - sizeof(t_heap); //-16 bytes !!!!
	first_heap->block_count = 0;


	return (first_heap);
}

/*Return th pointer of the last heap*/
t_heap *ft_find_last_heap (t_heap *first_heap)
{
	t_heap *current = first_heap;

	while (current->next != NULL)
	{
		current = current->next;
	}
	return current;
}

/* add a new heap */
t_heap *ft_add_new_heap (t_heap *first_heap, t_heap_size heap_size)
{	
	t_heap *new_heap;
	t_heap *last_heap;

	last_heap = ft_find_last_heap(first_heap);

	new_heap = (t_heap *) mmap(NULL, heap_size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (first_heap == MAP_FAILED)
	{
		perror("mmap");
		return NULL;
	}

	last_heap->next = new_heap;

	new_heap->previous = last_heap;
	new_heap->next = NULL;
	switch (heap_size)
	{
		case TINY_HEAP_ALLOCATION_SIZE:
			new_heap->group = TINY;
			break;
		case SMALL_HEAP_ALLOCATION_SIZE:
			new_heap->group = SMALL;
			break;
		default :
			new_heap->group = LARGE;
	}
	new_heap->total_size = heap_size;


	new_heap->free_size = heap_size - sizeof(t_heap);
	new_heap->block_count = 0;


	return (new_heap);

}