#include "../inc/malloc.h"

void ft_putnb_hex (uintptr_t nb)
{
    const char *str = "0123456789abcdef";
    if (nb / 16)
    {
        ft_putnb_hex( nb / 16);
    }
    else
    {
        write(1, "0x", 2);
    }
    write(1, &str[nb % 16], 1);
}