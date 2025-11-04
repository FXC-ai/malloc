#include "../../includes/malloc.h"

void t_heap_chain_iter(t_heap *first_heap, void (*f)(t_heap *))
{

    t_heap *current_heap = first_heap;

    while (current_heap)
    {
        f(current_heap);
        current_heap = current_heap->next;
    }
}