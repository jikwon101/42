#include <stdio.h>
#include "libft.h"
#include "push_swap.h"
#include "quickpivot.h"

#define RED "\x1b[31m"
#define BLUE "\x1b[36m"
#define RESET "\x1b[0m"


# define ASC 1
# define DESC -1
void	process(t_stack *a, t_stack *b, int type, int lsize);
void	r_sort(t_stack *a, t_stack *b, int lsize);
int	check_arguments(int size, char *argv[])
{	
	// av[] is not int
	// av[] is bigger than an int
	// av[] is duplicate.
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
	//		printf("DIVIDE_ASC\n");
			//printpair(a, b);
		}
		for (int i = 0 ; i < time ; i++)
			rra(a);
	}
	else
	{
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
	//		printf("DIVIDE_DESC\n");
			//printpair(a, b);
		}
		for (int i = 0 ; i < time ; i++)
			rrb(b);
	}
}

void	n_merge(t_stack *a, t_stack *b, int type, int size)
{
	if (type == ASC)
	{
		for (int i = 0 ; i < size ; i++)
			pa(a, b);
	}
	else
	{
		for (int i = 0 ; i < size ; i++)
			pb(a, b);
	}
//	printf("MERGE\n");
	//printpair(a, b);
}

void	o_sort(t_stack *a, t_stack *b, int lsize)
{
	int	asize;
	int	bsize;
	int	type;

	type = ASC;
	//printf("a is sorting in [%d]\n", lsize);
	if (lsize == 1 || n_is_ordered(a, type, lsize))
		return ;
	else if (lsize == 2 && !n_is_ordered(a, type, lsize))
	{
		sa(a);
		return ;
	}
	asize = a->size;
	n_divide(a, b, type, lsize);
	o_sort(a, b, lsize - (asize - a->size));
	r_sort(a, b, asize - a->size);
	n_merge(a, b, type, asize - a->size);
}

void	r_sort(t_stack *a, t_stack *b, int lsize)
{	
	int	asize;
	int	bsize;
	int	type;

//	printf("b is sorting in [%d]\n", lsize);
	type = DESC;
	if (lsize == 1 || n_is_ordered(b, type, lsize))
		return ;
	else if (lsize == 2 && !n_is_ordered(b, type, lsize))
	{
		sb(b);
		return ;
	}
	bsize = b->size;
	n_divide(a, b, type, lsize);
	o_sort(a, b, bsize - b->size);
	r_sort(a, b, lsize - (bsize - b->size));
	n_merge(a, b, type, bsize - b->size);
}

void	process(t_stack *a, t_stack *b, int type, int lsize)
{
	int	asize;
	int bsize;

	if (lsize == 1 || n_is_ordered(a, type, lsize))
		return ;
	else if (lsize == 2 && !n_is_ordered(a, type, lsize))
	{
		sa(a);
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
	//printf(RED "--------------------------PRE\n" RESET);
	//printpair(&a, &b);
	//printf(RED "-----------------------------\n" RESET);
	//quicksort(&a, &b, ASC);
	process(&a, &b, ASC, a.size);
	//printf(RED "--------------------------RES\n" RESET);
//	printpair(&a, &b);
//	printf(RED "-----------------------------\n" RESET);
	clear(&a);
	clear(&b);
}
