#include "../../includes/malloc.h"

t_block *add_block_back(t_heap *heap, size_t data_size, t_bool is_free)
{
    if (heap == NULL)
    {
        return NULL;
    }

    t_block *current_block = HEAP_SHIFT(heap);

    while (current_block->next)
    {
        current_block = current_block->next;
    }

    t_block *new_block = (t_block *) ((void *)current_block + sizeof(t_block) + current_block->data_size);

    current_block->next = new_block;

    new_block->prev      = current_block;
    new_block->next      = NULL;
    new_block->data_size = data_size;
    new_block->is_free   = is_free;

    heap->block_count += 1;
    heap->free_size -= (data_size + sizeof(t_block));

    return new_block;
}