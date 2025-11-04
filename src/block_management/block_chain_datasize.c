#include "../../includes/malloc.h"

size_t block_chain_datasize (t_block *first_block, t_bool is_free)
{
    if (first_block == NULL)
        return 0;

    t_block *current_block = first_block;
    size_t result = 0;

    while(current_block)
    {
        if (current_block->is_free == is_free)
            result += current_block->data_size;
        current_block = current_block->next;
    }

    return result;
}