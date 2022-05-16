#include <unistd.h>

/*
**	I used a pointer (instead of an index) for the program in this version.
*/
#define	SIZE 2048

char	*match(char ch, char *prog)
{
	int	matches;

	matches = 0;
	if (ch == '[')
	{
		while (matches != 1)
		{
			prog++;
			if (*prog == ']')
				matches++;
			else if (*prog == '[')
				matches--;
		}
	}
	else if (ch == ']')
	{
		while (matches != 1)
		{
			prog--;
			if (*prog == '[')
				matches++;
			else if (*prog == ']')
				matches--;
		}
	}
	return (prog);
}

int	main(int argc, char **argv)
{
	char	*program;
	char	data[SIZE] = {0};
	int		j = 0;

	if (argc == 2)
	{
		program = argv[1];
		while (*program)
		{
			if (*program == '<')
				j--;
			else if (*program == '>')
				j++;
			else if (*program == '+')
				data[j]++;
			else if (*program == '-')
				data[j]--;
			else if (*program == '.')
				write(1, data + j, 1);
			else if (*program == '[' && data[j] == 0)
				program = match('[', program);
			else if (*program == ']' && data[j] != 0)
				program = match(']', program);
			program++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
