/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument_sub.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:25:13 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/26 20:13:01 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_argument_sub.h"

int	is_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_under_min(char *str)
{
	int		res;
	char	*minint;
	size_t	len;

	res = 0;
	minint = ft_strdup("2147483648");
	if (!minint)
		errorexit(NULL);
	if (*str && *str == '-')
		str++;
	while (*str && *str == '0')
		str++;
	len = ft_strlen(str);
	if (len > ft_strlen(minint)
		|| (len == ft_strlen(minint) && ft_strcmp(minint, str) < 0))
		res = 1;
	free(minint);
	return (res);
}

int	is_over_max(char *str)
{
	int		res;
	char	*maxint;
	size_t	len;

	res = 0;
	maxint = ft_strdup("2147483647");
	if (!maxint)
		errorexit(NULL);
	if (*str && *str == '+')
		str++;
	while (*str && *str == '0')
		str++;
	len = ft_strlen(str);
	if ((len > ft_strlen(maxint))
		|| (len == ft_strlen(maxint) && ft_strcmp(maxint, str) < 0))
		res = 1;
	free(maxint);
	return (res);
}

int	isn_int_range(char *str)
{
	int	res;

	res = 0;
	if (str[0] == '-')
		res = is_under_min(str);
	else
		res = is_over_max(str);
	return (res);
}

int	is_duplicate(int *data, int size, int n)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (data[i] == n)
			return (1);
		i++;
	}
	return (0);
}
