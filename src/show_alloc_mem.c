#include "../inc/malloc.h"

static void display_bool(t_bool bool)
{
    if (bool == TRUE)
        ft_putstr_fd("TRUE", 1);
    else
        ft_putstr_fd("FALSE", 1);


}

/*

    Modèle du sujet : 0xB0020 - 0xBBEEF : 48847 bytes
*/

static void show_alloc_block(t_block *block)
{
    (void) block;
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
    t_heap_chain_iter(heap_anchor, show_alloc_heap);
}