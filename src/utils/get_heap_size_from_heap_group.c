#include "../inc/malloc.h"

size_t get_heap_size_from_heap_group(t_heap_group heap_group, size_t size)
{
    if (heap_group == TINY)
        return TINY_HEAP_SIZE;
    else if (heap_group == SMALL)
        return SMALL_HEAP_SIZE;
        
    // ft_putsize_t(size + sizeof(t_heap));
    return size + sizeof(t_heap) + sizeof(t_block);
}
