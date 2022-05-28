#include <unistd.h>

#define	START	0
#define	END		1

void	expand(char *s, int start, int end, int sol[2])
{
	while (start >= 0 && s[end] && s[start] == s[end])
	{
		if (end - start + 1 >= sol[END] - sol[START] + 1)
		{
			sol[START] = start;
			sol[END] = end;
		}
		start--;
		end++;
	}
}

void	biggest_pal(char *s)
{
	int	i;
	int	sol[2] = {0};

	i = 0;
	while(s[i])
	{
		expand(s, i, i, sol);		//  odd palindrome lengths
		expand(s, i, i + 1, sol);	// even palindrome lengths
		i++;
	}
	write(1, s + sol[START], sol[END] - sol[START] + 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		biggest_pal(argv[1]);
	write(1, "\n", 1);
	return (0);
}
