#include "../../includes/malloc.h"


t_heap *create_heap(t_heap_group heap_group, size_t heap_size)
{
    t_heap *heap = mmap
    (
        NULL,
        heap_size,
        PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANONYMOUS,
        -1,
        0
    );

    if (heap == MAP_FAILED)
    {
        write(2, "Error : create_heap\n", 19);
        return NULL;
    }

    heap->group       = heap_group;
    heap->total_size  = heap_size;
    heap->free_size   = heap_size - sizeof(t_heap);
    heap->block_count = 0;
    heap->next        = NULL;
    heap->prev        = NULL;
    
    // ft_bzero(HEAP_SHIFT(heap), heap_size - sizeof(t_heap));

    return heap;
}