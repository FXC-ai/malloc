#include "../inc/malloc.h"

void ft_putbool(t_bool bool)
{
    if (bool == TRUE)
    {
        ft_putstr_fd("\033[32mTRUE\033[0m", 1);
    }
    else
    {
        ft_putstr_fd("\033[31mFALSE\033[0m", 1);
    }
}