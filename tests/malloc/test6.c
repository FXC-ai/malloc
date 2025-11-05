#include "../../includes/malloc.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst_cpy;
	char	*src_cpy;

	if (!dst && !src)
		return (NULL);
	dst_cpy = (char *) dst;
	src_cpy = (char *) src;
	i = 0;
	while (i < n)
	{
		dst_cpy[i] = src_cpy[i];
		i++;
	}
	return (dst);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*cs1;
	char	*cs2;
	size_t	i;
	int		result;

	cs1 = (char *) s1;
	cs2 = (char *) s2;
	i = 0;
	result = 0;
	while (i < n)
	{
		if (cs1[i] != cs2[i])
		{
			result = (unsigned char) cs1[i] - (unsigned char) cs2[i];
			return (result);
		}
		i++;
	}
	return (result);
}

int main()
{
    char *ptr1 = malloc(21);

    char *dst = malloc(12);

    display_t_block((t_block *) BLOCK_UNSHIFT(dst));

    show_alloc_mem();

    char *src = "Hello World !\n";

    if (dst == NULL)
        return 1;

    ft_memcpy(dst, src, 13);

    ft_putstr_fd(dst, 1);
    write(1, "\n",1);
    
    display_t_block((t_block *) BLOCK_UNSHIFT(dst));

    show_alloc_mem();

    if (!ft_memcmp(dst, src, 13))
    {
        return 1;
    }
    return 0;
}