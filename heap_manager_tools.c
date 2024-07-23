#include "malloc.h"

/* round to the superior 8th byte */
size_t ft_round_eight(size_t size)
{
	// return size + (8 - (size % 8));
	return (size + 7) & ~7;
}


/* Return the adapted size of the heap given the size of allocated bytes asked */
size_t ft_calculate_heap_size (size_t size)
{
	size = ft_round_eight(size);

	if (size <= 128)
		return TINY_HEAP_ALLOCATION_SIZE;
	else if (size <= 512)
		return SMALL_HEAP_ALLOCATION_SIZE;
	else
		return size + sizeof(t_heap);
}

/* Return the type of heap needed (TINY SMALL OR LARGE)*/
t_heap_group ft_find_group (size_t size)
{
	if (size <= 128)
		return TINY;
	else if (size <= 512)
		return SMALL;
	else
		return LARGE;
}

size_t ft_find_heap_size(t_heap_group group)
{

	switch (group)
	{
		case 0:
			return TINY_HEAP_ALLOCATION_SIZE;
			break;
		case 1:
			return SMALL_HEAP_ALLOCATION_SIZE;
			break;
		default :
			return LARGE;
	}

}

/* pre-allocate” the first heap  */
t_heap *ft_init_heap(size_t heap_size)
{

	// need to put that in the global variable !!!

	t_heap *first_heap;

	// t_heap_group group = ft_find_group(size);
	// security about heap_size ???

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
	
	
	// void * first_block = (void *) HEAP_SHIFT(first_heap);

	// printf("first_heap = %p first_block = %p\n", first_heap, first_block);


	return (first_heap);
}

/*Return the pointer of the last heap*/
t_heap *ft_find_last_heap (t_heap *first_heap)
{
	t_heap *current = first_heap;

	while (current->next != NULL)
	{
		current = current->next;
	}
	return current;
}

/*Return the first heap with the given group in parameter*/
t_heap *ft_find_heap_group (t_heap *first_heap, t_heap_group group)
{
	t_heap *current = first_heap;

	if (first_heap == NULL)
		return NULL;
	while (current != NULL)
	{
		if (current->group == group)
		{
			return current;
		}
		current = current->next;
	}
	return NULL;
}

/* add a new heap */
t_heap *ft_add_new_heap (t_heap *first_heap, size_t heap_size)
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