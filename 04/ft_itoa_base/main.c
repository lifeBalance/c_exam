#include <stdio.h>

char	*ft_itoa_base(int value, int base);

int	main()
{
	int	n;

	n = 255;
	printf("%d = %s(base: %d)\n", n, ft_itoa_base(n, 10), 10);
	n = -255;
	printf("%d = %s(base: %d)\n", n, ft_itoa_base(n, 10), 10);
	n = 0;
	printf("%d = %s(base: %d)\n", n, ft_itoa_base(n, 10), 10);
	n = 0;
	printf("%d = %s(base: %d)\n", n, ft_itoa_base(n, 16), 16);
	n = -255;
	printf("%d = %s(base: %d)\n", n, ft_itoa_base(n, 16), 16);
	n = -1001;
	printf("%d = %s(base: %d)\n", n, ft_itoa_base(n, 10), 10);
	return (0);
}
