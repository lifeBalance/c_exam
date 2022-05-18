#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ft_list.h"

void	ft_print_list(t_list *lst);
t_list	*ft_list_new(void *data, int size);
t_list	*ft_list_append(t_list *lst, t_list *node);
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

int	main(void)
{
	t_list	*lst;

	lst = 0;
	lst = ft_list_append(lst, ft_list_new("hey", 4));
	lst = ft_list_append(lst, ft_list_new("hey", 4));
	lst = ft_list_append(lst, ft_list_new("ho", 3));
	lst = ft_list_append(lst, ft_list_new("ho", 3));
	lst = ft_list_append(lst, ft_list_new("let's go!", 10));
	lst = ft_list_append(lst, ft_list_new("let's go!", 10));
	lst = ft_list_append(lst, ft_list_new("last", 5));
	ft_print_list(lst);
	ft_list_remove_if(&lst, "ho", strcmp);
	printf("\n");
	ft_print_list(lst);
	return (0);
}

void	ft_print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", lst->data);
		lst = lst->next;
	}
}

t_list	*ft_list_new(void *data, int size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return (0);
	new->data = malloc(size);
	if (!new->data)
	{
		free(new);
		return (0);
	}
	memcpy(new->data, data, size);
	new->next = 0;
	return (new);
}

t_list	*ft_list_append(t_list *lst, t_list *node)
{
	t_list	*tmp;

	if (!lst)
		lst = node;
	else
	{
		tmp = lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	return (lst);
}
