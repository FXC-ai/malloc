#include "../inc/malloc.h"

size_t block_chain_datasize (t_block *first_block)
{
    if (first_block == NULL)
        return 0;

    t_block *current_block = first_block;
    size_t result = 0;

    while(current_block)
    {
        if (current_block->is_free == FALSE)
            result += current_block->data_size;
        current_block = current_block->next;
    }

    return result;
}