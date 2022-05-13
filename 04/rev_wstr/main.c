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

int	print_word(char *s)
{
	int	i;

	i = 0;
	while (*s && !ft_isspace(*s))
		i += write(1, s++, 1);
	return (i);
}

int	last(char *s, int i)
{
	while(i >= 0 && ft_isspace(s[i]))
		i--;
	return (i < 0);
}

void	rev_wstr(char *s)
{
	int	i;
	int	len;

	len = ft_strlen(s);
	i = ft_strlen(s) - 1;
	while (i >= 0 && ft_isspace(s[i]))
		i--;
	while (i >= 0)
	{
		if (i - 1 < 0 || ft_isspace(s[i - 1]))
		{
			if (!ft_isspace(s[i]))
			{
				print_word(s + i);
				if (!last(s, i - 1))
					write(1, " ", 1);
			}
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