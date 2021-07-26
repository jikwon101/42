/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:25:06 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/26 13:41:53 by jikwon           ###   ########.fr       */
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
		errorexit("Error : Malloc error\n");
	i = 0;
	res = 1;
	while (i < size)
	{
		if (!is_int(sets[i]) || isn_int_range(sets[i]))
		{
			res = 0;
			break ;
		}
		res = ft_atoi(sets[i]);
		if (is_duplicate(arr, i, ft_atoi(sets[i])))
		{
			res = 0;
			break ;
		}
		arr[i] = res;
		i++;
	}
	free(arr);
	return (res);
}
