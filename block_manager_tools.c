#include "malloc.h"


/* return the pointer of the last block */
void *find_last_block_meta (t_block_meta *first_block)
{
	t_block_meta *current = first_block;

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

/* Add a new block of size bytes of datas */
void *ft_add_new_block(t_block_meta *first_block, size_t size)
{
	t_block_meta *new_block;
	t_block_meta *last_block;
	int *security;

	size = ft_round_eight(size);
	last_block = find_last_block_meta(first_block);
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

size_t ft_round_eight(size_t size)
{
	// return size + (8 - (size % 8));
	return (size + 7) & ~7;
}