#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
t_list	*ft_list_new(void *data, int size);
t_list	*ft_list_append(t_list *lst, t_list *new);
void	ft_print_list(t_list *lst);
void	ft_toupper(void *data);

int	main(void)
{
	t_list	*lst;

	lst = 0;
	lst = ft_list_append(lst, ft_list_new("hey", 4));
	lst = ft_list_append(lst, ft_list_new("ho", 3));
	lst = ft_list_append(lst, ft_list_new("let's go!", 10));

	ft_print_list(lst);
	ft_list_foreach(lst, ft_toupper);
	ft_print_list(lst);
	return (0);
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
	{
		lst = node;
		return (lst);
	}
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (lst);
}

void	ft_print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", (char*)(lst->data));
		lst = lst->next;
	}
}

/*
** This is the function we'll pass as argument in our
**	call to ft_list_foreach.
*/
void	ft_toupper(void *data)
{
	char	*s;

	s = (char *)data;
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s = *s - 'a' + 'A';
		s++;
	}
}