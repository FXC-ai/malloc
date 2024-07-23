#include "malloc.h"


/* return the pointer of the last block */
void *ft_find_last_block (t_heap *heap)
{
	t_block_meta *current = HEAP_SHIFT(heap);

	if (heap == NULL)
		return NULL;
	
	while (current->next != NULL)
	{
		current = current->next;
	}
	return current;
}


/* create a new list */
void *ft_create_new_list(t_block_meta *first_block, size_t size)
{

	size = ft_round_eight(size);

	first_block->size = size;
	first_block->previous = NULL;
	first_block->next = NULL;
	first_block->is_free = false;

	return (void *) (first_block + sizeof(t_block_meta));
}


/* Create a new block */
t_block *create_block(t_block *previous_block, t_block *new_block, size_t size)
{
	new_block->previous = previous_block;
	new_block->next = NULL;
	new_block->size = size;
	new_block->is_free = false;
}

/* Add a new block of size bytes of datas */
void *ft_add_new_block(t_block_meta *first_block, size_t size)
{
	t_block_meta *new_block;
	t_block_meta *last_block;
	// int *security;

	size = ft_round_eight(size);
	last_block = ft_find_last_block(first_block);
	new_block = (void *) last_block + sizeof(t_block_meta) + last_block->size + sizeof(int);

	last_block->next = new_block;

	new_block->size = size;
	new_block->previous = last_block;
	new_block->next = NULL;
	new_block->is_free = false;

	security = (void *) new_block + sizeof(t_block_meta) + size;
	*security = size;

	return (void *) (new_block + sizeof(t_block_meta));
}