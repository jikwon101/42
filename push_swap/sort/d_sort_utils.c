/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_sort_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:30:53 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/25 02:30:54 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	d_ordered(t_stack *st, int size)
{
	t_node	*pos;

	pos = st->head;
	while (size - 1 > 0)
	{
		if (pos->data < pos->next->data)
			return (0);
		pos = pos->next;
		size--;
	}
	return (1);
}

int	all_smaller_than(t_stack *b, int cnt, int pivot)
{
	int		i;
	t_node	*pos;

	i = 0;
	pos = b->head;
	while (i < cnt)
	{
		if (pos->data > pivot)
			return (0);
		i++;
		pos = pos->next;
	}
	return (1);
}

int	d_arranged_type(t_stack *b, int lsize)
{
	int	type;

	if (lsize == 1 || is_ordered(b, DESC, lsize))
		return (1);
	type = d_order_type(b, lsize);
	if (lsize == 2 || type == 3)
		return (2);
	else if (lsize == 3)
		return (3);
	else if (type == 1)
		return (4);
	else if (type == 2)
		return (5);
	return (0);
}

void	d_sort_sp(t_stack *b, int type)
{
	if (type == 1)
		return ;
	else if (type == 2)
		sb(b);
	else if (type == 3)
		d_sort_three(b);
	else if (type == 4)
		rb(b);
	else if (type == 5)
		rrb(b);
}
