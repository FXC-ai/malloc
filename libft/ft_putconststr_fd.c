#include "libft.h"

void	ft_putconststr_fd(const char *s, int fd)
{
	size_t	size_s;

	if (s != NULL)
	{
		size_s = ft_strlen(s);
		write (fd, s, size_s);
	}
}
