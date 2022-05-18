#include	<stdlib.h>
#include	"ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*prev;
	t_list	*curr;

	while (*begin_list && cmp(data_ref, (*begin_list)->data) == 0)
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
		while (curr && cmp(data_ref, curr->data) == 0)
		{
			prev->next = curr->next;
			free(curr->data);
			free(curr);
			curr = prev->next;
		}
		prev = prev->next;
		curr = curr->next;
	}
}
