/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:25:06 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/26 20:12:27 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_argument.h"

int	check_arguments(int size, char **sets)
{
	int	i;
	int	res;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * (size));
	if (!arr)
		errorexit(NULL);
	i = -1;
	res = 1;
	while (i++ < size - 1)
	{
		if (!is_int(sets[i]) || isn_int_range(sets[i]))
		{
			res = 0;
			break ;
		}
		if (is_duplicate(arr, i, ft_atoi(sets[i])))
		{
			res = 0;
			break ;
		}
		arr[i] = ft_atoi(sets[i]);
	}
	free(arr);
	return (res);
}
