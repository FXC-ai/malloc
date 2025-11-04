#include "../../includes/malloc.h"
#include <limits.h>

#define M 1024

int main()
{
    ft_putsize_t(SIZE_MAX);
    ft_putstr_fd("\n",1);

    // Test 1
    ft_putsize_t(M);
    ft_putstr_fd("\n", 1);
    char *ptr1 = malloc(M);
    if (ptr1 != NULL) {
        ft_putnb_hex_fd((uintptr_t)ptr1, 1);
    } else {
        ft_putstr_fd("Échec de l'allocation\n", 1);
    }
    ft_putstr_fd("\n", 1);
    ft_putstr_fd("\n", 1);

    // Test 2
    ft_putsize_t(M * 1024);
    ft_putstr_fd("\n", 1);
    char *ptr2 = malloc(M * 1024);
    if (ptr2 != NULL) {
        ft_putnb_hex_fd((uintptr_t)ptr2, 1);
    } else {
        ft_putstr_fd("Échec de l'allocation\n", 1);
    }
    ft_putstr_fd("\n", 1);
    ft_putstr_fd("\n", 1);

    // Test 3
    ft_putsize_t(M * 1024 * 1024);
    ft_putstr_fd("\n", 1);
    char *ptr3 = malloc(M * 1024 * 1024);
    if (ptr3 != NULL) {
        ft_putnb_hex_fd((uintptr_t)ptr3, 1);
    } else {
        ft_putstr_fd("Échec de l'allocation\n", 1);
    }
    ft_putstr_fd("\n", 1);
    ft_putstr_fd("\n", 1);

    // Test 4
    ft_putsize_t(M * 1024 * 1024 * 1024);
    ft_putstr_fd("\n", 1);
    char *ptr4 = malloc(M * 1024 * 1024 * 1024);
    if (ptr4 != NULL) {
        ft_putnb_hex_fd((uintptr_t)ptr4, 1);
    } else {
        ft_putstr_fd("Échec de l'allocation\n", 1);
    }
    ft_putstr_fd("\n", 1);
    ft_putstr_fd("\n", 1);

    show_alloc_mem_ex();


    return 0;
}

