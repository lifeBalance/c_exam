#ifndef	STACK_H
#define	STACK_H

#define		SIZE 4096

typedef struct	s_stack {
	int		data[SIZE];
	int		top;
}				t_stack;

int		isempty(t_stack *st);
int		isfull(t_stack *st);
void	push(int n, t_stack *st);
int		pop(t_stack *st);
int		peek(t_stack *st);

#endif
