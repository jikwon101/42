#include "push_swap.h"

void	printcmd(char *s)
{
	control_log(ADD, s);
	//printf("%s\n", s); //temp
	return ;
	printf(RED "%s", s);
	printf(RESET);
}
void	sa(t_stack *a)
{
	printcmd("sa");
	if (a->size < 2)
		return ;
	swap(a);
}

void	sb(t_stack *b)
{
	printcmd("sb");
	if (b->size < 2)
		return ;
	swap(b);
}

void	ss(t_stack *a, t_stack *b)
{
	printcmd("ss");
	swap(a);
	swap(b);
}

void	pa(t_stack *a, t_stack *b)
{
	printcmd("pa");
	if (b->size == 0)
		return ;
	push(a, top(b));
	pop(b);
}

void	pb(t_stack *a, t_stack *b)
{
	printcmd("pb");
	if (a->size == 0)
		return ;
	push(b, top(a));
	pop(a);
}

void	ra(t_stack *a)
{
	printcmd("ra");
	if (a->size < 2)
		return ;
	rotate(a);
}

void	rb(t_stack *b)
{
	printcmd("rb");
	if (b->size < 2)
		return ;
	rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	printcmd("rr");
	rotate(a);
	rotate(b);
}

void	rra(t_stack *a)
{
	printcmd("rra");
	if (a->size < 2)
		return ;
	reverse_rotate(a);
}

void	rrb(t_stack *b)
{
	printcmd("rrb");
	if (b->size < 2)
		return ;
	reverse_rotate(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	printcmd("rrr");
	reverse_rotate(a);
	reverse_rotate(b);
}
