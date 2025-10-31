#include "../inc/malloc.h"


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

    me

}


void *calloc(size_t nmemb, size_t size)
{
    pthread_mutex_lock(&mt_protect);
    
    //ft_putstr_fd("calloc : ",1);
    //ft_putsize_t(size);
    //ft_putstr_fd("\n",1);
    
    void *ptr = execute_malloc(size);
    ft_bzero(ptr, round_nearest_multiple(size, BLOCK_MIN_SIZE));
    pthread_mutex_unlock(&mt_protect);

    return ptr;
}
