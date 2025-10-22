#include "../inc/malloc.h"

void display_hex (uintptr_t nb)
{
    const char *str = "0123456789abcdef";
    if (nb / 16)
    {
        display_hex( nb / 16);
    }
    write(1, &str[nb % 16], 1);
}