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

int main(int ac, char *av[])
{
	t_stack	a;
	t_stack	b;
	int		res;

	if (ac < 2)
	{
		printf("Error\n");
		return (1);
	}
	res = check_arguments(ac, av);
	if (!res)
		return (1);
	while (ac > 1)
	{
		push(&a, ft_atoi(av[ac - 1]));
		ac--;
	}
	print(&a);
	sa(&a, &b);
	print(&a);
}
