#include "stack.h"

int		isfull(t_stack *st)
{
	return (st->top >= SIZE);
}

int		isempty(t_stack *st)
{
	return (st->top == -1);
}

int		peek(t_stack *st)
{
	return (st->data[st->top]);
}

void	push(int n, t_stack *st)
{
	st->top++;
	st->data[st->top] = n;
}

int		pop(t_stack *st)
{
	int	ret;

	ret = st->data[st->top];
	st->data[st->top] = 0;
	st->top--;
	return (ret);
}