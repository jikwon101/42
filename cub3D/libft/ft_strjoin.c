/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:24:41 by jikwon            #+#    #+#             */
/*   Updated: 2020/04/04 21:04:46 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_len(char const *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		tot_len;
	char	*result;
	int		i;

	tot_len = ft_len(s1) + ft_len(s2) + 1;
	if ((result = (char *)malloc(tot_len * sizeof(char))) == 0)
		return (0);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[i - ft_len(s1)])
	{
		result[i] = s2[i - ft_len(s1)];
		i++;
	}
	result[i] = 0;
	return (result);
}
