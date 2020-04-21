/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:23:59 by jikwon            #+#    #+#             */
/*   Updated: 2020/04/04 19:23:38 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	size_t	i;
	int		result;
	int		a;
	int		b;

	i = 0;
	result = 0;
	while (i < count)
	{
		if (*((unsigned char *)buf1 + i) != *((unsigned char *)buf2 + i))
		{
			a = *((unsigned char *)buf1 + i);
			b = *((unsigned char *)buf2 + i);
			result = a - b;
			break ;
		}
		i++;
	}
	return (result);
}
