#include "../inc/malloc.h"

/*
    Modèle du sujet : 0xB0020 - 0xBBEEF : 48847 bytes
*/

static void show_alloc_block(t_block *block)
{

    display_hex((uintptr_t) BLOCK_SHIFT(block));
    ft_putstr_fd(" - ", 1);
    display_hex((uintptr_t) (BLOCK_SHIFT(block) + block->data_size));
    ft_putstr_fd(" : ", 1);
    display_nb(block->data_size);
    ft_putstr_fd(" bytes", 1);
    ft_putstr_fd(" (", 1);
    display_bool(block->is_free);
    ft_putstr_fd(")", 1);

    write(1, "\n", 1);
}

static void show_alloc_heap(t_heap *heap)
{
    display_t_heap_group(heap->group);
    ft_putstr_fd(" : ", 1);
    display_hex((uintptr_t) heap);
    write(1, "\n" ,1);

    block_chain_iter((t_block*) HEAP_SHIFT(heap), show_alloc_block);
}

static void show_total_size(t_heap *heap)
{
    size_t total = 0;

    t_heap *current_heap = heap;

    while (current_heap)
    { 
        total += block_chain_datasize(HEAP_SHIFT(current_heap));
        current_heap = current_heap->next;
    }

    ft_putstr_fd("Total : ", 1);
    display_nb(total);
    ft_putstr_fd(" bytes\n", 1);
}


/*
    TINY : 0xA0000
    0xA0020 - 0xA004A : 42 bytes
    0xA006A - 0xA00BE : 84 bytes
    SMALL : 0xAD000
    0xAD020 - 0xADEAD : 3725 bytes
    LARGE : 0xB0000
    0xB0020 - 0xBBEEF : 48847 bytes
    Total : 52698 bytes
*/

void show_alloc_mem()
{
    if (heap_anchor == NULL)
    {
        ft_putstr_fd("PAS DE HEAP ALLOUEE\n", 1);
        return;
    }

    t_heap_chain_iter(heap_anchor, show_alloc_heap);

    show_total_size(heap_anchor);

    // ATTENTION IL MANQUE LE TOTAL !!!!
}