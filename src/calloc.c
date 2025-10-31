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
    
    void *ptr = execute_calloc(nmemb, size);
    
    int fd = open("malloc.log", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd > 0 && DEBUG_MOD == 1)
    {
        ft_putstr_fd("calloc(", fd);
        ft_putsize_t_fd(nmemb, fd);
        ft_putstr_fd(",",fd);
        ft_putsize_t_fd(size, fd);
        ft_putstr_fd(")              => ",fd);
        ft_putnb_hex_fd((uintptr_t) ptr, fd);
        ft_putstr_fd("\n",fd);
    }
    close(fd);

    pthread_mutex_unlock(&mt_protect);

    return ptr;
}
