#include "test_functions.h"
#include <unistd.h>
#include <stdlib.h>

char	**make_area(char **zone, t_point size)
{
	int		i;
	int		j;
	char	**area;

	area = (char **)malloc(sizeof(char *) * (size.y + 1));
	if (!area)
		return (0);
	i = 0;
	while (i < size.y)
	{
		area[i] = (char *)malloc(sizeof(char) * (size.x + 1));
		if (!area[i])
			return (0);
		j = 0;
		while (j < size.x)
		{
			area[i][j] = zone[i][j];
			j++;
		}
		area[i][j] = 0;
		i++;
	}
	area[i] = 0;
	return (area);
}

void	print_tab(char **area)
{
	int	i;
	int	j;

	i = 0;
	while (area[i])
	{
		j = 0;
		while (area[i][j])
		{
			write(1, area[i] + j, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	putc(char ch)
{
	write(1, &ch, 1);
}