#include "../inc/malloc.h"

int main()
{
    char *ptr1 = malloc(0);

    ft_putstr_fd("ptr1 = ", 1);
    ft_putnb_hex((uintptr_t) ptr1);
    ft_putstr_fd("\n",1);

    show_alloc_mem();
    ft_putstr_fd("\n",1);

    return 0;
}