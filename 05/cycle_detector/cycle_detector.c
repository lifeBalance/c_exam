#include "list.h"	// DO NOT PUSH THIS FILE

int	cycle_detector(const t_list *list)
{
	const t_list	*slow;
	const t_list	*fast;

	if (!list)
		return (0);
	slow = list;
	fast = list;
	while (fast && fast->next)	// while (fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
			return (1);
	}
	return (0);
}
