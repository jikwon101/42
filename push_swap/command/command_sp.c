#include "command.h"

void	sa(t_stack *a)
{
	control_log(ADD, "sa");
	if (a->size < 2)
		return ;
	swap(a);
}

void	sb(t_stack *b)
{
	control_log(ADD, "sb");
	if (b->size < 2)
		return ;
	swap(b);
}

void	ss(t_stack *a, t_stack *b)
{
	control_log(ADD, "ss");
	swap(a);
	swap(b);
}

void	pa(t_stack *a, t_stack *b)
{
	control_log(ADD, "pa");
	if (b->size == 0)
		return ;
	push(a, top(b));
	pop(b);
}

void	pb(t_stack *a, t_stack *b)
{
	control_log(ADD, "pb");
	if (a->size == 0)
		return ;
	push(b, top(a));
	pop(a);
}
