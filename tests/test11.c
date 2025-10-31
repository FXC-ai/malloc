#include "../inc/malloc.h"


int main()
{

    void **ptr[9];
    void *tmp_ptr;
    int i;

    tmp_ptr = NULL;

    for (i = 0; i < 3; i++)
    {
        tmp_ptr = malloc(128);
        if (tmp_ptr == NULL)
        {
            return 1;
        }
        ptr[i] = tmp_ptr;
    }

    for (i = 0; i < 3; i++)
    {
        tmp_ptr = malloc(1024);
        if (tmp_ptr == NULL)
        {
            return 1;
        }
        ptr[i] = tmp_ptr;
    }

    for (i = 0; i < 3; i++)
    {
        tmp_ptr = malloc(4025);
        if (tmp_ptr == NULL)
        {
            return 1;
        }
        ptr[i] = tmp_ptr;
    }

    show_alloc_mem();

    return 0;
}