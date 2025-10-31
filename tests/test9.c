#include "../inc/malloc.h"

int main()
{
    void *ptr1 = malloc(0);

    show_alloc_mem();

    return 0;
}