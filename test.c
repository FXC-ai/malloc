#include "inc/malloc.h"

int main()
{

    t_block block = create_block(23, FALSE);

    void *heap1= create_heap(TINY_HEAP_SIZE);
    void *heap2= create_heap(SMALL_HEAP_SIZE);
    void *heap3= create_heap(8900);

    add_heap_front(heap1, heap2);
    add_heap_front(heap2, heap3);

    display_t_heap(heap3);
    display_t_heap(heap2);
    display_t_heap(heap1);

    return 0;
}