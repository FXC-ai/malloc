#include "../../includes/malloc.h"

int main()
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

    write(1, "\n",1);
    show_alloc_mem();

    free(ptr[0]);
    write(1, "\n",1);
    show_alloc_mem();

    free(ptr[1]);
    write(1, "\n",1);
    show_alloc_mem();

    free(ptr[2]);
    write(1, "\n",1);
    show_alloc_mem();

    free(ptr[3]);
    write(1, "\n",1);
    show_alloc_mem();

    free(ptr[4]);
    write(1, "\n",1);
    show_alloc_mem();

    return 0;
}