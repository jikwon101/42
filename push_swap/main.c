#include <stdio.h>
#include "libft.h"
#include "push_swap.h"
#include "quickpivot.h"

# define ASC 0
# define DESC 1

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
void	divide(t_stack *a, t_stack *b)
{
	int	pivot;
	int	cnt;
	int	info[2];
	
	cnt = a->size;
	pivot = find_pivot(a, info);
	printf("pivot : %d\n", pivot);
	while (cnt > 0)
	{
		if (top(a) < pivot)
		{
			pb(a, b);
			//printpair(a, b);
			//usleep(1000000);
		}
		else
		{
			ra(a);
			//printpair(a, b);
			//usleep(1000000);
		}
		cnt--;
	}
	printpair(a, b);
	usleep(1000000);
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
		return ;
	}
	while (!is_ordered(a, type))
	{
		asize = a->size;
		bsize = b->size;
		printf("-----------------------DIVIDE\n");
		divide(a, b);
		if (!is_ordered(a, ASC))
		{	
			printf("-----------------------SORT_A\n");
			quicksort(a, b, ASC);
			printpair(a, b);
			usleep(1000000);
		}
	}
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
	printf("--------------------------PRE\n");
	printpair(&a, &b);
	usleep(2000000);
	while (!is_ordered(&a, ASC))
	{
		quicksort(&a, &b, ASC);
		printf("------------------MID\n");
		quicksort(&b, &a, DESC);
	}
	printf("--------------------------RES\n");
	printpair(&a, &b);
}
