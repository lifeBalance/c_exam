#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int		ft_isdigit(char ch);
int		ft_isoperator(char ch);
int		do_op(int a, int b, char op);
int		rpn(char *s);

int	main(int argc, char **argv)
{
	if (argc != 2 || rpn(argv[1]) != 0)
		printf("Error");
	printf("\n");
	return (0);
}

int	ft_isdigit(char ch)
{
	return (ch >= '0' && ch <= '9');
}

int	ft_isoperator(char ch)
{
	return (ch == '+' || ch == '-' || ch == '*' || ch == '\\' || ch == '%');
}

int		do_op(int a, int b, char op)
{
	if (op == '+')
		return (a + b);
	else if (op == '-')
		return (a - b);
	else if (op == '*')
		return (a * b);
	else if (op == '/')
		return (a / b);
	else
		return (a % b);
}

int	rpn(char *s)
{
	t_stack		stack = {{0}, -1};
	int			a;
	int			b;

	while (*s)
	{
		if (ft_isdigit(*s) || (*s == '-' && ft_isdigit(*(s + 1))))
		{
			push(atoi(s), &stack);
			if (*s == '-')
				s++;
			while (*s && ft_isdigit(*s))
				s++;
		}
		else if (ft_isoperator(*s) && (!(*(s + 1)) || *(s + 1) == ' '))
		{
			if (!isempty(&stack))
				a = pop(&stack);
			else
				return (1);
			if (!isempty(&stack))
				b = pop(&stack);
			else
				return (1);
			push(do_op(b, a, *s), &stack);
		}
		s++;
	}
	a = pop(&stack);
	if (isempty(&stack))
	{
		printf("%d", a);
		return (0);
	}
	else
		return (1);
}
