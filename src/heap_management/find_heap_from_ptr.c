#include "../inc/malloc.h"


t_heap *find_heap_from_ptr (t_heap *heap_anchor, void *ptr)
{
    if (heap_anchor == NULL) {return NULL;}

    t_heap *heap_found = heap_anchor;

    while (heap_found)
    {
        if (heap_found->block_count > 0)
        {
            t_block *block_found = HEAP_SHIFT(heap_found);

            while (block_found != NULL)
            {
                if (BLOCK_SHIFT(block_found) == ptr)
                {
                    return heap_found;
                }

                block_found = block_found->next;
            }
        }

        heap_found = heap_found->next;
    }
    
    return NULL;
}