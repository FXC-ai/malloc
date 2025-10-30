#include "../inc/malloc.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
	char	*pd;
	char	*ps;

	if (!dst && !src)
		return (NULL);
	pd = (char *) dst;
	ps = (char *) src;
	if (pd > ps && (ps + len) > pd)
	{
		while (len)
		{
			len--;
			*(pd + len) = *(ps + len);
		}
	}
	else
	{
		while (len)
		{
			*pd++ = *ps++;
			len--;
		}
	}
	return (dst);
}
