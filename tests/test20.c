#include "../inc/malloc.h"

int main()
{
    char *ptr1 = calloc(150, sizeof(int));

    ft_putstr_fd("ptr1 = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr1, 1);
    ft_putstr_fd("\n",1);
    ft_putstr_fd(ptr1,1);
    ft_putstr_fd("\n",1);

    show_alloc_mem();


    char *ptr2 = realloc(ptr1, 1024 * sizeof(int));

    show_alloc_mem();

    return 0;
}