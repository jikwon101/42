/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:24:51 by jikwon            #+#    #+#             */
/*   Updated: 2020/04/06 21:04:16 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*new;

	i = 0;
	while (s[i])
		i++;
	while ((s[i] != c) && (i >= 0))
		i--;
	if (s[i] == c)
		new = (char *)(s + i);
	else
		new = NULL;
	return (new);
}
