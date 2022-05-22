#include <unistd.h>

#define	LEFT	0
#define	RIGHT	1

void	biggest_pal(char *s);
int		is_palindrome(char *s,  int i, int j);
int		ft_strlen(char *s);

int	main(int argc, char **argv)
{
	if (argc == 2)
		biggest_pal(argv[1]);
	write(1, "\n", 1);
	return (0);
}

void		biggest_pal(char *s)
{
	int	i;
	int	j;
	int	solution[2] = {0};
	int	len = ft_strlen(s);
	int	max_len = 0;

	if (len == 1)
	{
		write(1, s, 1);
		return ;
	}
	i = 0;
	while (i < len)
	{
		j = i;
		while (j < len)
		{
			if (is_palindrome(s, i, j) && j - i + 1 >= max_len)
			{
				max_len = j - i + 1;
				solution[LEFT] = i;
				solution[RIGHT] = j;
			}
			j++;
		}
		i++;
	}
	if (max_len > 0)
		write(1, s + solution[LEFT], solution[RIGHT] - solution[LEFT] + 1);
}

int		is_palindrome(char *s, int i, int j)
{
	while (i < j)
	{
		if (s[i] != s[j])
			return (0);
		i++;
		j--;
	}
	return (1);
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
