#include "../inc/malloc.h"

void set_block_prev(t_block *block, t_block *prev)
{
    if (block)
        block->prev = prev;
}

void set_block_next(t_block *block, t_block *next)
{
    if (block)
        block->next = next;
}

void set_block_data_size(t_block *block, size_t size)
{
    if (block)
        block->data_size = size;
}

void set_block_is_free(t_block *block, t_bool is_free)
{
    if (block)
        block->is_free = is_free;
}
