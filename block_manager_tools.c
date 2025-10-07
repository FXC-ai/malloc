#include "malloc.h"

/* Create a new block */
void ft_create_block(t_block *previous_block, t_block *new_block, size_t size)
{
	if (previous_block != NULL)
		previous_block->next = new_block;

	new_block->previous = previous_block;
	new_block->next = NULL;
	new_block->size = size;
	new_block->is_free = false;
}

/* return the pointer of the last block */
void *ft_find_last_block (t_heap *heap)
{
	if (heap->block_count == 0)
		return HEAP_SHIFT(heap);

	t_block * current;
	
	current = (t_block *) HEAP_SHIFT(heap);

	while (current->next != NULL)
		current = current->next;

	return current;
}


t_block *ft_add_new_block(t_heap *heap, size_t size)
{
	t_block *new_block;
	t_block *last_block;

	size = ft_round_eight(size);

	if (heap->block_count == 0)
	{
		new_block = HEAP_SHIFT(heap);
		ft_create_block(NULL, new_block, size);
		heap->block_count += 1;
		heap->free_size -= size + sizeof(t_block);
	}
	else
	{
		last_block = (t_block *) ft_find_last_block(heap);
		new_block = (void *) last_block + sizeof(t_block) + size;
		ft_create_block(last_block, new_block, size);
		heap->block_count += 1;
		heap->free_size -= size + sizeof(t_block);
	}
	return new_block;
}