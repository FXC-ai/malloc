#include "../inc/malloc.h"


t_block *search_block(t_heap *heap, size_t min_data_size, t_bool is_free)
{
    t_block *current_block = HEAP_SHIFT(heap);

    while (current_block)
    {
        if(current_block->data_size >= min_data_size && current_block->is_free == is_free )
        {
            return current_block;
        }
        current_block = current_block->next;
    }

    return NULL;
}