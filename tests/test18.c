#include "../inc/malloc.h"

int main()
{
    char *ptr1 = malloc(32);

    char *src = "Hello World ! Keep the hope !\n";

    ft_memcpy(ptr1, src, ft_strlen(src));

    ft_putstr_fd(ptr1, 1);
    show_alloc_mem();
    ft_putstr_fd("\n",1);

    char* realloc_ptr1 = realloc(ptr1, 15);

    ft_putstr_fd(realloc_ptr1, 1);
    ft_putstr_fd("\n",1);
    show_alloc_mem();
    ft_putstr_fd("\n",1);

    char* realloc_ptr2 = realloc(ptr1, 32);

    ft_putstr_fd(realloc_ptr2, 1);
    ft_putstr_fd("\n",1);
    show_alloc_mem();
    ft_putstr_fd("\n",1);

    return 0;
}