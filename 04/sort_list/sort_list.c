#include "list.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next)
	{
		if (cmp(tmp->data, tmp->next->data) == 0)
		{
			swap(&(tmp->data), &(tmp->next->data));
			tmp = lst;
		}
		else
			tmp = tmp->next;
	}
	return (lst);
}
