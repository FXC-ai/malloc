#include "../inc/malloc.h"


void *realloc(void *ptr, size_t size)
{
    void   *new_ptr;
    size_t size_alloc;
    size_t size_memmove;

    new_ptr = NULL;
    size_alloc = round_nearest_multiple(size, BLOCK_MIN_SIZE);
    size_memmove = 0;

    if (ptr == NULL)
    {
        return execute_malloc(size_alloc);
    }

    if (size == 0)
    {
        execute_free(ptr);
        return NULL;
    }

    if (find_heap_from_ptr(heap_anchor, ptr) == NULL)
    {
        return NULL;
    }

    if (size_alloc == ((t_block *) BLOCK_UNSHIFT(ptr))->data_size)
    {
        return ptr;
    }

    new_ptr = execute_malloc(size_alloc);

    if (size_alloc > ((t_block *) BLOCK_UNSHIFT(ptr))->data_size)
    {
        size_memmove = ((t_block *) BLOCK_UNSHIFT(ptr))->data_size;
    }
    else
    {
        size_memmove = size;
    }

    ft_memmove(new_ptr, ptr, size_memmove);

    execute_free(ptr);

    return new_ptr;
}