#include "../includes/malloc.h"
#include <stdio.h>


void block_mem_move(void *new_ptr, void *former_ptr, size_t size)
{
    size_t size_memmove = 0;

    t_block *former_block = (t_block *) BLOCK_UNSHIFT(former_ptr);


    if (former_block->data_size > size)
    {
        size_memmove = size;
    }
    else
    {
        size_memmove = former_block->data_size;
    }

    ft_memmove(new_ptr, former_ptr, size_memmove);

    execute_free(former_ptr);
}


void *execute_realloc(void *ptr, size_t size)
{
    void   *new_ptr;
    size_t size_alloc;
    t_heap *heap_found;
    t_block *block_to_realloc;

    new_ptr = NULL;
    heap_found = NULL;
    block_to_realloc = (t_block *) BLOCK_UNSHIFT(ptr);


    size_alloc = round_nearest_multiple(size, BLOCK_MIN_SIZE);

    if (ptr == NULL)
    {
        return execute_malloc(size_alloc);
    }

    if (size == 0)
    {
        execute_free(ptr);
        return NULL;
    }

    // Verifification que le pointeur a bien été alloué avant
    heap_found = find_heap_from_ptr(heap_anchor, ptr);
    if (heap_found == NULL)
    {
        return NULL;
    }

    
    if (heap_found->group != get_heap_group_from_block_size(size_alloc))
    {
        new_ptr = execute_malloc(size_alloc);

        if (new_ptr != NULL)
            block_mem_move(new_ptr, ptr, size);

        return new_ptr;
    }
    
   
    if (size_alloc == block_to_realloc->data_size)
    {
        return ptr;
    }

    
    if (size_alloc > block_to_realloc->data_size)
    {
        // Le block est à la fin de la heap
        if
        (
            block_to_realloc->next == NULL 
            && heap_found->free_size > (size_alloc - block_to_realloc->data_size)
        )
        {
            heap_found->free_size -= (size_alloc - block_to_realloc->data_size);
            block_to_realloc->data_size = size_alloc;

            return BLOCK_SHIFT(block_to_realloc);
        }

        // Le block est dans la heap
        if
        (
            block_to_realloc->next != NULL 
            && block_to_realloc->next->is_free
            && size_alloc == sizeof(t_block) + block_to_realloc->next->data_size + block_to_realloc->data_size
        )
        {
            merge_next_block2(heap_found, block_to_realloc);
            return ptr;
        }

    }

    if (size_alloc < block_to_realloc->data_size)
    {
        if (block_to_realloc->data_size > size_alloc + sizeof(t_block) + BLOCK_MIN_SIZE)
        {
            split_block2(heap_found, block_to_realloc, size_alloc);
            return ptr;
        }


    }
    


    new_ptr = execute_malloc(size_alloc);

    if (new_ptr != NULL)
        block_mem_move(new_ptr, ptr, size);



    return new_ptr;
}


void *realloc(void *ptr, size_t size)
{
    pthread_mutex_lock(&mt_protect);

    void *new_ptr = execute_realloc(ptr, size);

    int fd = open("malloc.log", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd > 0 && DEBUG_MOD == 1)
    {
        ft_putstr_fd("realloc(", fd);
        ft_putnb_hex_fd((uintptr_t) ptr, fd);
        ft_putstr_fd(", ", fd);
        ft_putsize_t_fd(size, fd);
        ft_putstr_fd(") => ",fd);
        ft_putnb_hex_fd((uintptr_t) new_ptr, fd);
        ft_putstr_fd("\n",fd);
    }
    close(fd);

    pthread_mutex_unlock(&mt_protect);

    return new_ptr;
}