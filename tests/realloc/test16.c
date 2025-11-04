#include "../../includes/malloc.h"

int main()
{
    void *ptr1 = malloc(128 + 179);
    void *ptr2 = malloc(128 + 2 * 179);
    void *ptr3 = malloc(128 + 3 * 179);
    void *ptr4 = malloc(128 + 4 * 179);

    free (ptr1);

    show_alloc_mem_ex();
    ft_putstr_fd("\n",1);
    
    void *null_ptr = realloc(ptr1, 128 + 179);
    void *ptr5 = realloc(ptr2, 1024);

    ft_putstr_fd("ptr5 = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr5, 1);
    ft_putstr_fd("\n",1);

    show_alloc_mem_ex();


    return 0;
}