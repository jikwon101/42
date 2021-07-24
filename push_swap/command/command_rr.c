/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:27:03 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/25 02:27:05 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void	rra(t_stack *a)
{
	control_log(ADD, "rra");
	if (a->size < 2)
		return ;
	reverse_rotate(a);
}

void	rrb(t_stack *b)
{
	control_log(ADD, "rrb");
	if (b->size < 2)
		return ;
	reverse_rotate(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	control_log(ADD, "rrr");
	reverse_rotate(a);
	reverse_rotate(b);
}
