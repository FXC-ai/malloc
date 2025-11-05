#include "../../includes/malloc.h"

t_bool delete_heap_authorization(t_heap *heap)
{

    if 
    (
        heap->prev == NULL && 
        heap->next == NULL &&
        heap->group != LARGE
    )
    {
        return FALSE;
    }

    return TRUE;

}