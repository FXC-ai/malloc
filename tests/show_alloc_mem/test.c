#include "../../includes/malloc.h"

int main()
{
    void *ptr1 = malloc(128);
    void *ptr2 = malloc(128);
    void *ptr3 = malloc(128);
    void *ptr4 = malloc(128);

    show_alloc_mem();
    ft_putstr_fd("\n", 1);

    free (ptr1);

    show_alloc_mem();
    ft_putstr_fd("\n", 1);


    void *ptr5 = realloc(ptr2, 256);

    show_alloc_mem();
    ft_putstr_fd("\n", 1);


    free(ptr5);

    show_alloc_mem();

    ft_putstr_fd("\n", 1);

    free(ptr3);

    show_alloc_mem();
    ft_putstr_fd("\n", 1);


    free(ptr4);


    show_alloc_mem();
    ft_putstr_fd("END\n", 1);




    return 0;
}