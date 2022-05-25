#include <unistd.h>

#define START	0
#define END		1

int	ft_strlen(char *s)
{
	int len;

	len = 0;
	if (s)
		while (s[len])
			len++;
	return (len);
}

void	expand(char *s, int start, int end, int len, int solution[2])
{
	while (start >= 0 && end < len && s[start] == s[end])
	{
		if (end - start + 1 >= solution[END] - solution[START] + 1)
		{
			solution[START] = start;
			solution[END] = end;
		}
		start--;
		end++;
	}
}

void biggest_pal(char *s)
{
	int i;
	int len;
	int	solution[2] = {0};

	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{ 
		expand(s, i, i, len, solution);		//  odd palindrome lengths
		expand(s, i, i + 1, len, solution);	// even palindrome lengths
		i++;
	}
	write(1, s + solution[START], solution[END] - solution[START] + 1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		biggest_pal(argv[1]);
	write(1, "\n", 1);
	return (0);
}
