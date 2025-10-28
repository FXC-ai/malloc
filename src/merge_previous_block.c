#include "../inc/malloc.h"

t_block *merge_previous_block (t_heap *heap, t_block *block)
{
    if (block == NULL || block->prev == NULL || block->prev->is_free == FALSE) {return block;}

    if (block->next)
        block->next->prev = block->prev;

    block->prev->next = block->next;

    block->prev->data_size += block->data_size + sizeof(t_block);

    t_block *result = block->prev;

    ft_bzero(BLOCK_SHIFT(block->prev), block->prev->data_size);

    heap->block_count -= 1;

    return result;
}