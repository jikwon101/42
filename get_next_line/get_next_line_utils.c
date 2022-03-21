/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 15:33:27 by jikwon            #+#    #+#             */
/*   Updated: 2020/06/23 17:45:22 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_strlcpy(char *dst, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return ;
}

char	*ft_strdup(char *str, int size)
{
	char	*result;

	if (str == NULL)
		return (0);
	if ((result = (char *)malloc(size + 1)) == 0)
		return (0);
	result[size] = '\0';
	ft_strlcpy(result, str, size);
	return (result);
}

char	*ft_strchr(char *str, char target)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == target)
			return (str + i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		tot_len;
	int		len1;
	int		len2;
	char	*result;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	tot_len = len1 + len2;
	if ((result = (char *)malloc(tot_len + 1)) == 0)
		return (0);
	result[tot_len] = '\0';
	ft_strlcpy(result, s1, len1);
	ft_strlcpy(result + len1, s2, len2);
	return (result);
}
