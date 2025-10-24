#include "../inc/malloc.h"

t_block *init_block_chain(t_heap *heap, size_t data_size)
{
    t_block *first_block = (t_block *) HEAP_SHIFT(heap);

    first_block->next = NULL;
    first_block->prev = NULL;
    first_block->data_size = data_size;
    first_block->is_free = FALSE;

    heap->block_count += 1;
    heap->free_size -= (data_size + sizeof(t_block));

    return first_block;
}