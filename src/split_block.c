#include "../inc/malloc.h"


t_block *split_block
(
    t_heap  *heap,
    t_block *left_block,
    size_t  size,
    t_bool  is_free
)
{
    if (left_block == NULL)
        return NULL;
    
    write(1,"AA\n", 3);

    if (left_block->is_free == FALSE)
        return NULL;

    write(1,"BB\n", 3);
    
    
    if (size == 0)
        return left_block;

    write(1,"CC\n", 3);



    if (sizeof(t_block) + BLOCK_MIN_SIZE + size > left_block->data_size)
        return left_block;


    write(1,"DD\n", 3);


    t_block *right_block = BLOCK_SHIFT(left_block) + size;

    right_block->next = left_block->next;
    right_block->prev = left_block;
    right_block->data_size = left_block->data_size - sizeof(t_block) - size;
    right_block->is_free = TRUE;

    left_block->next = right_block;
    left_block->data_size = size;
    left_block->is_free = is_free;

    heap->block_count -= 1;

    return right_block;
}