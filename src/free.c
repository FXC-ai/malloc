#include "../inc/malloc.h"


t_bool check_ptr_allocation (t_heap *heap_anchor, void *ptr)
{
    if (heap_anchor == NULL) {return FALSE;}

    t_heap *heap_found = heap_anchor;

    while (heap_found)
    {

        if (heap_found->block_count > 0)
        {
            t_block *block_found = HEAP_SHIFT(heap_found);

            while (block_found != NULL)
            {
                
                if (BLOCK_SHIFT(block_found) == ptr)
                {
                    return TRUE;
                }

                block_found = block_found->next;
            }
        }

        heap_found = heap_found->next;
    }
    
    return FALSE;
}

t_block *merge_previous_block (t_heap *heap, t_block *block)
{
    if (block == NULL || block->prev == NULL || block->prev->is_free == FALSE) {return NULL;}

    if (block->next)
        block->next->prev = block->prev;

    block->prev->next = block->next;

    block->prev->data_size += block->data_size + sizeof(t_block);

    t_block *result = block->prev;

    ft_bzero(BLOCK_SHIFT(block->prev), block->prev->data_size);

    heap->block_count -= 1;

    return result;
}

t_block *merge_next_block(t_heap *heap, t_block *block)
{
    if (block == NULL || block->next == NULL || block->next->is_free == FALSE) {return block;}

    block->data_size += block->next->data_size;

    if (block->next->next)
        block->next->next->prev = block;

    block->next = block->next->next;

    ft_bzero(BLOCK_SHIFT(block), block->data_size);

    heap->block_count -= 1;

    return block;
}

void delete_last_block(t_heap *heap, t_block *first_block)
{
    if (!first_block) {return;}

    t_block *current_block;

    current_block = first_block;

    while (current_block->next)
    {
        current_block = current_block->next;
    }

    display_block_chain(current_block);

    if (current_block->prev)
        current_block->prev->next = NULL;

    ft_bzero(current_block, current_block->data_size + sizeof(t_block));

    heap->block_count -= 1;
}

void delete_heap(t_heap **heap)
{

    t_heap *heap_to_delete = *heap;

    if (heap_to_delete->prev)
    {
        heap_to_delete->prev->next = heap_to_delete->next;
    }

    if (heap_to_delete->next && heap_to_delete->prev)
    {
        heap_to_delete->next->prev = heap_to_delete->prev;
    }

    // LE PROBLEME EST LA !!! IL FAUT TROUVER UN MOYEN DE GERER LE CAS OU ON VEUT DELETE
    // LA DERNIERE HEAP

    munmap(heap_to_delete, heap_to_delete->total_size);

    *heap = NULL;

}


void free(void *ptr)
{

    (void) ptr;

    /*
    if (check_ptr_allocation(heap_anchor, ptr))
    {

        t_block *block_found = BLOCK_UNSHIFT(ptr);



    }

*/
}