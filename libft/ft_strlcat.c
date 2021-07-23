/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:24:42 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/24 02:12:52 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(char const *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_len(dst);
	if (len >= size)
		return (ft_len(src) + size);
	while ((i + 1 < size - len) && (src[i]))
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = 0;
	return (len + ft_len(src));
}
