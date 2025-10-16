#include <stdio.h>
#include <unistd.h>

void *malloc (size_t size)
{
    (void) size;

    char c = 'o';
    write(1, &c, 1);
    return NULL;
}