#include "sort.h"

void	a_divide(t_stack *a, t_stack *b, int lsize)
{	
	int	pivot;
	int	i;
	int	cnt;
	int	time;

	i = 0;
	time = 0;
	cnt = lsize;
	if (a->size == lsize)
		time = 0 - lsize - 1;
	pivot = find_pivot(a, lsize);
	while (i < cnt && !all_bigger_than(a, cnt - i, pivot))
	{
		if (top(a) < pivot)
			pb(a, b);
		else
		{
			ra(a);
			time++;
		}
		i++;
	}
	i = 0;
	while (i++ < time)
		rra(a);
}

void	a_sort_three_sp(t_stack *a)
{
	int	md;

	md = find_pivot(a, 3);
	if ((top(a) < md && next(a) > md)
		|| (top(a) == md && next(a) < md)
		|| (top(a) > md && next(a) == md))
		sa(a);
	if (is_ordered(a, ASC, 3))
		return ;
	if (top(a) == md)
		rra(a);
	else
		ra(a);
	return ;
}

void	a_sort_three(t_stack *a)
{
	int	md;

	if (a->size == 3)
		return (a_sort_three_sp(a));
	md = find_pivot(a, 3);
	if ((top(a) < md && next(a) > md)
		|| (top(a) == md && next(a) < md)
		|| (top(a) > md && next(a) == md))
		sa(a);
	if (is_ordered(a, ASC, 3))
		return ;
	if (top(a) == md)
	{
		ra(a);
		sa(a);
		rra(a);
		sa(a);
	}
	else
	{
		sa(a);
		ra(a);
		sa(a);
		rra(a);
	}
}

void	a_sort(t_stack *a, t_stack *b, int lsize)
{
	int	res;
	int	asize;
	int	type;

	type = ASC;
	res = a_arranged_type(a, lsize);
	if (res != 0)
		return (a_sort_sp(a, res));
	asize = a->size;
	divide(a, b, type, lsize);
	a_sort(a, b, lsize - (asize - a->size));
	d_sort(a, b, asize - a->size);
	merge(a, b, type, asize - a->size);
}
