#include <unistd.h>

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_isspace(char ch)
{
	return (ch == ' ' || ch == '\t' || ch == '\n');
}

void	print_word(char *s)
{
	while (*s && !ft_isspace(*s))
		write(1, s++, 1);
}

int	last_word(char *s, int i)
{
	while(i >= 0 && ft_isspace(s[i]))
		i--;
	return (i < 0);
}

void	rev_wstr(char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (i >= 0 && ft_isspace(s[i]))
		i--;
	while (i >= 0)
	{
		if (!ft_isspace(s[i]) && (i - 1 < 0 || ft_isspace(s[i - 1])))
		{
			print_word(s + i);
			if (!last_word(s, i - 1))
				write(1, " ", 1);
		}
		i--;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}
