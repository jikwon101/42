#include <stdio.h>
#include "libft.h"
#include "push_swap.h"
#include "quickpivot.h"
#include "log.h"
#define RED "\x1b[31m"
#define BLUE "\x1b[36m"
#define RESET "\x1b[0m"

# define ASC 1
# define DESC -1

void	r_sort(t_stack *a, t_stack *b, int lsize);
void	o_sort(t_stack *a, t_stack *b, int lsize);
int	check_arguments(int size, char *argv[])
{	
	// av[] is not int
	// av[] is bigger than an int
	// av[] is duplicate.
	(void)size;
	(void)argv;
	return (1);
}

void	init_stack(int ac, char *av[], t_stack *a, t_stack *b)
{
	init(a);
	init(b);
	while (ac > 1)
	{
		push(a, ft_atoi(av[ac - 1]));
		ac--;
	}
}


int	n_ordered(t_stack *st, int size)
{
	t_node	*pos;

	pos = st->head;
	while (size - 1 > 0)
	{
		if (pos->data > pos->next->data)
			return (0);
		pos = pos->next;
		size--;
	}
	return (1);
}

int	n_reverse_ordered(t_stack *st, int size)
{
	t_node	*pos;

	pos = st->head;
	while (size - 1 > 0)
	{
		if (pos->data < pos->next->data)
			return (0);
		pos = pos->next;
		size--;
	}
	return (1);
}

int		n_is_ordered(t_stack *st, int type, int size)
{
	if (type == ASC)
		return (n_ordered(st, size));
	return (n_reverse_ordered(st, size));
}

int		all_bigger_than(t_stack *a, int cnt , int pivot)
{
	int	i;
	t_node	*pos;

	i = 0;
	pos = a->head;
	while (i < cnt)
	{
		if (pos->data < pivot)
			return (0);
		i++;
		pos = pos->next;
	}
	return (1);
}
int	all_smaller_than(t_stack *a, int cnt, int pivot)
{
	int	i;
	t_node *pos;

	i = 0;
	pos = a->head;
	while (i < cnt)
	{
		if (pos->data > pivot)
			return (0);
		i++;
		pos = pos->next;
	}
	return (1);
}
void	n_divide(t_stack *a, t_stack *b, int type, int lsize)
{
	int	pivot;
	int	i;
	int	cnt;
	int	time;

	i = 0;
	time = 0;
	cnt = lsize;
	if (type == ASC)
	{
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
		for (int i = 0 ; i < time ; i++)
			rra(a);
	}
	else
	{
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
		for (int i = 0 ; i < time ; i++)
			rrb(b);
	}
}

void	n_merge(t_stack *a, t_stack *b, int type, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (type == ASC)
			pa(a, b);
		else
			pb(a, b);
		i++;
	}
}

void	special_o_sort(t_stack *a)
{
	int	md;

	md = find_pivot(a, 3);
	if ((top(a) < md && next(a) > md)
		|| (top(a) == md && next(a) < md)
		|| (top(a) > md && next(a) == md))
		sa(a);
	if (n_is_ordered(a, ASC, 3))
		return ;
	if (a->size == 3)
	{
		if (top(a) == md)
			rra(a);
		else
			ra(a);
		return ;
	}
	else
	{
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
}

void	special_r_sort(t_stack *b)
{
	int	md;

	md = find_pivot(b, 3);
	if ((top(b) < md && next(b) == md)
		|| (top(b) == md && next(b) > md)
		|| (top(b) > md && next(b) < md))
		sb(b);
	if (n_is_ordered(b,DESC, 3))
		return ;
	if (b->size == 3)
	{
		if (top(b) == md)
			rrb(b);
		else
			rb(b);
		return  ;
	}
	else
	{
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
}
int	r_ordertype(t_stack *b)
{
	int	i;
	t_node	*pos;
	
	i = 0;
	pos = b->head;
	while (i < 2)
	{
		if (pos->data < pos->next->data)
			return (0);
		pos = pos->next;
		i++;
	}
	if (b->head->data < pos->next->data)
		return (1);
	return (0);
}


void	r_sort(t_stack *a, t_stack *b, int lsize)
{	
	int	bsize;
	int	type;

	type = DESC;
	if (lsize == 1 || n_is_ordered(b, type, lsize))
		return ;
	else if (lsize == 2 && !n_is_ordered(b, type, lsize))
	{
		sb(b);
		return ;
	}
	else if (lsize == 3) //else if (b->size == 3)
	{
		special_r_sort(b);
		return ;
	}
	else if (lsize == 4 && lsize == b->size && r_ordertype(b))
	{
		rrb(b);
		return ;
	}
	bsize = b->size;
	n_divide(a, b, type, lsize);
	o_sort(a, b, bsize - b->size);
	r_sort(a, b, lsize - (bsize - b->size));
	n_merge(a, b, type, bsize - b->size);
}

int	o_ordertype(t_stack *a)
{
	int	i;
	t_node	*pos;
	
	i = 0;
	pos = a->head;
	while (i < 2)
	{
		if (pos->data > pos->next->data)
			return (0);
		pos = pos->next;
		i++;
	}
	if (a->head->data > pos->next->data)
		return (1);
	return (0);
}
void	o_sort(t_stack *a, t_stack *b, int lsize)
{
	int	asize;
	int	type;

	type = ASC;
	if (lsize == 1 || n_is_ordered(a, type, lsize))
		return ;
	else if (lsize == 2 && !n_is_ordered(a, type, lsize))
	{
		sa(a);
		return ;
	}	
	else if (lsize == 3) //else if (a->size == 3)
	{
		special_o_sort(a);
		return ;
	}
	else if (lsize == 4 && lsize == a->size && o_ordertype(a))
	{
		rra(a);
		return ;
	}
	asize = a->size;
	n_divide(a, b, type, lsize);
	o_sort(a, b, lsize - (asize - a->size));
	r_sort(a, b, asize - a->size);
	n_merge(a, b, type, asize - a->size);
}

int main(int ac, char *av[])
{
	t_stack	a;
	t_stack	b;

	if (ac < 2 || !(check_arguments(ac, av)))
	{
		printf("Error\n"); //stdderr ***
		return (1);
	}
	init_stack(ac, av, &a, &b);
	control_log(INIT, NOCMD);
	o_sort(&a, &b, a.size);
	clear(&a);
	clear(&b);
	control_log(PRINT, NOCMD);
	control_log(CLEAR, NOCMD);
}
