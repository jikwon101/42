#include "check_argument.h"

int	check_arguments(int size, char **sets)
{	
	int	i;
	int	res;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * (size));
	if (!arr)
		errorexit("Error : Malloc error\n");
	i = 0;
	while (i < size)
	{
		if (!is_int(sets[i]) || isn_int_range(sets[i]))
		{
			free(arr);
			return (0);
		}
		res = ft_atoi(sets[i]);
		if (is_duplicate(arr, i, res))
		{
			free(arr);
			return (0);
		}
		arr[i] = res;
		i++;
	}
	return (1);
}
