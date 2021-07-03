#include <stdio.h>
#include "libft.h"
#include "push_swap.h"

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
	t_node *pos;

	pos = st->head;
	while (pos->next)
	{
		if (pos->data > pos->next->data)
			return (0);
		pos = pos->next;
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
		printf("Error\n");
		return (1);
	}
	init_stack(ac, av, &a);
	//printpair(&a, &b);
	while (!ordered(&a))
	{
		if (top(&a) > next(&a))
		{
			printf("sa\n");
			sa(&a, &b);
		}
		else
		{
			printf("pb\n");
			pb(&a, &b);
			if (b.size > 1 && top(&b) < next(&b))
			{
				printf("sa\n");
				sb(&a, &b);
			}
		}
	}
	while (b.size)
	{
		printf("pa\n");
		pa(&a, &b);
		if (a.size > 1 && top(&a) > next(&a))
		{
			printf("sa\n");
			sa(&a, &b);
		}
	}
	//printpair(&a, &b);
}
