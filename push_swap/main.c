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
	quicksort(a, b, type);
	remerge(a, b, asize, bsize);
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
	quicksort(&a, &b, ASC);
	printf(RED "--------------------------RES\n" RESET);
	printpair(&a, &b);
	printf(RED "-----------------------------\n" RESET);
}
