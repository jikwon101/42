/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:26:57 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/25 02:26:58 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void	ra(t_stack *a)
{
	control_log(ADD, "ra");
	if (a->size < 2)
		return ;
	rotate(a);
}

void	rb(t_stack *b)
{
	control_log(ADD, "rb");
	if (b->size < 2)
		return ;
	rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	control_log(ADD, "rr");
	rotate(a);
	rotate(b);
}
