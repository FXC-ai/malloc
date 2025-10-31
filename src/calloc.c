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

    ft_bzero(ptr, total);

    return ptr;
}


void *calloc(size_t nmemb, size_t size)
{
    pthread_mutex_lock(&mt_protect);
    
    ft_putstr_fd("\033[0;35mcalloc : \033[0m", 1);


    ft_putsize_t(nmemb);
    ft_putstr_fd(", ",1);
    ft_putsize_t(size);

    
    void *ptr = execute_calloc(nmemb, size);

    ft_putstr_fd(" => ",1);
    ft_putnb_hex((uintptr_t) ptr);
     ft_putstr_fd("\n",1);

    pthread_mutex_unlock(&mt_protect);

    return ptr;
}
