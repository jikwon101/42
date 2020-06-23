/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:24:54 by jikwon            #+#    #+#             */
/*   Updated: 2020/04/12 17:20:08 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			count;
	unsigned int	i;
	char			*result;

	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	count = 0;
	i = start;
	while ((s[i]) && (count < len))
	{
		i++;
		count++;
	}
	if ((result = (char *)malloc(count + 1)) == 0)
		return (0);
	result[count] = 0;
	i = start;
	while (count > 0)
	{
		result[i - start] = s[i];
		i++;
		count--;
	}
	return (result);
}
