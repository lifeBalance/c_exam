static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
** Bubble sort
*/
void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	j;

	while (size > 0)	// loop exits when size == 0.
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
				swap(tab + j, tab + j + 1);
			j++;
		}
		size--;			// we decrease the size by one on each iteration.
	}
}
