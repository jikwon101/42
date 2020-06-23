/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:25:43 by jikwon            #+#    #+#             */
/*   Updated: 2020/04/11 03:06:53 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_zero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
}

void			*ft_calloc(size_t nmemb, size_t size)
{
	size_t	tot;
	void	*result;

	tot = nmemb * size;
	if ((result = malloc(tot)) == 0)
		return (0);
	ft_zero(result, tot);
	return (result);
}
