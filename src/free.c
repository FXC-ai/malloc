#include "../inc/malloc.h"

/*
** ─────────────────────────────────────────────────────────────────────────────
** Fonction : execute_free
**
** Description :
**     Libère un bloc précédemment alloué par malloc().
**
**     Étapes principales :
**     1. Vérifie que le pointeur appartient à une heap connue.
**     2. Marque le bloc comme libre.
**     3. Fusionne avec les blocs adjacents libres pour éviter la fragmentation.
**     4. Si le bloc est en fin de chaîne, il est nettoyé et retiré.
**     5. Si la heap devient vide (aucun bloc restant), elle est supprimée.
**
** Paramètres :
**     ptr — pointeur retourné par malloc() ou realloc().
**
** Retour :
**     Aucun (void). Si le pointeur est invalide ou NULL, la fonction ne fait rien.
**
** Remarques :
**     - La fonction ne tente pas de vérifier si le pointeur a déjà été libéré.
**     - Les blocs fusionnés réduisent la fragmentation mémoire interne.
**     - Une heap vide est désallouée pour libérer la mémoire au système.
**
** ─────────────────────────────────────────────────────────────────────────────
*/
void execute_free(void *ptr)
{
    //ft_putstr_fd("free : ", 1);
    //ft_putnb_hex((uintptr_t) ptr);
    
    if (ptr == NULL) 
    {
        ft_putnb_hex((uintptr_t) ptr);
        ft_putstr_fd("\n ", 1);
        return;
    }

    // On récupère le pointeur vers la structure du bloc associée à la zone mémoire
    t_block *block_to_free = BLOCK_UNSHIFT(ptr);

    // Recherche de la heap contenant ce bloc
    t_heap *heap_found = find_heap_from_ptr(heap_anchor, ptr);

    // Si aucune heap ne correspond au pointeur, on ignore l’appel
    if (heap_found == NULL)
    {
        ft_putnb_hex((uintptr_t) ptr);

        ft_putstr_fd("pas trouvé \n ", 1);

        return;
    }

    // Marque le bloc comme libre
    block_to_free->is_free = TRUE;

    // Fusion avec le bloc précédent s’il est également libre
    block_to_free = merge_previous_block(heap_found, block_to_free);

    // Fusion avec le bloc suivant s’il est libre
    merge_next_block(heap_found, block_to_free);

    // ───────────────────────────────────────────────
    // Si le bloc libéré est le dernier de la heap,
    // on le nettoie et on met à jour les liens
    // ───────────────────────────────────────────────
    if (block_to_free->next == NULL) 
    {
        if (block_to_free->prev)
        {
            block_to_free->prev->next = NULL;
        }

        // Nettoyage de la mémoire (métadonnées + données)
        ft_bzero(block_to_free, block_to_free->data_size + sizeof(t_block));

        // Mise à jour du compteur de blocs de la heap
        heap_found->block_count -= 1;
    }

    // ───────────────────────────────────────────────
    // Si la heap ne contient plus aucun bloc,
    // on la supprime complètement
    // ───────────────────────────────────────────────
    if (heap_found->block_count == 0)
    {
        delete_heap(heap_found, &heap_anchor);
    }
}

void free(void *ptr)
{
    pthread_mutex_lock(&mt_protect);

    execute_free(ptr);

    pthread_mutex_unlock(&mt_protect);
}

