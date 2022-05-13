static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
** Stupid sort
*/
void		sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i + 1 < size)
	{
		if (tab[i] > tab[i + 1])
		{
			swap(tab + i, tab + i + 1);
			i = 0;
		}
		i++;
	}
}
