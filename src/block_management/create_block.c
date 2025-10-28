#include "../inc/malloc.h"


void create_block(t_block *block, size_t data_size, t_bool is_free)
{
    block->prev      = NULL;
    block->next      = NULL;
    block->data_size = data_size;
    block->is_free   = is_free;
}