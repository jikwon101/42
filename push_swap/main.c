#include <stdio.h>
#include "libft.h"
#include "push_swap.h"
#include "quickpivot.h"

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

int	a_ordered(t_stack *st)
{
	t_node *pos;
	int	cnt = st->size;

	pos = st->head;
	while (cnt)
	{
		if (pos->data > pos->next->data)
			return (0);
		pos = pos->next;
		cnt--;
	}
	return (1);
}

int	b_ordered(t_stack *st)
{
	t_node	*pos;
	int cnt = st->size;

	pos = st->head;
	while (cnt)
	{
		if (pos->data < pos->next->data)
			return (0);
		pos = pos->next;
		cnt--;
	}
	return (1);
}

int main(int ac, char *av[])
{
	t_stack	a;
	t_stack	b;
	int		res;

	if (ac < 2 || !(res = check_arguments(ac, av)))
	{
		printf("Error\n"); //stdderr ***
		return (1);
	}
	init_stack(ac, av, &a);
	printpair(&a, &b);
	printf("pivot : %d\n", find_pivot(&a));
}
