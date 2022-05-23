#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int	cycle_detector(const t_list *list);

int main(void)
{
	t_list *node1;
	t_list *node2;
	t_list *node3;
	t_list *node4;

	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));
	node3 = malloc(sizeof(t_list));
	node4 = malloc(sizeof(t_list));

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node2;

	printf("%d\n", cycle_detector(node1));
}
