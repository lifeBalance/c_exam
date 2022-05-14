#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*prev;
	t_list	*curr;

	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		curr = (*begin_list)->next;
		free((*begin_list)->data);
		free(*begin_list);
		*begin_list = curr;
	}
	prev = *begin_list;
	curr = (*begin_list)->next;
	while (curr)
	{
		if (cmp(curr->data, data_ref) == 0)
		{
			prev->next = curr->next;
			free(curr->data);
			free(curr);
		}
		prev = prev->next;
		curr = curr->next;
	}
}
