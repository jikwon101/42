#include "command.h"

void	ra(t_stack *a)
{
	control_log(ADD, "ra");
	if (a->size < 2)
		return ;
	rotate(a);
}

void	rb(t_stack *b)
{
	control_log(ADD, "rb");
	if (b->size < 2)
		return ;
	rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	control_log(ADD, "rr");
	rotate(a);
	rotate(b);
}
