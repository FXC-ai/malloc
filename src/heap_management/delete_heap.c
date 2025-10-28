#include "../inc/malloc.h"


/*
    Il y a 3 cas a traiter :
         - []->[X]->[] (1)
         - [X]->[]->[] (2)
         - []->[]->[X] (3)
         - [X]         (4)
*/
void delete_heap(t_heap *heap_to_delete, t_heap **heap_anchor)
{
    /*(4)*/
    if (heap_to_delete->prev == NULL && heap_to_delete->next == NULL)
    {
        munmap(heap_to_delete, heap_to_delete->total_size);
        *heap_anchor = NULL;
        return;
    }

    /*(1)*/
    if (heap_to_delete->next && heap_to_delete->prev)
    {
        heap_to_delete->prev->next = heap_to_delete->next;
        heap_to_delete->next->prev = heap_to_delete->prev;
    }

    /*(2)*/
    if (heap_to_delete->prev == NULL && heap_to_delete->next != NULL)
    {
        heap_to_delete->next->prev = NULL;
        *heap_anchor = heap_to_delete->next;
    }

    /*(3)*/
    if (heap_to_delete->prev != NULL && heap_to_delete->next == NULL)
    {
        heap_to_delete->prev->next = NULL;

    }

    munmap(heap_to_delete, heap_to_delete->total_size);
}