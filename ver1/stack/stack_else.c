/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_else.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:31:50 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/25 02:31:50 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_stack *st)
{
	int	temp;

	if (isempty(st))
		return ;
	temp = st->head->data;
	st->head->data = st->head->next->data;
	st->head->next->data = temp;
}

void	rotate(t_stack *st)
{
	if (isempty(st))
		return ;
	st->head = st->head->next;
}

void	reverse_rotate(t_stack *st)
{
	if (isempty(st))
		return ;
	st->head = st->head->prev;
}
