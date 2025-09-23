#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{

	printf("%p\n%d\n%ld\n", s, c, n);
	size_t			i;
	unsigned char	*cs;
	// unsigned char	cc;
	i = 0;
	cs =  &(*(unsigned char *) s);
	// cc = (unsigned char) c;
	while (i < n)
	{

		printf("i = %ld,  s = %p, *s = %c \n", i, s + i, *((unsigned char *) s + i));

		if (*((unsigned char *) cs + i) == c)
		{
			void *r = s + i;
			return  r;
		}
		i++;

	}
	return (NULL);
}

int main()
{
    printf("---------- TEST 1 : memchr ------------\n");
    printf("%p\n", memchr("essai", 'e', 6));

    

    return 0;
}