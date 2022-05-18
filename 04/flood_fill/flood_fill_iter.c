#include "t_point.h"
#include "flood_fill.h"

/*
**	Iterative version
*/
static void	fill_row(char **tab, t_point begin)
{
	int	j;

	j = begin.x;
	while (tab[begin.y][j])
	{
		if (tab[begin.y][j] != '1')
			tab[begin.y][j] = 'F';
		else
			break ;
		j++;
	}
	j = begin.x;
	while (j >= 0)
	{
		if (tab[begin.y][j] != '1')
			tab[begin.y][j] = 'F';
		else
			break ;
		j--;
	}
}

static void	fill_col(char **tab, t_point begin)
{
	int	i;

	i = begin.y;
	while (tab[i])
	{
		if (tab[i][begin.x] != '1')
			tab[i][begin.x] = 'F';
		else
			break ;
		i++;
	}
	i = begin.y;
	while (i >= 0)
	{
		if (tab[i][begin.x] != '1')
			tab[i][begin.x] = 'F';
		else
			break ;
		i--;
	}
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	int		i;
	int		j;
	t_point	point;

	fill_row(tab, begin);
	fill_col(tab, begin);
	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			point.y = i;
			point.x = j;
			if (tab[i][j] == 'F')
			{
				fill_col(tab, point);
				fill_row(tab, point);
			}
			j++;
		}
		i++;
	}
}
