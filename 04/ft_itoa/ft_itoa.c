#include <stdlib.h>

static int	count_digits(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char	*s;
	int		cpy;
	int		len;

	s = 0;
	len = count_digits((nbr > 0) ? nbr : -nbr);
	len += (nbr < 0);
	s = (char *)malloc(len + 1);
	if (!s)
		return (0);
	s[len] = 0;
	len--;
	if (nbr < 0)
	{
		s[0] = '-';
		cpy = -nbr;
	}
	else
		cpy = nbr;
	while(len >= (nbr < 0))
	{
		s[len] = (cpy % 10) + '0';
		len--;
		cpy /= 10;
	}
	return (s);
}
