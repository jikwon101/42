#include "stack.h"

void	sa(t_stack *a, t_stack *b)
{
	int	temp;

	if (empty(a))
	{
		return ;
	}
	temp = top(a);
	pop(a);
	if (empty(a))
	{
		push(a, temp);
		return ;
	}
	push(b, top(a));
	push(a, temp);
	push(a, top(b));
	pop(b);
	// 	수정 필요
	// 	스택에 사이즈 변수 추가
}

void	sb(t_stack *a, t_stack *b)
{
}

void	ss(t_stack *a, t_stack *b)
{
}

void	pa(t_stack *a, t_stack *b)
{
}

void	pb(t_stack *a, t_stack *b)
{
}

void	ra(t_stack *a, t_stack *b)
{
}

void	rb(t_stack *a, t_stack *b)
{
}

void	rr(t_stack *a, t_stack *b)
{
}

void	rra(t_stack *a, t_stack *b)
{
}

void	rrb(t_stack *a, t_stack *b)
{
}

void	rrr(t_stack *a, t_stack *b)
{
}
