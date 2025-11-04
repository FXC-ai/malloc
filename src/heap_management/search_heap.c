#include "../../includes/malloc.h"

t_heap *search_heap
(
    t_heap          *heap_start,
	t_heap_group	group,
	size_t			total_size,
	size_t			free_size,
	size_t			block_count
)
{
    t_heap* current_heap = heap_start;

    while (current_heap)
    {
        if
        (
            current_heap->group == group 
            && current_heap->total_size >= total_size
            && current_heap->free_size >= free_size
            && current_heap->block_count >= block_count
        )
        {
            return current_heap;
        }
        current_heap = current_heap->next;
    }

    return NULL;
}