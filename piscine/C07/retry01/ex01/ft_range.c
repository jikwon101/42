/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 03:01:28 by jikwon            #+#    #+#             */
/*   Updated: 2020/02/13 08:54:15 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	len;
	int *result;
	int i;

	i = 0;
	if (min >= max)
		return (0);
	len = max - min;
	if ((result = (int *)malloc(sizeof(int) * len)) == 0)
		return (0);
	while (min < max)
		result[i++] = min++;
	return (result);
}
