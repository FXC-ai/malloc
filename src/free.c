#include "../inc/malloc.h"


t_bool check_ptr_allocation (t_heap *heap_anchor, void *ptr)
{
    if (heap_anchor == NULL) {return FALSE;}

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
                    return TRUE;
                }

                block_found = block_found->next;
            }
        }

        heap_found = heap_found->next;
    }
    
    return FALSE;
}

t_block *merge_previous_block (t_block *block)
{
    if (block == NULL || block->prev == NULL || block->prev->is_free == FALSE) {return NULL;}

    ft_putstr_fd("A\n",2);

    t_block *previous_block = block->prev;
    ft_putstr_fd("B\n",2);

    t_block *next_block = block->next;
    ft_putstr_fd("C\n",2);

    next_block->prev = previous_block;
    ft_putstr_fd("D\n",2);

    previous_block->next = block->next;
    ft_putstr_fd("E\n",2);

    previous_block->data_size += block->data_size + sizeof(t_block);
    ft_putstr_fd("F\n",2);

    ft_bzero(BLOCK_SHIFT(previous_block), previous_block->data_size);
    ft_putstr_fd("G\n",2);

    return previous_block;
}

void free(void *ptr)
{

    (void) ptr;

    /*
    if (check_ptr_allocation(heap_anchor, ptr))
    {

        t_block *block_found = BLOCK_UNSHIFT(ptr);



    }

*/
}