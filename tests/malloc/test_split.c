#include "../../includes/malloc.h"

static int	ft_word_count(char *str, char c)
{
	int	word_count;
	int	i;
	int	word_check;

	i = 0;
	word_count = 0;
	word_check = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			word_check++;
		if (str[i] == c && word_check > 0)
		{
			word_count++;
			word_check = 0;
		}
		i++;
	}
	if (word_check > 0)
	{
		word_count++;
	}
	return (word_count);
}

static int	ft_size_word(int index, char *str, char c)
{
	int		count;
	int		index_ini;

	index_ini = index;
	count = 0;
	while (str[index] != '\0' && str[index] != c)
	{
		index++;
	}
	count = index - index_ini;
	return (count);
}

static char	*ft_cpy_word(int i, int size_word, char *str)
{
	char	*word;
	int		j;

	word = malloc((size_word + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	j = 0;
	while (j < size_word)
	{
		word[j] = str[i];
		j++;
		i++;
	}
	word[j] = '\0';
	return (word);
}

static void	ft_free_tabs(char **tab, int h)
{
	int	i;

	i = 0;
	while (i <= h)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_split(char *str, char c)
{
	int		h;
	int		i;
	char	**tab;

	tab = malloc(sizeof(char *) * (ft_word_count(str, c) + 1));
	if (tab == NULL)
		return (NULL);
	h = 0;
	i = -1;
	while (h < ft_word_count(str, c))
	{
		if (ft_size_word(++i, str, c) > 0)
		{	
			tab[h] = ft_cpy_word(i, ft_size_word(i, str, c), str);
			if (tab[h] == NULL)
			{
				ft_free_tabs(tab, h);
				return (NULL);
			}
			i += ft_size_word(i, str, c);
			h++;
		}
	}
	tab[h] = NULL;
	return (tab);
}

int main()
{
    char *str1 = "Voila un test avec split !!!!!";

    char **splited = ft_split(str1, ' ');

    int i = 0;
    while (splited[i])
    {
        ft_putstr_fd(splited[i], 1);
        ft_putstr_fd("\n", 1);
        i++;
    }
    

    show_alloc_mem_ex();

    return 0;
}