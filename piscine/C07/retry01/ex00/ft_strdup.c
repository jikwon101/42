/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:11:07 by jikwon            #+#    #+#             */
/*   Updated: 2020/02/12 21:24:34 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*new;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (src[len] != 0)
		len++;
	new = (char *)malloc(len + 1);
	if (new == '\0')
		return (NULL);
	while (i < len)
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
