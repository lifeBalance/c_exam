#include <unistd.h>
#include <stdlib.h>

int		ft_isspace(char ch)
{
	return (ch == ' ' || ch == '\t' || ch == '\n');
}

int		word_len(char *s)
{
	int	len;

	len = 0;
	while (s[len] && !ft_isspace(s[len]))
		len++;
	return (len);
}

void	rostring(char *s)
{
	char	*first;
	int		i;

	while (ft_isspace(*s))
		s++;
	if (*s)
	{
		first = (char *)malloc(word_len(s) + 1);
		if (!first)
			return ;
		i = 0;
		while (*s && !ft_isspace(*s))
			first[i++] = *s++;
		first[i] = 0;
		while (*s && ft_isspace(*s))
			s++;
	}
	while (*s)
	{
		while (*s && ft_isspace(*s))
			s++;
		if (*s && !ft_isspace(*s))
		{
			while (*s && !ft_isspace(*s))
			{
				write(1, s, 1);
				s++;
			}
			write(1, " ", 1);
		}
	}
	write(1, first, word_len(first));
	free(first);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rostring(argv[1]);
	write(1, "\n", 1);
	return (0);
}
