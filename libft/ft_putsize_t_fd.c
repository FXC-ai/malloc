#include "libft.h"

void ft_putsize_t_fd (size_t nb, int fd)
{
    const char *str = "0123456789";
    if (nb / 10)
    {
        ft_putsize_t_fd(nb / 10, fd);
    }
    write(fd, &str[nb % 10], 1);
}