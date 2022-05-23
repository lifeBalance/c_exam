#include <stdlib.h>

static int	count_digits(unsigned int n)
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
	char			*s;
	unsigned int	cpy;
	int				len;

	cpy = (nbr < 0) ? (unsigned int) -nbr : (unsigned int) nbr;
	len = count_digits(cpy);
	len += (nbr < 0);
	s = (char *)malloc(len + 1);
	if (!s)
		return (0);
	s[len--] = 0;
	while(len >= (nbr < 0))
	{
		s[len] = (cpy % 10) + '0';
		len--;
		cpy /= 10;
	}
	if (nbr < 0)
		s[0] = '-';
	return (s);
}
