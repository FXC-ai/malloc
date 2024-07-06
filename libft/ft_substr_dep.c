/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 09:57:09 by fcoindre          #+#    #+#             */
/*   Updated: 2022/10/30 16:40:34 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	len_to_cpy;
	char	*result;
	size_t	i;

	len_s = ft_strlen(s);
	len_to_cpy = 0;

	if (start > len_s)
		start = len_s;

    if (len >= (len_s - start))
	{
        len_to_cpy = (len_s - start) + 1;
	}
	else if (len < (len_s - start))
	{
		len_to_cpy = len + 1;
	}

	result = malloc(sizeof(char) * len_to_cpy);
	if (result == NULL)
		return (NULL);
	
	i = 0;
	while (i < len_to_cpy)
	{
		result[i] = s[i + start];
		i++;
	}
	
	result[i] = '\0';


	return (result);
}

#include <stdio.h>

int main()
{	

	char *str = "lorem ipsum dolor sit amet";
	unsigned int start = 0;
	size_t len = 10;


	char *result = ft_substr(str, start, len);
	printf("result = %s\n", result);

	return 0;

}
