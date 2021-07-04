#include "push_swap.h"

void	sa(t_stack *a)
{
	printf("sa\n");
	if (a->size < 2)
		return ;
	swap(a);
}

void	sb(t_stack *b)
{
	printf("sb\n");
	if (b->size < 2)
		return ;
	swap(b);
}

void	ss(t_stack *a, t_stack *b)
{
	printf("ss\n");
	swap(a);
	swap(b);
}

void	pa(t_stack *a, t_stack *b)
{
	printf("pa\n");
	if (b->size == 0)
		return ;
	push(a, top(b));
	pop(b);
}

void	pb(t_stack *a, t_stack *b)
{
	printf("pb\n");
	if (a->size == 0)
		return ;
	push(b, top(a));
	pop(a);
}

void	ra(t_stack *a)
{
	printf("ra\n");
	if (a->size < 2)
		return ;
	rotate(a);
}

void	rb(t_stack *b)
{
	printf("rb\n");
	if (b->size < 2)
		return ;
	rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	printf("rr\n");
	rotate(a);
	rotate(b);
}

void	rra(t_stack *a)
{
	printf("rra\n");
	if (a->size < 2)
		return ;
	reverse_rotate(a);
}

void	rrb(t_stack *b)
{
	printf("rrb\n");
	if (b->size < 2)
		return ;
	reverse_rotate(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	printf("rrr\n");
	reverse_rotate(a);
	reverse_rotate(b);
}
