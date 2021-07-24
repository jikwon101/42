#include "check_argument_main.h"

int	check_arguments(int **data, int ac, char *argv[])
{	
	int	i;
	int	res;

	*data = (int *)malloc(sizeof(int) * (ac - 1));
	if (!*data)
		error("Error : Malloc error\n");
	i = 1;
	while (i < ac)
	{
		if (!is_int(argv[i]) || isn_int_range(argv[i]))
			return (0);
		res = ft_atoi(argv[i]);
		if (is_duplicate(*data, i - 1, res))
			return (0);
		(*data)[i - 1] = res;
		i++;
	}
	return (1);
}
