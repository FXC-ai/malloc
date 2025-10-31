#include "../inc/malloc.h"

int main()
{
    char *ptr1 = malloc(21);

    char *dst = malloc(12);

    display_t_block((t_block *) BLOCK_UNSHIFT(dst));

    show_alloc_mem();

    char *src = "Hello World !\n";

    if (dst == NULL)
        return 1;

    ft_memcpy(dst, src, 13);

    ft_putstr_fd(dst, 1);
    write(1, "\n",1);
    
    display_t_block((t_block *) BLOCK_UNSHIFT(dst));

    show_alloc_mem();

    if (!ft_memcmp(dst, src, 13))
    {
        return 1;
    }
    return 0;
}