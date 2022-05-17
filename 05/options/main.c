#include <unistd.h>

#define USAGE "options: abcdefghijklmnopqrstuvwxyz\n"
#define ERROR "Invalid Option\n"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	islowercaseletter(char ch)
{
	return (ch >= 'a' && ch <= 'z');
}

int	validate_options(char **args, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (args[i][j])
		{
			if (j == 0 && args[i][j] != '-')
				return (0);	
			else if (j > 0 && !islowercaseletter(args[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

unsigned int	set_bit(unsigned int options, int pos)
{
	options |= (1 << pos);
	return (options);
}

int	test_bit(unsigned int n, unsigned int pos)
{
	return ((n & (1 << pos)) > 0);
}

void	print_bits(unsigned int n)
{
	int	i = 31;

	while (i >= 0)
	{
		if (test_bit(n, i))
			write(1, "1", 1);
		else
			write(1, "0", 1);
		if (i > 0 && i % 8 == 0)
			write(1, " ", 1);
		i--;
	}
}

void	represent(char **s, int size)
{
	unsigned int	options = 0;
	int				i;
	int				j;

	i = 1;
	while (i < size)
	{
		j = 1;
		while (s[i][j])
		{
			if (s[i][j] == 'h')
			{
				write(1, USAGE, ft_strlen(USAGE));
				return ;
			}
			else if (islowercaseletter(s[i][j]))
				options = set_bit(options, s[i][j] - 'a');
			j++;
		}
		i++;
	}
	print_bits(options);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		write(1, USAGE, ft_strlen(USAGE));
	else
	{
		if (validate_options(argv, argc))
			represent(argv, argc);
		else
			write(1, ERROR, ft_strlen(ERROR));
	}
	return (0);
}