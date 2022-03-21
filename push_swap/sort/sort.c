/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:30:57 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/25 02:30:58 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	is_ordered(t_stack *st, int type, int size)
{
	if (type == ASC)
		return (a_ordered(st, size));
	return (d_ordered(st, size));
}

void	divide(t_stack *a, t_stack *b, int type, int lsize)
{
	if (type == ASC)
		a_divide(a, b, lsize);
	else
		d_divide(a, b, lsize);
}

void	merge(t_stack *a, t_stack *b, int type, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (type == ASC)
			pa(a, b);
		else
			pb(a, b);
		i++;
	}
}
