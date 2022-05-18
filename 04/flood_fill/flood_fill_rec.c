#include "t_point.h"
#include "flood_fill.h"

/*
**	Recursive version
*/
void	fill(char **tab, t_point size, t_point begin, char target)
{
	if (begin.y < 0 || begin.y >= size.y ||
		begin.x < 0 || begin.x >= size.x ||
		tab[begin.y][begin.x] != target)
		return;

	tab[begin.y][begin.x] = 'F';
	fill(tab, size, (t_point){begin.x - 1, begin.y}, target);
	fill(tab, size, (t_point){begin.x + 1, begin.y}, target);
	fill(tab, size, (t_point){begin.x, begin.y - 1}, target);
	fill(tab, size, (t_point){begin.x, begin.y + 1}, target);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}