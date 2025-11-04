#include "../../includes/malloc.h"

int main()
{
    char *ptr1 = malloc(0);

    ft_putstr_fd("ptr1 = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr1, 1);
    ft_putstr_fd("\n",1);

    char *ptr2 = realloc(ptr1, 32);

    ft_putstr_fd("ptr2 = ", 1);
    ft_putnb_hex_fd((uintptr_t) ptr2, 1);
    ft_putstr_fd("\n",1);

    show_alloc_mem();
    ft_putstr_fd("\n",1);

    return 0;
}