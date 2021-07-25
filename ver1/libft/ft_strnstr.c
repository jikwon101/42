/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:24:49 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/24 02:05:34 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static	int	ft_init(size_t *i, size_t *j, int *count)
{
	*i = 0;
	*j = 0;
	*count = 0;
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;
	int		count;

	ft_init(&i, &j, &count);
	if (*little == 0)
		return ((char *)big);
	while (i < n)
	{
		if (big[i] == little[j])
		{
			j++;
			count++;
			if (count == ft_len(little))
				return ((char *)(big + i - count + 1));
		}
		else
		{
			i = i - count;
			j = 0;
			count = 0;
		}
		i++;
	}
	return (0);
}
