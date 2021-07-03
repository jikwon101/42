#include "stack.h"

void	sa(t_stack *a, t_stack *b)
{
	int	temp;

	//printf("sa\n");
	if (a->size < 2)
		return ;
	push(b, top(a));
	pop(a);
	temp = top(a);
	pop(a);
	push(a, top(b));
	pop(b);
	push(a, temp);
}

void	sb(t_stack *a, t_stack *b)
{
	int	temp;

	//printf("sb\n");
	if (b->size < 2)
		return ;
	push(a, top(b));
	pop(b);
	temp = top(b);
	pop(b);
	push(b, top(a));
	pop(a);
	push(b, temp);
}

void	ss(t_stack *a, t_stack *b)
{
	//printf("ss\n");
	sa(a, b);
	sb(a, b);
}

void	pa(t_stack *a, t_stack *b)
{
	//printf("pa\n");
	if (b->size == 0)
		return ;
	push(a, top(b));
	pop(b);
}

void	pb(t_stack *a, t_stack *b)
{
	//printf("pb\n");
	if (a->size == 0)
		return ;
	push(b, top(a));
	pop(a);
}

void	ra(t_stack *a, t_stack *b)
{
	int	temp;
	int	cnt;

	//printf("ra\n");
	if (a->size < 2)
		return ;
	cnt = a->size - 1;
	temp = top(a);
	pop(a);
	while (a->size)
	{
		push(b, top(a));
		pop(a);
	}
	push(a, temp);
	while (cnt)
	{
		push(a, top(b));
		pop(b);
		cnt--;
	}
}

void	rb(t_stack *a, t_stack *b)
{
	int	temp;
	int	cnt;

	//printf("rb\n");
	if (b->size < 2)
		return ;
	cnt = b->size - 1;
	temp = top(b);
	pop(b);
	while (b->size)
	{
		push(a, top(b));
		pop(b);
	}
	push(b, temp);
	while (cnt)
	{
		push(b, top(a));
		pop(a);
		cnt--;
	}
}

void	rr(t_stack *a, t_stack *b)
{
	//printf("rr\n");
	ra(a, b);
	rb(a, b);
}

void	rra(t_stack *a, t_stack *b)
{
	int	temp;
	int	cnt;

	//printf("rra\n");
	if (a->size < 2)
		return ;
	cnt = a->size - 1;
	while (a->size != 1)
	{
		push(b, top(a));
		pop(a);
	}
	temp = top(a);
	pop(a);
	while(cnt)
	{
		push(a, top(b));
		pop(b);
		cnt--;
	}
	push(a, temp);
}

void	rrb(t_stack *a, t_stack *b)
{
	int	temp;
	int	cnt;

	//printf("rrb\n");
	if (b->size < 2)
		return ;
	cnt = b->size - 1;
	while (b->size != 1)
	{
		push(a, top(b));
		pop(b);
	}
	temp = top(b);
	pop(b);
	while(cnt)
	{
		push(b, top(a));
		pop(a);
		cnt--;
	}
	push(b, temp);

}

void	rrr(t_stack *a, t_stack *b)
{
	//printf("rrr\n");
	rra(a, b);
	rrb(a, b);
}
