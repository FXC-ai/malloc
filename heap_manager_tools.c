#include "malloc.h"

/* round to the superior 8th byte */
size_t ft_round_eight(size_t size)
{
	// return size + (8 - (size % 8));
	return (size + 7) & ~7;
}

/* pre-allocate” the first heap  */
t_heap *ft_init_heap(size_t heap_size, t_heap_group group)
{
	t_heap *new_heap;

	new_heap = (t_heap *) mmap(NULL, heap_size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (new_heap == MAP_FAILED)
	{
		perror("mmap");
		return NULL;
	}

	new_heap->previous = NULL;
	new_heap->next = NULL;
	new_heap->group = group;
	new_heap->total_size = heap_size;
	new_heap->free_size = heap_size - sizeof(t_heap); //-16 bytes !!!!
	new_heap->block_count = 0;
	
	return (new_heap);
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
t_heap *ft_add_new_heap (t_heap *first_heap, size_t heap_size, t_heap_group group)
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
	new_heap->group = group;
	new_heap->total_size = heap_size;


	new_heap->free_size = heap_size - sizeof(t_heap);
	new_heap->block_count = 0;


	return (new_heap);

}