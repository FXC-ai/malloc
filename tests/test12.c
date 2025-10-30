#include "../inc/malloc.h"

int main ()
{
    void **ptr[5];
    int i;

    for (i = 0; i < 5; i++)
    {
        ptr[i] = malloc(128);
        if (ptr[i] == NULL)
        {
            return 1;
        }
    }
	show_alloc_mem();

    free(ptr[1]);
    free(ptr[3]);
    
	show_alloc_mem();

    free(ptr[2]);

	show_alloc_mem();

    void *ptr_sup = malloc(128);

    (void) ptr_sup;
	show_alloc_mem();

    void *ptr_sup2 = malloc(128);

    (void) ptr_sup2;
	show_alloc_mem();

    return 0;
}