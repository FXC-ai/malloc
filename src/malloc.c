#include "../inc/malloc.h"

t_heap *heap_anchor = NULL;

void *malloc (size_t size)
{

    size_t size_alloc;

    if (size % BLOCK_MIN_SIZE == 0)
    {
        size_alloc = size;
    }
    else
    {
        size_alloc = size + BLOCK_MIN_SIZE - ((size + BLOCK_MIN_SIZE) % BLOCK_MIN_SIZE); 
    }

    display_nb(size_alloc);
    write(1, "\n", 1);


    t_heap_group heap_group = get_heap_group_from_block_size(size_alloc);
    display_nb(heap_group);
    write(1, "\n", 1);


    size_t heap_size = get_heap_size_from_heap_group(heap_group, size_alloc);
    display_nb(heap_size);
    write(1, "\n", 1);


    heap_anchor = create_heap(heap_group, heap_size);
    display_t_heap(heap_anchor);

    t_block *block = init_block_chain(heap_anchor, size_alloc);
    display_block_chain(block);

    return block;
}
