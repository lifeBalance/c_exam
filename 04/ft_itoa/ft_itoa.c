#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	char	*s;
	int		cpy;
	int		len;

	s = 0;
	cpy = (nbr > 0) ? nbr : -nbr;
	len = 1;
	while (cpy / 10)
	{
		cpy /= 10;
		len++;
	}
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