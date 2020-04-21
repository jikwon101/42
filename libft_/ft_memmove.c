/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:24:06 by jikwon            #+#    #+#             */
/*   Updated: 2020/04/12 20:35:57 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*ft_memcpy_rev(void *dst, void const *src, size_t size)
{
	size_t			i;
	unsigned char	temp;

	i = size;
	while (i > 0)
	{
		temp = *((unsigned char *)src + i - 1);
		*((unsigned char *)dst + i - 1) = temp;
		i--;
	}
	return (dst);
}

void			*ft_memmove(void *dest, void const *src, size_t n)
{
	unsigned long int	addr_dest;
	unsigned long int	addr_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	addr_dest = (unsigned long int)dest;
	addr_src = (unsigned long int)src;
	if (addr_dest < addr_src)
		ft_memcpy(dest, src, n);
	else
		ft_memcpy_rev(dest, src, n);
	return (dest);
}
