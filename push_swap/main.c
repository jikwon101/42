#include <stdio.h>
#include "libft.h"
#include "push_swap.h"
#include "quickpivot.h"

#define RED "\x1b[31m"
#define BLUE "\x1b[36m"
#define RESET "\x1b[0m"


# define ASC 1
# define DESC -1

int	check_arguments(int size, char *argv[])
{	
	// av[] is not int
	// av[] is bigger than an int
	// av[] is duplicate.
	return (1);
}

void	init_stack(int ac, char *av[], t_stack *a)
{
	while (ac > 1)
	{
		push(a, ft_atoi(av[ac - 1]));
		ac--;
	}
}

int	ordered(t_stack *st)
{
	t_node	*pos;
	int		cnt;;

	cnt = st->size;
	pos = st->head;
	while (cnt - 1 > 0)
	{
		if (pos->data > pos->next->data)
			return (0);
		pos = pos->next;
		cnt--;
	}
	return (1);
}

int	reverse_ordered(t_stack *st)
{
	t_node	*pos;
	int cnt = st->size;

	pos = st->head;
	while (cnt - 1 > 0)
	{
		if (pos->data < pos->next->data)
			return (0);
		pos = pos->next;
		cnt--;
	}
	return (1);
}

int		is_ordered(t_stack *st, int type)
{
	if (type == ASC)
		return (ordered(st));
	return (reverse_ordered(st));
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


void	divide(t_stack *a, t_stack *b, int type)
{
	int	pivot;
	int	cnt;
	int	info[2];
	int rtime;
	
	rtime = 0;
	cnt = a->size;
	pivot = find_pivot(a, info, a->size);
	printf(BLUE "pivot : %d\n", pivot); printf(RESET);
	while (cnt > 0)
	{
		if (type == ASC)
		{
			if (top(a) < pivot)
				pb(a, b);
			else
			{
				ra(a);
				rtime++;
			}
		}
		else
		{
			if (top(a) > pivot)
				pb(a, b);
			else
			{
				ra(a);
				rtime++;
			}
		}
		cnt--;
	}
	while (rtime)
	{
		rra(a);
		rtime--;
	}
	if (type == ASC)
		printpair(a, b);
	else
		printpair(b, a);
}

void	remerge(t_stack *a, t_stack *b, int asize, int bsize)
{
	int cnt;
	
	cnt = asize - a->size;
	while (cnt)
	{
		pa(a, b);
		cnt--;
	}
	printpair(a, b);
}

void	quicksort(t_stack *a, t_stack *b, int type)
{
	int	asize;
	int	bsize;

	if (a->size == 1 || is_ordered(a, type))
		return ; 
	if (a->size == 2 && !is_ordered(a, type))
	{
		sa(a);
		printpair(a, b);
		return ;
	}
	asize = a->size;
	bsize = b->size;
	divide(a, b, type);
	//quicksort(a, b, type);
	remerge(a, b, asize, bsize);
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

void	n_divide(t_stack *a, t_stack *b, int size)
{
	int	pivot;
	int	i;
	int	cnt;
	int	info[2];

	i = 0;
	cnt = size;
	pivot = find_pivot(a, info, a->size);
	printf(BLUE "pivot : %d\n", pivot); printf(RESET);
	while (i < cnt || !all_bigger_than(a, cnt - size, pivot))
	{
		if (top(a) < pivot)
			pb(a, b);
		else
			ra(a);
		printpair(a, b);
		i++;
	}
}

void	n_merge(t_stack *a, t_stack *b, int size)
{
	for (int i = 0 ; i < size ; i++)
		pa(a, b);
}

void	o_sort(t_stack *a, t_stack *b, int size)
{
	
}
void	r_sort(t_stack *b, t_stack *a, int size)
{

}

void	process(t_stack *a, t_stack *b, int lsize)
{
	int	asize;
	int bsize;

	asize = a->size;
	n_divide(a, b, lsize);
	o_sort(a, b, a->size - lsize);
	r_sort(b, a, asize - a->size);
	n_merge(a, b, asize - a->size);
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
	init_stack(ac, av, &a);
	printf(RED "--------------------------PRE\n" RESET);
	printpair(&a, &b);
	printf(RED "-----------------------------\n" RESET);
	//quicksort(&a, &b, ASC);
	process(&a, &b);
	printf(RED "--------------------------RES\n" RESET);
	printpair(&a, &b);
	printf(RED "-----------------------------\n" RESET);
}
