#include "../../includes/malloc.h"

t_heap *heap_anchor = NULL;
pthread_mutex_t mt_protect = PTHREAD_MUTEX_INITIALIZER;

/*
** ─────────────────────────────────────────────────────────────────────────────
** Fonction : execute_malloc
**
** Description :
**     Implémentation personnalisée de malloc().
**     Alloue dynamiquement une zone mémoire de la taille demandée, en gérant
**     manuellement les heaps (zones de mémoire) et les blocks (sous-parties de heap).
**
**     L’algorithme suit trois étapes principales :
**
**     1. Recherche dans les heaps existantes un block libre de taille suffisante.
**     2. Si aucun block libre n’est trouvé, on tente d’ajouter un block à une heap
**        existante disposant d’assez d’espace libre.
**     3. Si aucune heap adéquate n’existe, une nouvelle heap est créée.
**
** Paramètres :
**     size — taille (en octets) de la mémoire demandée.
**
** Retour :
**     Pointeur vers la zone mémoire allouée.
**     Retourne NULL en cas d’erreur ou si la taille demandée est nulle.
**
** Remarques :
**     - Les heaps sont classées en trois groupes : TINY, SMALL, LARGE.
**     - Chaque bloc est aligné sur un multiple de BLOCK_MIN_SIZE.
**
** ─────────────────────────────────────────────────────────────────────────────
*/
void *execute_malloc (size_t size)
{
    size_t size_alloc;
    t_block *block = NULL;
    t_block *block_found = NULL;
    t_heap *heap_found = NULL;
    t_heap *new_heap = NULL;

    
    // Si la taille demandée est nulle, on ne fait rien
    if (size == 0) {return NULL;}

    // On arrondit la taille demandée au multiple le plus proche de BLOCK_MIN_SIZE
    size_alloc = round_nearest_multiple(size, BLOCK_MIN_SIZE);

    // Détermination du groupe de heap (TINY, SMALL ou LARGE) en fonction de la taille du bloc demandé
    t_heap_group heap_group = get_heap_group_from_block_size(size_alloc);

    // Détermination de la taille totale de heap nécessaire pour ce groupe
    size_t heap_size = get_heap_size_from_heap_group(heap_group, size_alloc);

    // ───────────────────────────────────────────────
    // 1. Recherche d’un bloc libre déjà existant
    //    dans les heaps actuellement allouées
    // ───────────────────────────────────────────────

    if (heap_anchor != NULL)
    {
        heap_found = heap_anchor;

        while (heap_found)
        {
            if (heap_found->group == heap_group)
            {
                block_found = search_block
                (
                    HEAP_SHIFT(heap_found),   // Premier bloc de la heap
                    size_alloc,               // Taille minimale recherchée
                    TRUE                      // On cherche un bloc libre (TRUE signifit "free")
                );
            }
            
            if (block_found != NULL)
            {
                // Si un bloc libre de taille suffisante est trouvé :
                // on le découpe si nécessaire
                split_block(heap_found, block_found, size_alloc);

                return BLOCK_SHIFT(block_found); // Retourne le pointeur vers la zone de données
            }

            heap_found = heap_found->next;
        }
    }

    // ───────────────────────────────────────────────
    // 2. Aucune correspondance trouvée, mais il existe
    //    une heap du bon groupe avec assez d’espace libre
    // ───────────────────────────────────────────────

    if (heap_anchor != NULL)
    {
        heap_found = search_heap(
            heap_anchor,
            heap_group,
            0,                             // On ne filtre pas sur la taille totale
            size_alloc + sizeof(t_block),  // On vérifie l’espace libre disponible
            0                              // Pas de contrainte sur le nombre de blocs
        );

        // On ajoute un nouveau bloc à la fin de cette heap existante
        block = add_block_back(heap_found, size_alloc, FALSE);
    }

    // ───────────────────────────────────────────────
    // 3. Aucune heap disponible : création d’une nouvelle heap
    // ───────────────────────────────────────────────
    if (heap_found == NULL)
    {
        new_heap = create_heap(heap_group, heap_size);
        if (new_heap == NULL)
        {
            // Échec de l’allocation de la nouvelle heap
            return NULL;
        }

        // On insère la nouvelle heap au début de la chaîne
        add_heap_front(&heap_anchor, new_heap);

        // On initialise le premier bloc de cette nouvelle heap
        block = init_block_chain(heap_anchor, size_alloc);
    }

    // ft_putnb_hex_fd((uintptr_t) BLOCK_SHIFT(block));
    // ft_putstr_fd("\n", 1);

    // On renvoie le pointeur vers la zone de données du bloc alloué
    return BLOCK_SHIFT(block);
}

void *malloc (size_t size)
{
    pthread_mutex_lock(&mt_protect);
    
    void *ptr = execute_malloc(size);
    
    int fd = open("malloc.log", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd > 0 && DEBUG_MOD == 1)
    {
        ft_putstr_fd("malloc(", fd);
        ft_putsize_t_fd(size, fd);
        ft_putstr_fd(")                   => ",fd);
        ft_putnb_hex_fd((uintptr_t) ptr, fd);
        ft_putstr_fd("\n",fd);
    }

    close(fd);
    
    
    pthread_mutex_unlock(&mt_protect);
    return ptr;
}
