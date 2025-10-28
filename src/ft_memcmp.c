#include "../inc/malloc.h"

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
