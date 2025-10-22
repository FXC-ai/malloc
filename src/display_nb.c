#include "../inc/malloc.h"

void display_nb (size_t nb)
{
    const char *str = "0123456789";
    if (nb / 10)
    {
        display_nb(nb / 10);
    }
    write(1, &str[nb % 10], 1);
}