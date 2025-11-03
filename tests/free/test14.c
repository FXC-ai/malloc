#include "../../inc/malloc.h"

int main()
{

    void *ptr1 = malloc(16);
    void *ptr2 = malloc(16);
    void *ptr3 = malloc(16);
    void *ptr4 = malloc(16);
    void *ptr5 = malloc(16);

    show_alloc_mem();
    write(1, "\n" ,1);

    free(ptr1);
    show_alloc_mem();
    write(1, "\n" ,1);
    
    free(ptr4);
    show_alloc_mem();
    write(1, "\n" ,1);

    free(ptr3);
    show_alloc_mem();
    write(1, "\n" ,1);

    free(ptr2);
    show_alloc_mem();
    write(1, "\n" ,1);

    free(ptr5);
    show_alloc_mem();
    write(1, "\n" ,1);

    return 0;
}