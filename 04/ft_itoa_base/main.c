#include <stdio.h>

char	*ft_itoa_base(int value, int base);

int	main()
{
	int	n;
	int	base;

	n = 255, base = 10;
	printf("%d = %s(base: %d)\n", n, ft_itoa_base(n, base), base);
	n = -255, base = 10;
	printf("%d = %s(base: %d)\n", n, ft_itoa_base(n, base), base);
	n = 0, base = 10;
	printf("%d = %s(base: %d)\n", n, ft_itoa_base(n, base), base);
	n = 0, base = 16;
	printf("%d = %s(base: %d)\n", n, ft_itoa_base(n, base), base);
	n = -255, base = 16;
	printf("%d = %s(base: %d)\n", n, ft_itoa_base(n, base), base);
	n = 15, base = 16;
	printf("%d = %s(base: %d)\n", n, ft_itoa_base(n, base), base);
	n = -1001, base = 10;
	printf("%d = %s(base: %d)\n", n, ft_itoa_base(n, base), base);
	return (0);
}
