#include "../../includes/malloc.h"

int main()
{
    void *ptr1 = malloc(16);
    void *ptr2 = malloc(16);
    void *ptr3 = malloc(16);
    void *ptr4 = malloc(16);

    show_alloc_mem_ex();

    free(ptr1);
    free(ptr3);

    show_alloc_mem_ex();

    //display_t_block((t_block *) BLOCK_UNSHIFT(ptr2));

    free(ptr4);


    show_alloc_mem_ex();

    return 0;
}