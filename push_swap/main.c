#include "push_swap.h"

#define RED "\x1b[31m"
#define BLUE "\x1b[36m"
#define RESET "\x1b[0m"

# define ASC 1
# define DESC -1

void	r_sort(t_stack *a, t_stack *b, int lsize);
void	o_sort(t_stack *a, t_stack *b, int lsize);

int		find(t_arr arr, int val)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = arr.head;
	while (cnt < arr.size)
	{
		if (arr.data[I(i, NOP)] == val)
			return (cnt);
		cnt++;
		i++;
	}
	return (cnt);
}

void	init_stack(int *data, int size, t_stack *a, t_stack *b)
{
	t_arr	arr;
	int		i;
	int		index;

	I(NOP, size);
	initarr(&arr, size);
	if (!arr.data)
		errorexit("Error : Malloc Error\n");
	init(a);
	init(b);
	sort_arr(&arr, data, size);
	i = size - 1;
	while (i >= 0)
	{
		index = find(arr, data[i]);
		push(a, index);
		i--;
	}
	free(arr.data);
}


int		a_ordered(t_stack *st, int size)
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

int		d_ordered(t_stack *st, int size)
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

int		is_ordered(t_stack *st, int type, int size)
{
	if (type == ASC)
		return (a_ordered(st, size));
	return (d_ordered(st, size));
}

int		all_bigger_than(t_stack *a, int cnt , int pivot)
{
	int		i;
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

int		all_smaller_than(t_stack *b, int cnt, int pivot)
{
	int		i;
	t_node	*pos;

	i = 0;
	pos = b->head;
	while (i < cnt)
	{
		if (pos->data > pivot)
			return (0);
		i++;
		pos = pos->next;
	}
	return (1);
}
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
	while (i < time)
	{
		rra(a);
		i++;
	}
}

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
	while (i < time)
	{
		rrb(b);
		i++;
	}
}

void	divide(t_stack *a, t_stack *b, int type, int lsize)
{
	if (type == ASC)
		a_divide(a, b, lsize);
	else
		d_divide(a, b, lsize);
}

void	merge(t_stack *a, t_stack *b, int type, int size)
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
	if (is_ordered(a, ASC, 3))
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
	if (is_ordered(b,DESC, 3))
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
	if (lsize == 1 || is_ordered(b, type, lsize))
		return ;
	else if (lsize == 2 && !is_ordered(b, type, lsize))
	{
		sb(b);
		return ;
	}
	else if (lsize == 3)
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
	divide(a, b, type, lsize);
	o_sort(a, b, bsize - b->size);
	r_sort(a, b, lsize - (bsize - b->size));
	merge(a, b, type, bsize - b->size);
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
	if (lsize == 1 || is_ordered(a, type, lsize))
		return ;
	else if (lsize == 2 && !is_ordered(a, type, lsize))
	{
		sa(a);
		return ;
	}	
	else if (lsize == 3)
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
	divide(a, b, type, lsize);
	o_sort(a, b, lsize - (asize - a->size));
	r_sort(a, b, asize - a->size);
	merge(a, b, type, asize - a->size);
}

int main(int ac, char *av[])
{
	t_stack	a;
	t_stack	b;
	int		*data;

	data = NULL;
	if (ac < 2 || !(check_arguments(&data, ac, av)))
	{
		if (data)
			free(data);
		errorexit("Error : Arguments\n");
	}
	init_stack(data, ac - 1,  &a, &b);
	free(data);
	control_log(INIT, NOCMD);
	o_sort(&a, &b, a.size);
	clear(&a);
	clear(&b);
	control_log(PRINT, NOCMD);
	control_log(CLEAR, NOCMD);
}
