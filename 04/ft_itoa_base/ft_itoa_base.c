#include <stdlib.h>

static int	count_digits_base(unsigned int n, int base)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(int value, int base)
{
	char			*s;
	int				len;
	unsigned int	cpy;

	if (value < 0 && base == 10)
		cpy = -value;
	else
		cpy = (unsigned int)value;
	len = count_digits_base(cpy, base);
	len += (value < 0 && base == 10);
	s = (char *)malloc(len + 1);
	if (!s)
		return (0);
	s[len--] = 0;
	while (len >= (value < 0 && base == 10))
	{
		s[len] = "0123456789ABCDEF"[cpy % base];
		len--;
		cpy /= base;
	}
	if (value < 0 && base == 10)
		s[0] = '-';
	return (s);
}
