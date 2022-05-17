#include <unistd.h>

#define SIZE 40000

void	pop(int *top, char stack[SIZE])
{
	stack[*top] = 0;
	if (*top > 0)
		(*top)--;
}

void	push(char ch, int *top, char stack[SIZE])
{
	(*top)++;
	stack[*top] = ch;
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
	char	stack[SIZE];
	int		top;

	top = 0;
	while (*s)
	{
		if (isopening(*s))
			push(*s, &top, stack);
		else if (isclosing(*s))
		{
			if (match(stack[top], *s))
				pop(&top, stack);
			else
				return (0);
		}
		s++;
	}
	return (top == 0);
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
