#include "list.h"	// DO NOT PUSH THIS FILE

int	cycle_detector(const t_list *list)
{
	const t_list	*turtle;
	const t_list	*hare;

	if (!list)
		return (0);
	turtle = list;
	hare = list;
	while (hare && hare->next)
	{
		turtle = turtle->next;
		hare = hare->next->next;
		if (hare == turtle)
			return (1);
	}
	return (0);
}
