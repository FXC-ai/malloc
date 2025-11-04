#include "libft.h"

void ft_putsize_t (size_t nb)
{
    const char *str = "0123456789";
    if (nb / 10)
    {
        ft_putsize_t(nb / 10);
    }
    write(1, &str[nb % 10], 1);
}