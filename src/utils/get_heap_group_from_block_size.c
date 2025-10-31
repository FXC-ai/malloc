#include "../inc/malloc.h"

t_heap_group  get_heap_group_from_block_size(size_t block_size)
{
    if (block_size <= TINY_BLOCK_SIZE)
        return TINY;
    else if (block_size <= SMALL_BLOCK_SIZE)
        return SMALL;
    
    return LARGE;
}