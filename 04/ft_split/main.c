#include <stdio.h>

char	**ft_split(char *str);

int	main(int argc, char **argv)
{
	char	**arr;
	int		i;

	if (argc == 2)
	{
		arr = ft_split(argv[1]);
		i = 0;
		while (arr[i])
		{
			printf("%s\n", arr[i]);
			i++;
		}
	}
	return (0);
}
