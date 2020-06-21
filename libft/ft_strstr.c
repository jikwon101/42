/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:24:49 by jikwon            #+#    #+#             */
/*   Updated: 2020/04/06 20:19:46 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_init(size_t *i, size_t *j, size_t *count)
{
	*i = 0;
	*j = 0;
	*count = 0;
	return (0);
}

char		*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;
	size_t	count;

	ft_init(&i, &j, &count);
	if (*little == 0)
		return ((char *)big);
	while (big[i])
	{
		if (big[i] == little[j])
		{
			j++;
			count++;
			if (count == ft_strlen(little))
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
