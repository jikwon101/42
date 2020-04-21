/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 22:52:03 by jikwon            #+#    #+#             */
/*   Updated: 2020/04/14 15:24:00 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_check(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	int	ft_count(const char *s1, const char *set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while ((ft_check(s1[i], set)))
		i++;
	while (s1[i])
	{
		count++;
		i++;
	}
	i--;
	while ((ft_check(s1[i], set)) && i != 0 && count != 0)
	{
		count--;
		i--;
	}
	count = count + 1;
	return (count);
}

char		*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		j;
	int		count;
	char	*result;

	i = 0;
	j = 0;
	count = ft_count(s1, set);
	if ((result = (char *)malloc(sizeof(char) * count)) == 0)
		return (0);
	while (ft_check(s1[j], set))
		j++;
	while (i < count - 1)
	{
		result[i] = s1[j];
		i++;
		j++;
	}
	result[i] = 0;
	return (result);
}
