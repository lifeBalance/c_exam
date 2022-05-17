#include <unistd.h>

#define SIZE 40000

typedef struct	s_stack {
	char	data[SIZE];
	int		top;
}				t_stack;

int		is_full(t_stack *st) { return (st->top == SIZE); }

int		is_empty(t_stack *st) { return (st->top == -1); }

char	peek(t_stack *st) { return (st->data[st->top]); }

char	pop(t_stack *st)
{
	char	ret;

	ret = st->data[st->top];
	st->data[st->top] = 0;
	st->top--;
	return (ret);
}

void	push(char ch, t_stack *st)
{
	st->top++;
	st->data[st->top] = ch;
}

int		isopening(char ch)
{
	return (ch == '(' || ch == '[' || ch == '{');
}

int		isclosing(char ch)
{
	return (ch == ')' || ch == ']' || ch == '}');
}

int		match(char opening, char closing)
{
	return ((opening == '(' && closing == ')') ||
			(opening == '[' && closing == ']') ||
			(opening == '{' && closing == '}'));
}

int		brackets(char *s)
{
	t_stack	stack = {{0}, -1};

	while (*s)
	{
		if (isopening(*s) && !is_full(&stack))
			push(*s, &stack);
		else if (isclosing(*s))
		{
			if (match(peek(&stack), *s) && !is_empty(&stack))
				pop(&stack);
			else
				return (0);
		}
		s++;
	}
	return (is_empty(&stack));
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			if (brackets(argv[i]))
				write(1, "OK\n", 3);
			else
				write(1, "Error\n", 6);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
