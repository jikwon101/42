#include "sort.h"

void	d_divide(t_stack *a, t_stack *b, int lsize)
{		
	int	pivot;
	int	i;
	int	cnt;
	int	time;

	i = 0;
	time = 0;
	cnt = lsize;
	if (b->size == lsize)
		time = 0 - lsize - 1;
	pivot = find_pivot(b, lsize);
	while (i < cnt && !all_smaller_than(b, cnt - i, pivot))
	{
		if (top(b) > pivot)
			pa(a, b);
		else
		{
			rb(b);
			time++;
		}
		i++;
	}
	i = 0;
	while (i++ < time)
		rrb(b);
}

void	d_sort_three_sp(t_stack *b)
{
	int	md;

	md = find_pivot(b, 3);
	if ((top(b) < md && next(b) == md)
		|| (top(b) == md && next(b) > md)
		|| (top(b) > md && next(b) < md))
		sb(b);
	if (is_ordered(b, DESC, 3))
		return ;
	if (top(b) == md)
		rrb(b);
	else
		rb(b);
}

void	d_sort_three(t_stack *b)
{
	int	md;

	if (b->size == 3)
		return (d_sort_three_sp(b));
	md = find_pivot(b, 3);
	if ((top(b) < md && next(b) == md)
		|| (top(b) == md && next(b) > md)
		|| (top(b) > md && next(b) < md))
		sb(b);
	if (is_ordered(b, DESC, 3))
		return ;
	if (top(b) == md)
	{
		rb(b);
		sb(b);
		rrb(b);
		sb(b);
	}
	else
	{
		sb(b);
		rb(b);
		sb(b);
		rrb(b);
	}
}

void	d_sort(t_stack *a, t_stack *b, int lsize)
{	
	int	bsize;
	int	type;
	int	res;

	type = DESC;
	res = d_arranged_type(b, lsize);
	if (res != 0)
		return (d_sort_sp(b, res));
	bsize = b->size;
	divide(a, b, type, lsize);
	a_sort(a, b, bsize - b->size);
	d_sort(a, b, lsize - (bsize - b->size));
	merge(a, b, type, bsize - b->size);
}
