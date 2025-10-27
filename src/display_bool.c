#include "../inc/malloc.h"

void display_bool(t_bool bool)
{
    if (bool == TRUE)
        ft_putstr_fd("TRUE", 1);
    else
        ft_putstr_fd("FALSE", 1);
}