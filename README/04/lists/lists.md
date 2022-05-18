# Functions to test linked lists exercises
The next three functions must be almost second nature for someone claiming to understand **linked lists**. Producing them should take almost no mental effort, and a typing time of around 10-15 minutes. They go in your `main.c`.

## Creating Nodes
Creating nodes by hand it's not practical. The following function does that for us:
```c
t_list	*ft_lst_new(void *data, int size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return (0);
	new->data = malloc(size);
	if (!data)
	{
		free(new);
		return (0);
	}
	memcpy(new->data, data, size);
	new->next = 0;
	return (new);
}
```

## Appending Nodes
We also need a function to append new nodes to a list:
```c
t_list	*ft_lst_append(t_list *lst, t_list *node)
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
```

## Print a list
We should have a small function to traverse the list, printing the data on our way:
```c
void	ft_print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", (char*)lst->data);
		lst = lst->next;
	}
}
```

Don't worry about leaving the list pointing at the end; the `lst` argument is just a **copy** of the value of the address that points to the list's head.

## Putting it together
Both functions above can be used together in a **quick and dirty** way to create a linked list, which we can use to test if the exercises work or not:
```c
int	main(void)
{
	t_list	*lst = 0;

	lst = ft_lst_append(lst, ft_lst_new("hey", 4));
	lst = ft_lst_append(lst, ft_lst_new("ho", 3));
	lst = ft_lst_append(lst, ft_lst_new("let's go!", 10));

	ft_print_lst(lst);  // print the nodes

	// do your thing here!

	ft_print_list(lst);  // print the nodes again, to see if it worked.

	return (0);
}
```

---
[:arrow_backward:][back] ║ [:house:][home] ║ [:arrow_forward:][next]

<!-- navigation -->
[home]: ../../../README.md
[back]: ../index.md
[next]: ./ft_list_foreach.md