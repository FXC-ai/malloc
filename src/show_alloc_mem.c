#include "../inc/malloc.h"

/* ============================================================================
** Fonction : show_alloc_block
**
** Rôle :
**     Affiche les informations d’un bloc mémoire :
**       - Adresse de début et de fin
**       - Taille du bloc (en octets)
**
** ============================================================================
*/
static void show_alloc_block(t_block *block)
{
    if (block->is_free == FALSE)
    {
        ft_putnb_hex_fd((uintptr_t) BLOCK_SHIFT(block), 1);
        ft_putstr_fd(" - ", 1);
        ft_putnb_hex_fd((uintptr_t) (BLOCK_SHIFT(block) + block->data_size), 1);
        ft_putstr_fd(" : ", 1);
        ft_putsize_t(block->data_size);
        ft_putstr_fd(" bytes", 1);
        write(1, "\n", 1);
    }
}


/* ============================================================================
** Fonction : show_alloc_heap
**
** Rôle : Affiche les informations d’une heap : son type (TINY, SMALL, LARGE),
** son adresse puis tous les blocs qu’elle contient
** ============================================================================
*/
static void show_alloc_heap(t_heap *heap)
{
    display_t_heap_group(heap->group);
    ft_putstr_fd(" : ", 1);
    ft_putnb_hex_fd((uintptr_t) heap, 1);
    write(1, "\n" ,1);

    block_chain_iter((t_block*) HEAP_SHIFT(heap), show_alloc_block);
}

/* ============================================================================
** Fonction : show_total_size
**
** Rôle : Calcule et affiche la quantité totale de mémoire allouée (en 
** additionnant la taille des blocs non libres dans toutes les heaps).
** ============================================================================
*/
static void show_total_size(t_heap *heap)
{
    size_t total = 0;

    t_heap *current_heap = heap;

    while (current_heap)
    { 
        total += block_chain_datasize(HEAP_SHIFT(current_heap), FALSE);
        current_heap = current_heap->next;
    }

    ft_putstr_fd("Total : ", 1);
    ft_putsize_t(total);
    ft_putstr_fd(" bytes\n", 1);
    
}

/* ============================================================================
** Fonction : show_alloc_mem
**
** Rôle :
**     Point d’entrée principal pour afficher la mémoire actuellement allouée.
**
** Étapes :
**     1. Vérifie qu’il existe au moins une heap.
**     2. Affiche chaque heap et ses blocs via show_alloc_heap().
**     3. Termine par l’affichage du total alloué via show_total_size().
**
** Exemple (selon le sujet) :
**
**     TINY : 0xA0000
**     0xA0020 - 0xA004A : 42 bytes
**     0xA006A - 0xA00BE : 84 bytes
**     SMALL : 0xAD000
**     0xAD020 - 0xADEAD : 3725 bytes
**     LARGE : 0xB0000
**     0xB0020 - 0xBBEEF : 48847 bytes
**     Total : 52698 bytes
**
** ============================================================================
*/
void execute_show_alloc_mem()
{
    t_heap_chain_iter(heap_anchor, show_alloc_heap);

    show_total_size(heap_anchor);
}

void show_alloc_mem()
{
    pthread_mutex_lock(&mt_protect);
    

    execute_show_alloc_mem();

    pthread_mutex_unlock(&mt_protect);
}