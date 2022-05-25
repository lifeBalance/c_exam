#include <unistd.h>

#define	LEFT	0
#define	RIGHT	1

void	biggest_pal(char *s, int len);
int		ft_strlen(char *s);

int	main(int argc, char **argv)
{
	if (argc == 2)
		biggest_pal(argv[1], ft_strlen(argv[1]));
	write(1, "\n", 1);
	return (0);
}

void	print_dp(int len, int dp[len][len])
{
	int		i;
	int		j;
	char	ch;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			ch = dp[i][j] + '0';
			write(1, &ch, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	init_dp(int len, int dp[len][len])
{
	int		i;
	int		j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
			dp[i][j++] = 0;
		i++;
	}
}

void		biggest_pal(char *s, int len)
{
	int	dp[len][len];
	int	sol[2] = {0};
	int	i;
	int	j;

	init_dp(len, dp);
	j = 0;
	while (j < len)
	{
		i = 0;
		while (i < len - j)
		{
			if (s[i] == s[j] && (dp[i + 1][j - 1] || j - i <= 2))
			{
				dp[i][j] = 1;
				if (j - i + 1 >= sol[RIGHT] - sol[LEFT] + 1)
				{
					sol[LEFT] = i;
					sol[RIGHT] = j;
				}
			}
			i++;
		}
		j++;
		// print_dp(len, dp);
	}
	write (1, s + sol[LEFT], sol[RIGHT] - sol[LEFT] + 1);
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
