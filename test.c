#include "inc/malloc.h"

int main()
{

    t_block *block0 = malloc(96);

    t_block *block1 = malloc(37);

    t_block *block2 = malloc(120);

    t_block *block3 = malloc(150);

    t_block *block4 = malloc(150);
   

    show_alloc_mem();

    /*   
    void *heap1= create_heap(TINY, TINY_HEAP_SIZE);
    void *heap2= create_heap(SMALL, SMALL_HEAP_SIZE);
    void *heap3= create_heap(LARGE, 8900);

    add_heap_front(heap1, heap2);
    add_heap_front(heap2, heap3);

    t_block *block0     = init_block_chain(heap1, 13);
    t_block *ptr_block1 = add_block_back(heap1, 12, FALSE);
    t_block *block2     = add_block_back(heap1, 120, TRUE);
    t_block *block3     = add_block_back(heap1, 120, TRUE);

    display_block_chain(heap1);

    write(1, "\n", 1);
    write(1, "\n", 1);

    t_block* right_block = split_block(heap1, block2, 16, TRUE);
    t_block* right_block2 = split_block(heap1, block3, 73, TRUE);
    display_block_chain(heap1);

    display_t_heap(heap1);
    */
    return 0;
}