#include "../inc/malloc.h"

void free(void *ptr)
{
    t_block *block_to_free = BLOCK_UNSHIFT(ptr);

    t_heap *heap_found = find_heap_from_ptr(heap_anchor, ptr);

    if (heap_found == NULL)
        return;

    block_to_free->is_free = TRUE;

    block_to_free = merge_previous_block(heap_found, block_to_free);

    merge_next_block(heap_found, block_to_free);

    if (block_to_free->next == NULL) 
    {
        if (block_to_free->prev) {block_to_free->prev->next = NULL;}
        ft_bzero(block_to_free, block_to_free->data_size + sizeof(t_block));
        heap_found->block_count -= 1;
    }

    if (heap_found->block_count == 0)
    {
        delete_heap(heap_found, &heap_anchor);
    }
}