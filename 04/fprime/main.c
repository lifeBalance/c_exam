#include <stdio.h>
#include <stdlib.h>

int	isprime(int n)
{
	int	div;

	div = 2;
	while (div <= n / 2)
	{
		if (n % div == 0)
			return (0);
		div++;
	}
	return (1);
}

void	fprime(int n)
{
	int	div;

	if (isprime(n))
	{
		printf("%d", n);
		return ;
	}
	div = 2;
	while (n > 1)
	{
		while (n > 1 && isprime(div) && n % div == 0)
		{
			printf("%d", div);
			n /= div;
			if (n > 1)
				printf("*");
		}
		div++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		fprime(atoi(argv[1]));
	printf("\n");
	return (0);
}