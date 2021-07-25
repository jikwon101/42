#include "push_swap.h"

int		find(t_arr arr, int val)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = arr.head;
	while (cnt < arr.size)
	{
		if (arr.data[_i(i, NOP)] == val)
			return (cnt);
		cnt++;
		i++;
	}
	return (cnt);
}

void	init_stack(int *data, int size, t_stack *a, t_stack *b)
{
	t_arr	arr;
	int		i;
	int		index;

	_i(NOP, size);
	initarr(&arr, size);
	if (!arr.data)
		errorexit("Error : Malloc Error\n");
	init(a);
	init(b);
	sort_arr(&arr, data, size);
	i = size - 1;
	while (i >= 0)
	{
		index = find(arr, data[i]);
		push(a, index);
		i--;
	}
	free(arr.data);
}
//#include <fcntl.h>
int main(int ac, char *av[])
{
	t_stack	a;
	t_stack	b;
	int		*data;

	data = NULL;
	if (ac < 2 || !(check_arguments(&data, ac, av)))
	{
		if (data)
			free(data);
		errorexit("Error : check_Arguments\n");
	}
	init_stack(data, ac - 1,  &a, &b);
	//int fd = open("input.txt", O_RDWR | O_CREAT, 0644);
	//savef(fd, &a); //temp
	free(data);
	control_log(INIT, NOCMD);
	a_sort(&a, &b, a.size);
	clear(&a);
	clear(&b);
	control_log(PRINT, NOCMD);
	control_log(CLEAR, NOCMD);
}
