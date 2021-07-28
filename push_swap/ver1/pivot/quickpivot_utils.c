/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickpivot_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:29:58 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/26 17:07:50 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quickpivot.h"

int	i_(int i, int option)
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
	pos = i_(pos, NOP);
	(arr->data)[pos] = val;
	arr->size++;
}

int	distance(int pos, t_arr *arr)
{
	int	front;
	int	back;

	front = i_(pos - arr->head, NOP);
	back = arr->size - front;
	if (front < back)
		return (1);
	return (0);
}
