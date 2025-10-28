#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

void ft_putnb_hex (uintptr_t nb)
{
    const char *str = "0123456789abcdef";
    if (nb / 16)
    {
        ft_putnb_hex( nb / 16);
    }
    write(1, &str[nb % 16], 1);
}

int main()
{

    printf("Welcome back %zu\n", SIZE_MAX);

    void *ptr = malloc(1073741824);

    printf("%p\n", ptr);
    ft_putnb_hex((uintptr_t) ptr);


    printf("\n");

    return 0;
}