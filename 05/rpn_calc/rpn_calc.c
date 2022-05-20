#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int		ft_isdigit(char ch);
int		ft_isoperator(char ch);
int		do_op(int a, int b, int *c, char op);
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
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
}

int		do_op(int a, int b, int *c, char op)
{
	if (op == '+')
		*c = a + b;
	else if (op == '-')
		*c = a - b;
	else if (op == '*')
		*c = a * b;
	else if ((op == '/' || op == '%') && b == 0)
		return (1);
	else if (op == '/')
		*c = a / b;
	else if (op == '%')
		*c = a % b;
	return (0);
}

int	rpn(char *s)
{
	t_stack		stack = {{0}, -1};
	int			a;
	int			b;
	int			c;

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
				b = pop(&stack);
			else
				return (1);
			if (!isempty(&stack))
				a = pop(&stack);
			else
				return (1);
			if (do_op(a, b, &c, *s) != 0)
				return (1);
			push(c, &stack);
		}
		s++;
	}
	c = pop(&stack);
	if (isempty(&stack))
	{
		printf("%d", c);
		return (0);
	}
	else
		return (1);
}
