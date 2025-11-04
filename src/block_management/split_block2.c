#include "../../includes/malloc.h"


void split_block2
(
    t_heap  *heap,
    t_block *left_block,
    size_t  size

)
{
    if (left_block == NULL)
        return;
    
    if (size == 0)
        return;


    if (left_block->data_size < size + sizeof(t_block) + BLOCK_MIN_SIZE)
    {
        return;
    }

    t_block *right_block = BLOCK_SHIFT(left_block) + size;

    right_block->next = left_block->next;
    right_block->prev = left_block;
    right_block->data_size = left_block->data_size - sizeof(t_block) - size;
    right_block->is_free = TRUE;

    left_block->next = right_block;
    left_block->data_size = size;
    left_block->is_free = FALSE;

    heap->block_count += 1;

}