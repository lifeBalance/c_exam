#include "list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));
t_list	*ft_list_new(int data);
t_list	*ft_list_append(t_list *lst, t_list *node);
void	print_list(t_list *lst);
int descending(int a, int b) { return (a >= b); }
int ascending(int a, int b) { return (a <= b); }

int	main(void)
{
	t_list	*lst;

	lst = 0;
	lst = ft_list_append(lst, ft_list_new(3));
	lst = ft_list_append(lst, ft_list_new(1));
	lst = ft_list_append(lst, ft_list_new(2));
	lst = ft_list_append(lst, ft_list_new(5));
	print_list(lst);
	sort_list(lst, descending);
	printf("\n");
	print_list(lst);
	return (0);
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d\n", lst->data);
		lst = lst->next;
	}
}

t_list	*ft_list_new(int data)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return (0);
	new->data = data;
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
