#include "../inc/malloc.h"

t_heap *heap_anchor = NULL;

void *malloc (size_t size)
{

    size_t size_alloc;
    t_block *block = NULL;
    t_heap *heap_found = NULL;
    t_heap *new_heap = NULL;

    if (size % BLOCK_MIN_SIZE == 0)
    {
        size_alloc = size;
    }
    else
    {
        size_alloc = size + BLOCK_MIN_SIZE - ((size + BLOCK_MIN_SIZE) % BLOCK_MIN_SIZE); 
    }

    t_heap_group heap_group = get_heap_group_from_block_size(size_alloc);

    size_t heap_size = get_heap_size_from_heap_group(heap_group, size_alloc);

    if (heap_anchor != NULL)
    {
        heap_found = search_heap(heap_anchor, heap_group, 0, size_alloc + sizeof(t_block),0);
        block = add_block_back(heap_found, size_alloc, FALSE);
    }

    if (heap_found == NULL)
    {
        new_heap = create_heap(heap_group, heap_size);
        if (new_heap == NULL)
        {
            return NULL;
        }

        add_heap_front(&heap_anchor, new_heap); ///// ???????
        block = init_block_chain(heap_anchor, size_alloc);
    }



    return block;
}
