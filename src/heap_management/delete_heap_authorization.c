#include "../../includes/malloc.h"
/*
** Voici la version initial de cette fonction.
** Il ne faut pas reproduire ceci.
** La fonction autorise la supression d une heap que  
**
** Je pense qu'il faut utiliser un getrlimit
**
*/
t_bool delete_heap_authorization(t_heap *heap)
{
    (void) heap;
    /*
    if 
    (
        heap->prev == NULL && 
        heap->next == NULL &&
        heap->group != LARGE
    )
    {
        return FALSE;
    }
    */
    return FALSE;

}