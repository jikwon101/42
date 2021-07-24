#include "push_swap.h"

void	init_stack(char **sets, int size, t_stack *a, t_stack *b)
{
	int	i;

	i = size;
	init(a);
	init(b);
	while (i > 0)
	{
		push(a, ft_atoi(sets[i - 1]));
		i--;
	}
}

int	main(int ac, char *av[])
{
	int		size;
	t_stack	a;
	t_stack	b;
	char	**sets;

	size = ac - 1;
	sets = av + 1;
	if (ac == 2)
	{
		sets = ft_split(av[1], ' ');
		if (!sets)
			errorexit("Error : Check Argument\n");
		size = 0;
		while (sets[size])
			size++;
	}
	if (ac < 2 || !size || !check_arguments(size, sets))
		errorexit("Error : Check Arguments\n");
	init_stack(sets, size, &a, &b);
	control_log(INIT, NOCMD);
	a_sort(&a, &b, a.size);
	clear(&a);
	clear(&b);
	control_log(PRINT, NOCMD);
	control_log(CLEAR, NOCMD);
}
