#include <stdio.h>

char	*ft_itoa(int nbr);

int	main(void)
{
	int	n;

	n = 234;
	printf("%d: %s\n", n, ft_itoa(n));

	n = -234;
	printf("%d: %s\n", n, ft_itoa(n));

	n = 0;
	printf("%d: %s\n", n, ft_itoa(n));

	n = 1001;
	printf("%d: %s\n", n, ft_itoa(n));

	n = -1001;
	printf("%d: %s\n", n, ft_itoa(n));

	n = -123456789;
	printf("%d: %s\n", n, ft_itoa(n));
	return (0);
}
