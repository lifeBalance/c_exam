#include <unistd.h>

#define	LEFT	0
#define	RIGHT	1

void	biggest_pal(char *s, int sol[2]);
int		ft_strlen(char *s);

int	main(int argc, char **argv)
{
	int		solution[2] = {0};

	if (argc == 2)
		biggest_pal(argv[1], solution);
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

void		biggest_pal(char *s, int sol[2])
{
	int	len = ft_strlen(s);
	int	dp[len][len];
	int	i;
	int	k;

	init_dp(len, dp);
	k = 0;
	while (k < len)
	{
		i = 0;
		while (k + i < len)
		{
			if (k == 0)
				dp[i][i] = 1;
			else if (k == 1 && s[i] == s[k + i])
				dp[i][k + i] = 1;
			else if (k >= 2 && s[i] == s[k + i] && dp[i + 1][(k + i) - 1])
			{
				dp[i][k + i] = 1;
				if ((k + i) - i + 1 >= sol[RIGHT] - sol[LEFT] + 1)
				{
					sol[LEFT] = i;
					sol[RIGHT] = k + i;
				}
			}
			i++;
		}
		k++;
		// print_dp(len, dp);
	}
	if (sol[RIGHT] - sol[LEFT] + 1)
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
