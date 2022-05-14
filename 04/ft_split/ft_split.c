#include <stdlib.h>

int	ft_isspace(char ch)
{
	return (ch == ' ' || ch == '\t' || ch == '\n');
}

int	count_words(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (!ft_isspace(*s))
		{
			count++;
			while (*s && !ft_isspace(*s))
				s++;
		}
		while (*s && ft_isspace(*s))
			s++;
	}
	return (count);
}

int	word_len(char *s)
{
	int	len;

	len = 0;
	while(s[len] && !ft_isspace(len))
		len++;
	return (len);
}

char	**ft_split(char *str)
{
	char	**arr;
	int		words;
	int		i;

	words = count_words(str);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (0);
	words = 0;
	while (*str)
	{
		if (!ft_isspace(*str))
		{
			arr[words] = (char *)malloc(word_len(str) + 1);
			if (!arr[words])
				return (0);
			i = 0;
			while (*str && !ft_isspace(*str))
				arr[words][i++] = *str++;
			arr[words][i] = 0;
			words++;
			arr[words] = 0;
		}
		while (*str && ft_isspace(*str))
			str++;
	}
	return (arr);
}
