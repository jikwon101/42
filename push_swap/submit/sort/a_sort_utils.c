/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_sort_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:30:38 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/26 17:10:19 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	a_ordered(t_stack *st, int size)
{
	t_node	*pos;

	pos = st->head;
	while (size - 1 > 0)
	{
		if (pos->data > pos->next->data)
			return (0);
		pos = pos->next;
		size--;
	}
	return (1);
}

int	all_bigger_than(t_stack *a, int cnt, int pivot)
{
	int		i;
	t_node	*pos;

	i = 0;
	pos = a->head;
	while (i < cnt)
	{
		if (pos->data < pivot)
			return (0);
		i++;
		pos = pos->next;
	}
	return (1);
}

int	a_arranged_type(t_stack *a, int lsize)
{
	int	type;

	if (lsize == 1 || is_ordered(a, ASC, lsize))
		return (1);
	type = a_order_type(a, lsize);
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

void	a_sort_sp(t_stack *a, int type)
{
	if (type == 1)
		return ;
	else if (type == 2)
		sa(a);
	else if (type == 3)
		a_sort_three(a);
	else if (type == 4)
		ra(a);
	else if (type == 5)
		rra(a);
}
