/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 03:12:40 by jikwon            #+#    #+#             */
/*   Updated: 2020/02/13 08:54:40 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	len = max - min;
	if ((*range = (int *)malloc(sizeof(int) * len)) == 0)
		return (0);
	while (i < len)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (len);
}
