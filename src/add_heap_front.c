#include "../inc/malloc.h"
#include <stdio.h>

void add_heap_front(t_heap *heap_anchor, t_heap *heap)
{

    if (heap_anchor == NULL)
    {
        heap_anchor = heap;
        return;
    }

    heap->next = heap_anchor;
    heap_anchor->prev = heap;
    heap_anchor = heap;

}