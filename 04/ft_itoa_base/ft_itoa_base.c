#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	char	*s;
	int		len;
	int		cpy;

	len = 1;
	cpy = (value < 0)? -value : value;
	while (cpy / base)
	{
		cpy /= base;
		len++;
	}
	len += (value < 0 && base == 10);
	s = (char *)malloc(len + 1);
	if (!s)
		return (0);
	s[len] = 0;
	len--;
	if (value < 0 && base == 10)
	{
		s[0] = '-';
		cpy = -value;
	}
	else if (value < 0)
		cpy = -value;
	else
		cpy = value;
	while (len >= (value < 0 && base == 10))
	{
		s[len] = "0123456789abcdef"[cpy % base];
		len--;
		cpy /= base;
	}
	return (s);
}
