#include <stdlib.h>

static int	count_digits_base(int n, int base)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(int value, int base)
{
	char	*s;
	int		len;
	int		cpy;

	len = count_digits_base((value < 0)? -value : value, base);
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
