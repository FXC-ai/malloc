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
        ft_putstr_fd("A\n",1);
        return execute_malloc(size_alloc);
    }

    if (size == 0)
    {
        ft_putstr_fd("B\n",1);
        execute_free(ptr);
        return NULL;
    }

    if (find_heap_from_ptr(heap_anchor, ptr) == NULL)
    {
        ft_putstr_fd("C\n",1);
        return NULL;
    }

    if (size_alloc == ((t_block *) BLOCK_UNSHIFT(ptr))->data_size)
    {
        ft_putstr_fd("D\n",1);
        return ptr;
    }

    new_ptr = execute_malloc(size_alloc);

    if (size_alloc > ((t_block *) BLOCK_UNSHIFT(ptr))->data_size)
    {
        size_memmove = ((t_block *) BLOCK_UNSHIFT(ptr))->data_size;
        ft_putstr_fd("D\n",1);

    }
    else
    {
        size_memmove = size;
        ft_putstr_fd("E\n",1);

    }

    ft_memmove(new_ptr, ptr, size_memmove);

    execute_free(ptr);

    return new_ptr;
}