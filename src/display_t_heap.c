#include "../inc/malloc.h"

void display_t_heap(t_heap *heap)
{
    write(1, "---------HEAP INFOS-------\n", 27);

    write(1, "location    = ", 14);
    display_hex((uintptr_t) heap);
    write(1, "\n", 1);
    write(1, "\n", 1);

    write(1, "prev        = ", 14);
    display_hex((uintptr_t) heap->prev);
    write(1, "\n", 1);

    write(1, "next        = ", 14);
    display_hex((uintptr_t) heap->next);
    write(1, "\n", 1);
    write(1, "\n", 1);

    write(1, "group       = ", 14);
    display_t_heap_group(heap->group);
    write(1, "\n", 1);

    write(1, "total size  = ", 14);
    display_nb(heap->total_size);
    write(1, "\n", 1);

    write(1, "free size   = ", 14);
    display_nb(heap->free_size);
    write(1, "\n", 1);

    write(1, "block count = ", 14);
    display_nb(heap->block_count);
    write(1, "\n", 1);

    write(1, "--------------------------\n\n", 28);
}