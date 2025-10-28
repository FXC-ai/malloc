#include "../inc/malloc.h"

void         display_block_chain(t_block *first_block)
{
    t_block *current_block = first_block;

    while (current_block)
    {
        display_t_block(current_block);
        write(1, "           |          \n", 23);
        write(1, "           V          \n", 23);
        current_block = current_block->next;
    }

}