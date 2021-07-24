#include "quickpivot.h"

int	_i(int i, int option)
{
	static int	stsize;

	if (option >= 0)
	{
		stsize = option;
		return (0);
	}
	while (i < 0)
		i += stsize;
	while (i >= stsize)
		i %= stsize;
	return (i);
}

void	initarr(t_arr *arr, int lsize)
{
	arr->head = 0;
	arr->size = 0;
	arr->data = (int *)malloc(sizeof(int) * lsize);
}

void	insert(int pos, t_arr *arr, int val)
{
	pos = _i(pos, NOP);
	(arr->data)[pos] = val;
	arr->size++;
}

int	distance(int pos, t_arr *arr)
{
	int	front;
	int	back;

	front = _i(pos - arr->head, NOP);
	back = arr->size - front;
	if (front < back)
		return (1);
	return (0);
}
