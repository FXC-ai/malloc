#include "../../includes/malloc.h"


t_block *search_block(t_block *first_block, size_t min_data_size, t_bool is_free)
{
    t_block *current_block = first_block;

    while (current_block)
    {
        if
        (
            (
                current_block->data_size == min_data_size ||
                current_block->data_size >= min_data_size + sizeof(t_block) + BLOCK_MIN_SIZE
            )&& current_block->is_free == is_free
        )
        {
            return current_block;
        }
        current_block = current_block->next;
    }

    return NULL;
}