#include "../../includes/malloc.h"


/*
    Il y a 2 cas a traiter :
        - NULL        (1)
        - []->[]->[X] (2)
        - [X]         (3)

*/

void delete_last_block(t_heap *heap)
{
    t_block *current_block = HEAP_SHIFT(heap);

    if (!current_block) {return;} //1

    while (current_block->next)
    {
        current_block = current_block->next;
    }

    if (current_block->prev)         // 3
        current_block->prev->next = NULL; 

    ft_bzero(current_block, current_block->data_size + sizeof(t_block));

    heap->block_count -= 1;
}