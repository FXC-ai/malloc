#include "../inc/malloc.h"

int main()
{
    void *ptr_realloc  = realloc(NULL, 16);
    void *ptr_realloc1 = realloc(NULL, 16);
    void *ptr_realloc2 = realloc(NULL, 16);
    void *ptr_realloc3 = realloc(NULL, 32);

    show_alloc_mem();
    write(1, "\n",1);

    void *ptr_null = realloc(ptr_realloc, 0);

    show_alloc_mem();
    write(1, "\n",1);
    
    void *ptr_realloc4 = realloc(ptr_realloc3, 32);

    ft_putstr_fd("ptr_realloc4 = ",1);
    ft_putnb_hex_fd((uintptr_t) ptr_realloc4);
    ft_putstr_fd("\n",1);

    show_alloc_mem();
    write(1, "\n",1);


    void *ptr_realloc5 = realloc(ptr_realloc2, 149);

    ft_putstr_fd("ptr_realloc5 = ",1);
    ft_putnb_hex_fd((uintptr_t) ptr_realloc5);
    ft_putstr_fd("\n",1);

    show_alloc_mem();
    write(1, "\n",1);

    return 0;
}