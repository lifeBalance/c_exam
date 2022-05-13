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
void		sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i + 1 < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
				swap(tab + j, tab + j + 1);
			j++;
		}
		i++;
	}
}
