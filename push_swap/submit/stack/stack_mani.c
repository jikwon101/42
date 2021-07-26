/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mani.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:31:37 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/26 20:08:32 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	pop(t_stack *st)
{
	t_node	*target;

	if (isempty(st))
		return ;
	target = st->head;
	if (st->size == 1)
	{
		st->head = NULL;
		free(target);
	}
	else
	{
		connecting(target->prev, target->next);
		st->head = target->next;
		free(target);
	}
	st->size--;
}

void	push(t_stack *st, int val)
{
	t_node	*temp;
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		errorexit(NULL);
	newnode->data = val;
	if (isempty(st))
	{
		st->head = newnode;
		connecting(newnode, newnode);
	}
	else
	{
		temp = st->head->prev;
		connecting(newnode, st->head);
		connecting(temp, newnode);
		st->head = newnode;
	}
	st->size++;
}

int	top(t_stack *st)
{
	return (st->head->data);
}

void	clear(t_stack *st)
{
	while (!isempty(st))
	{
		pop(st);
	}
}
