#include "../inc/malloc.h"

void display_t_heap_group(t_heap_group heap_group)
{
    if (heap_group == TINY)
        write(1, "TINY", 5);
    else if (heap_group == SMALL)
        write(1, "SMALL", 6);
    else if (heap_group == LARGE)
        write(1, "LARGE", 6);
}