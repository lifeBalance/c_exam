#include <unistd.h>

#define	SIZE 2048
#define	OPENING '['
#define	CLOSING ']'

int		match(char *program, int i);

int	main(int argc, char **argv)
{
	char	data[SIZE] = {0};
	char			*program;
	int				i;
	int				j;

	if (argc == 2)
	{
		program = argv[1];
		i = 0;
		j = 0;
		while (program[i])
		{
			if (program[i] == '>')
				j++;
			else if (program[i] == '<')
				j--;
			else if (program[i] == '+')
				data[j]++;
			else if (program[i] == '-')
				data[j]--;
			else if (program[i] == '.')
				write(1, data + j, 1);
			else if (program[i] == '[' && data[j] == 0)
				i = match(program, i);
			else if (program[i] == ']' && data[j] != 0)
				i = match(program, i);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}

int		match(char *program, int i)
{
	int		matches;
	
	matches = 0;
	if (program[i] == OPENING)
	{
		while (matches != 1)
		{
			i++;
			if (program[i] == CLOSING)
				matches++;
			else if (program[i] == OPENING)
				matches--;
		}
	}
	else if (program[i] == CLOSING)
	{
		while (matches != 1)
		{
			i--;
			if (program[i] == OPENING)
				matches++;
			else if (program[i] == CLOSING)
				matches--;
		}
	}
	return (i);
}
