#include "inc/malloc.h"
#include <stdio.h>

int main()
{
    void *block0 = malloc(96);

    display_hex((uintptr_t) block0);
    write(1, "\n", 1);

    show_alloc_mem();
    write(1, "\n", 1);

    display_t_heap_chain(heap_anchor);

    return 0;
}