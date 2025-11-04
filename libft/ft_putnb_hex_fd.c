#include "libft.h"

void ft_putnb_hex_fd (uintptr_t nb, int fd)
{
    const char *str = "0123456789abcdef";
    if (nb / 16)
    {
        ft_putnb_hex_fd( nb / 16, fd);
    }
    else
    {
        write(fd, "0x", 2);
    }
    write(fd, &str[nb % 16], 1);
}