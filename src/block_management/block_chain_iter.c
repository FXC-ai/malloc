#include "../../includes/malloc.h"

void block_chain_iter(t_block *first_block, void (*f)(t_block *))
{

    t_block *current_block = first_block;

    while (current_block)
    {
        f(current_block);
        current_block = current_block->next;
    }
}