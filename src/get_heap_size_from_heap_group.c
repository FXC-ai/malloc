#include "../inc/malloc.h"

size_t get_heap_size_from_size(size_t size)
{
    t_heap_group heap_group = get_heap_group_from_block_size(size);

    if (heap_group == TINY)
        return TINY_HEAP_SIZE;
    else if (heap_group == SMALL)
        return SMALL_HEAP_SIZE;
    
    return size;
}