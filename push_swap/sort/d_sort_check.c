/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_sort_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:30:47 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/25 22:12:11 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	check_rb(t_stack *b)
{
	t_node	*pos;
	int		i;

	i = 0;
	pos = b->head->next;
	while (i < b->size - 1)
	{
		if (pos->data < pos->next->data)
			return (0);
		pos = pos->next;
		i++;
	}
	return (1);
}

int	check_rrb(t_stack *b)
{
	t_node	*pos;
	int		i;

	i = 0;
	pos = b->head->prev;
	while (i < b->size - 1)
	{
		if (pos->data < pos->next->data)
			return (0);
		pos = pos->next;
		i++;
	}
	return (1);
}

int	check_sb(t_stack *b)
{
	t_node	*pos;
	t_node	*second;
	int		i;

	i = 0;
	pos = b->head->next;
	second = pos;
	while (i < b->size - 2)
	{
		if (pos->data < pos->next->data)
			return (0);
		pos = pos->next;
		i++;
	}
	if (top(b) < second->data && top(b) > second->next->data)
		return (1);
	return (0);
}

int	d_order_type(t_stack *b, int lsize)
{
	if (b->size == lsize && b->size > 3)
	{
		if (check_rb(b))
			return (1);
		if (check_rrb(b))
			return (2);
	}
	if (check_sb(b))
		return (3);
	return (0);
}
