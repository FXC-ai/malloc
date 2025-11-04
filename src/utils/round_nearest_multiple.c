#include "../../includes/malloc.h"

size_t round_nearest_multiple(size_t size, size_t multiple_of)
{
    if (size % multiple_of == 0)
    {
        return size;
    }
    else
    {
        return (size + BLOCK_MIN_SIZE - ((size + multiple_of) % multiple_of)); 
    }
}