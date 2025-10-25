#include "../inc/malloc.h"


void add_heap_front(t_heap **heap_start, t_heap *heap)
{
    write(1, "**heap_start : ", 15);
    display_hex((uintptr_t ) heap_start);
    write(1, "\n", 1);

    write(1, "heap         : ", 7);
    display_hex((uintptr_t ) heap);
    write(1, "\n", 1);

    /*
        LE PROBLEME EST ICI !!!!!!!!!
        JE PASSE EN PARAMETRE LA VARIABLE GLOBALE...
        QUI EST A NULL
        IL FAUT UTILISER DIRECTEMENT HEAP_ANCHOR ???
    */

    if (*heap_start == NULL)
    {
        *heap_start = heap;
        return;
    }

        

    heap->next = *heap_start;
    (*heap_start)->prev = heap;
    *heap_start = heap;

}