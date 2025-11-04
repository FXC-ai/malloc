#include "../../includes/malloc.h"

void display_t_heap(t_heap *heap)
{

    ft_putstr_fd("\n\033[0;34m----------HEAP INFOS--------\033[0m\n", 1);
    if (heap == NULL)
    {
        write(1, "NULL\n", 5);
    }
    else
    {
        write(1, "location    = ", 14);
        ft_putnb_hex_fd((uintptr_t) heap , 1);
        write(1, "\n", 1);
        write(1, "\n", 1);

        write(1, "previous    = ", 14);
        ft_putnb_hex_fd((uintptr_t) heap->prev, 1);
        write(1, "\n", 1);

        write(1, "next        = ", 14);
        ft_putnb_hex_fd((uintptr_t) heap->next, 1);
        write(1, "\n", 1);
        write(1, "\n", 1);

        write(1, "group       = ", 14);
        display_t_heap_group(heap->group);
        write(1, "\n", 1);

        write(1, "total size  = ", 14);
        ft_putsize_t(heap->total_size);
        write(1, "\n", 1);

        write(1, "non alloc   = ", 14);
        ft_putsize_t(heap->free_size);
        write(1, "\n", 1);

        write(1, "block count = ", 14);
        ft_putsize_t(heap->block_count);
        write(1, "\n", 1);
    }


        ft_putstr_fd("\033[0;34m----------------------------\033[0m\n\n", 1);

}