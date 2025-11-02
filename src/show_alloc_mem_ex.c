#include "../inc/malloc.h"


/* ============================================================================
** Fonction : show_alloc_block
**
** Rôle :
**     Affiche les informations d’un bloc mémoire :
**       - Adresse de début et de fin
**       - Taille du bloc (en octets)
**       - État (alloué / libre) si DEBUG_MOD_MOD est activé
**
** ============================================================================
*/

static void show_alloc_block(t_block *block)
{
    ft_putnb_hex_fd((uintptr_t) BLOCK_SHIFT(block), 1);
    ft_putstr_fd(" - ", 1);
    ft_putnb_hex_fd((uintptr_t) (BLOCK_SHIFT(block) + block->data_size), 1);
    ft_putstr_fd(" : ", 1);
    ft_putsize_t(block->data_size);
    ft_putstr_fd(" bytes", 1);
    ft_putstr_fd(" (", 1);
    ft_putbool(block->is_free);
    ft_putstr_fd(")", 1);
    write(1, "\n", 1);
}



static void show_alloc_heap(t_heap *heap)
{
    display_t_heap(heap);

    block_chain_iter((t_block*) HEAP_SHIFT(heap), show_alloc_block);
}


static void show_total_size_used(t_heap *heap)
{
    size_t total = 0;

    t_heap *current_heap = heap;

    while (current_heap)
    { 
        total += block_chain_datasize(HEAP_SHIFT(current_heap), FALSE);
        current_heap = current_heap->next;
    }

    ft_putstr_fd("Total alloc : ", 1);
    ft_putsize_t(total);
    ft_putstr_fd(" bytes\n", 1);
}

static void show_total_size_free(t_heap *heap)
{
    size_t total = 0;

    t_heap *current_heap = heap;

    while (current_heap)
    { 
        total += block_chain_datasize(HEAP_SHIFT(current_heap), TRUE);
        current_heap = current_heap->next;
    }

    ft_putstr_fd("Total free  : ", 1);
    ft_putsize_t(total);
    ft_putstr_fd(" bytes\n", 1);
}

void execute_show_alloc_mem_ex()
{
    if (heap_anchor == NULL)
    {
        ft_putstr_fd("PAS DE HEAP ALLOUEE\n", 1);
        return;
    }

    t_heap_chain_iter(heap_anchor, show_alloc_heap);

    show_total_size_used(heap_anchor);
    show_total_size_free(heap_anchor);
}

void show_alloc_mem_ex()
{
    pthread_mutex_lock(&mt_protect);
    ft_putstr_fd("\n", 1);

    execute_show_alloc_mem_ex();

    pthread_mutex_unlock(&mt_protect);
}