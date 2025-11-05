#include "../../includes/malloc.h"

int main()
{
    void *ptr1 = malloc(64);
    void *ptr2 = malloc(16);
    void *ptr3 = malloc(16);
    void *ptr4 = malloc(16);

    show_alloc_mem_ex();


    free(ptr4);
    free(ptr3);
    free(ptr2);
    free(ptr1);


    show_alloc_mem_ex();
    
    void *ptr5 = malloc(16);

    show_alloc_mem_ex();


    return 0;
}