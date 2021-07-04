#include "quickpivot.h"

int	I(int i, int option)
{
	static int stsize;

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

void	initarr(t_arr *arr, int stsize)
{
	arr->head = 0;
	arr->size = 0;
	arr->data = (int *)malloc(sizeof(stsize));
	//temp
	if (arr->data)
	{
		for (int i = 0 ; i < stsize ; i++)
			(arr->data)[i] = -100;
	}
}

void	insert(int pos, t_arr *arr, int val)
{
	pos = I(pos, NOP);
	(arr->data)[pos] = val;
	arr->size++;
}

void push_forward(int pos, t_arr *arr, int val)
{
	//printf("%d is forward of %d\n", val, (arr->data)[pos]);
	int	i;
	int	cnt;

	cnt = I(pos - arr->head, NOP);
	i = arr->head - 1;
	while (i < arr->head - 1 + cnt)
	{
		(arr->data)[I(i, NOP)] = (arr->data)[I(i + 1, NOP)];
		i++;
	}
	arr->head = I(arr->head - 1, NOP);
	insert(pos - 1, arr, val);
}

void push_backward(int pos, t_arr *arr, int val)
{
	//printf("%d is backward of %d\n", val, (arr->data)[pos]);
	int	i;
	int	k;
	int	cnt;
	
	cnt = arr->size - I(pos - arr->head, NOP);
	k = 0;
	i = I(pos + cnt - 1, NOP);
	while (k < cnt)
	{
		(arr->data)[I(i + 1, NOP)] = (arr->data)[I(i, NOP)];
		i--;
		k++;
	}
	insert(pos, arr, val);
}

int	distance(int pos, t_arr *arr)
{
	int	front;
	int	back;

	front = I(pos - arr->head, NOP);
	back = arr->size - front;
	if (front < back)
		return (1);		//push_forward
	return (0);			//push_backward
}


void	printarray(t_arr *arr, int stsize)
{
	printf("[%2d] :  ", (arr->data)[arr->head]);
	int i = 0;
	while (i < stsize)
	{
		if ((arr->data)[i % stsize] == -100)
			printf("%2s ", ".");
		else
			printf("%2d ", (arr->data)[i % stsize]);
		i++;
	}
	printf("\n");
/*
	int k = arr->head;
	while (k < arr->head + arr->size)
	{
		printf("%d ", (arr->data)[k % arr->stsize]);
		k++;
	}
	printf("\n");
	*/
	
}

void	sort(t_arr *arr, t_stack *st)
{
	int		stcnt;
	t_node	*pos;
	int		i;

	stcnt = 0;
	pos = st->head;
	while (stcnt < st->size)
	{
		i = arr->head;
		while (i < (arr->head + arr->size))
		{
			if ((arr->data)[I(i, NOP)] < pos->data)
				i++;
			else
				break;
		}
		i = I(i, NOP);
		if (distance(i, arr))
			push_forward(i, arr, pos->data);
		else
			push_backward(i, arr, pos->data);
		stcnt++;
		pos = pos->next;
		printarray(arr, st->size);
	}
}

int	find_pivot(t_stack *st, int *res)
{
	t_arr	arr;

	I(NOP, st->size);
	initarr(&arr, st->size);
	if (!arr.data)
		exit(1);
	sort(&arr, st);
	res[0] = (arr.data)[arr.head];
	res[1] = (arr.data)[I(arr.head + arr.size - 1, NOP)];
	return (arr.data[I(arr.head + (arr.size / 2), NOP)]);
}
