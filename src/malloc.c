#include "../inc/malloc.h"

void *malloc (size_t size)
{
    (void) size;

    
    write(1, "FX\n", 3);
    return NULL;
}
