#include "../inc/malloc.h"

void         display_heap_chain(t_heap *first_heap)
{
    t_heap *current_heap = first_heap;

    while (current_heap)
    {
        display_t_heap(current_heap);
        write(1, "           |          \n", 23);
        write(1, "           V          \n", 23);
        current_heap = current_heap->next;
    }
    
}