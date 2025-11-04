#include "../../includes/malloc.h"

#define COLOR_RESET   "\033[0m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_MAGENTA "\033[35m"

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

static const char *get_heap_color(t_heap_group group)
{
    if (group == TINY)
        return COLOR_BLUE;
    else if (group == SMALL)
        return COLOR_YELLOW;
    else
        return COLOR_MAGENTA;
}

static void show_alloc_heap(t_heap *heap)
{
    const char *color = get_heap_color(heap->group);

    ft_putconststr_fd(color, 1);  // Début de la couleur

    display_t_heap_group(heap->group);
    ft_putstr_fd(": total size     = ", 1);
    ft_putsize_t(heap->total_size); 
    ft_putstr_fd("\n       block count    = ", 1);
    ft_putsize_t(heap->block_count);
    ft_putstr_fd("\n       non used space = ", 1);
    ft_putsize_t(heap->free_size);



    ft_putstr_fd("\n       used space     = ", 1);
    ft_putsize_t(heap->total_size - heap->free_size);


    ft_putstr_fd("\n       metadata space = ", 1);
    ft_putsize_t(sizeof(t_heap) + heap->block_count * sizeof(t_block));

    ft_putstr_fd("\n       data space     = ", 1);
    ft_putsize_t(heap->total_size - sizeof(t_heap) - heap->free_size - (sizeof(t_block) * heap->block_count));
    ft_putstr_fd("\n", 1);
    ft_putstr_fd("\n", 1);

    ft_putconststr_fd(COLOR_RESET, 1);  // Réinitialise la couleur
    ft_putstr_fd("BLOCKS ALLOCATED DETAILS :\n", 1);

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
    ft_putstr_fd("__________________________________________\n", 1);


    pthread_mutex_unlock(&mt_protect);
}