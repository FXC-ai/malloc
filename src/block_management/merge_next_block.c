#include "../inc/malloc.h"

void merge_next_block(t_heap *heap, t_block *block)
{
    if (block == NULL || block->next == NULL || block->next->is_free == FALSE)
    {
        return;
    }

    block->data_size += block->next->data_size + sizeof(t_block);

    if (block->next->next)
        block->next->next->prev = block;

    block->next = block->next->next;

    ft_bzero(BLOCK_SHIFT(block), block->data_size);

    heap->block_count -= 1;
}