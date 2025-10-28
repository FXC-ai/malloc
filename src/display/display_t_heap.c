#include "../inc/malloc.h"

void display_t_heap(t_heap *heap)
{

    write(1, "---------HEAP INFOS-------\n", 27);
    if (heap == NULL)
    {
        write(1, "NULL\n", 5);
    }
    else
    {
        write(1, "location    = ", 14);
        ft_putnb_hex((uintptr_t) heap);
        write(1, "\n", 1);
        write(1, "\n", 1);

        write(1, "prev        = ", 14);
        ft_putnb_hex((uintptr_t) heap->prev);
        write(1, "\n", 1);

        write(1, "next        = ", 14);
        ft_putnb_hex((uintptr_t) heap->next);
        write(1, "\n", 1);
        write(1, "\n", 1);

        write(1, "group       = ", 14);
        display_t_heap_group(heap->group);
        write(1, "\n", 1);

        write(1, "total size  = ", 14);
        ft_putsize_t(heap->total_size);
        write(1, "\n", 1);

        write(1, "free size   = ", 14);
        ft_putsize_t(heap->free_size);
        write(1, "\n", 1);

        write(1, "block count = ", 14);
        ft_putsize_t(heap->block_count);
        write(1, "\n", 1);
    }


    write(1, "--------------------------\n", 28);
}