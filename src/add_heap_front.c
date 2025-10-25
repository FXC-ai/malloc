#include "../inc/malloc.h"


void add_heap_front(t_heap **heap_start, t_heap *heap)
{

    if (*heap_start == NULL)
    {
        *heap_start = heap;
        return;
    }

    heap->next = *heap_start;
    (*heap_start)->prev = heap;
    *heap_start = heap;
}