#include "../inc/malloc.h"
#define BLUE "\033[34m"
#define RESET "\033[0m"




void display_t_block(t_block *block)
{

    write(1, "---------" BLUE "BLOCK INFOS" RESET "------\n", 37);


    write(1, "location    = ", 14);
    ft_putnb_hex((uintptr_t) block);
    write(1, "\n", 1);
    write(1, "\n", 1);

    write(1, "prev        = ", 14);
    ft_putnb_hex((uintptr_t) block->prev);
    write(1, "\n", 1);

    write(1, "next        = ", 14);
    ft_putnb_hex((uintptr_t) block->next);
    write(1, "\n", 1);
    write(1, "\n", 1);



    write(1, "data size   = ", 14);
    ft_putsize_t(block->data_size);
    write(1, "\n", 1);

    write(1, "is free     = ", 14);
    ft_putsize_t(block->is_free);
    write(1, "\n", 1);


    write(1, "--------------------------\n", 28);
}