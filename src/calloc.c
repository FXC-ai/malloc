#include "../includes/malloc.h"

void *execute_calloc(size_t nmemb, size_t size)
{
    if (size && nmemb > SIZE_MAX / size)
    {
        return NULL;
    }

    size_t total = nmemb * size;
    void *ptr = execute_malloc(total);
    if (ptr == NULL)
        return NULL;

    ft_bzero(ptr, total);

    return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
    pthread_mutex_lock(&mt_protect);
    
    void *ptr = execute_calloc(nmemb, size);
    
    pthread_mutex_unlock(&mt_protect);

    return ptr;
}
