#include "quickpivot.h"

void	push_forward(int pos, t_arr *arr, int val)
{
	int	i;
	int	cnt;

	cnt = _i(pos - arr->head, NOP);
	i = arr->head - 1;
	while (i < arr->head - 1 + cnt)
	{
		(arr->data)[_i(i, NOP)] = (arr->data)[_i(i + 1, NOP)];
		i++;
	}
	arr->head = _i(arr->head - 1, NOP);
	insert(pos - 1, arr, val);
}

void	push_backward(int pos, t_arr *arr, int val)
{
	int	i;
	int	k;
	int	cnt;

	cnt = arr->size - _i(pos - arr->head, NOP);
	k = 0;
	i = _i(pos + cnt - 1, NOP);
	while (k < cnt)
	{
		(arr->data)[_i(i + 1, NOP)] = (arr->data)[_i(i, NOP)];
		i--;
		k++;
	}
	insert(pos, arr, val);
}

void	sort(t_arr *arr, t_stack *st, int lsize)
{
	int		cnt;
	t_node	*pos;
	int		i;

	cnt = 0;
	pos = st->head;
	while (cnt < lsize)
	{
		i = arr->head;
		while (i < (arr->head + arr->size))
		{
			if ((arr->data)[_i(i, NOP)] < pos->data)
				i++;
			else
				break ;
		}
		i = _i(i, NOP);
		if (distance(i, arr))
			push_forward(i, arr, pos->data);
		else
			push_backward(i, arr, pos->data);
		cnt++;
		pos = pos->next;
	}
}

int	find_pivot(t_stack *st, int lsize)
{
	t_arr	arr;
	int		res;

	_i(NOP, lsize);
	initarr(&arr, lsize);
	if (!arr.data)
		errorexit("Error : Malloc error\n");
	sort(&arr, st, lsize);
	res = (arr.data[_i(arr.head + (arr.size / 2), NOP)]);
	if (arr.data)
		free(arr.data);
	return (res);
}
