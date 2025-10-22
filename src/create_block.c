#include "../inc/malloc.h"


t_block create_block(size_t data_size, t_bool is_free)
{
    t_block block;

    block.prev = NULL;
    block.next = NULL;
    block.data_size = data_size;
    block.is_free = is_free;

    return block;
}