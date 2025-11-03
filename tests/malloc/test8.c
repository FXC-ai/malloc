#include "../../inc/malloc.h"

int main()
{
    void **ptr[102];
    void *tmp_ptr;
    int i;

    tmp_ptr = NULL;

    for (i = 0; i < 102; i++)
    {
        tmp_ptr = malloc(128);
        if (tmp_ptr == NULL)
        {
            return 1;
        }
        ptr[i] = tmp_ptr;
    }

    write(1, "\n",1);
    show_alloc_mem();
    write(1, "\n",1);

    return 0;
}