/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 01:58:37 by jikwon            #+#    #+#             */
/*   Updated: 2020/07/31 11:03:52 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

int		is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_cntchr(char *str, char c)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == c)
			cnt++;
		i++;
	}
	return (cnt);
}

char	**check_color_elem(char **elem)
{
	int		cnt;
	char	**result;

	cnt = 0;
	while (elem[cnt])
		cnt++;
	if (cnt != 2)
		return (0);
	if (ft_cntchr(elem[1], ',') != 2)
		return (0);
	result = ft_split(elem[1], ',');
	return (result);
}

int		ft_is_blank(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (i == (int)ft_strlen(line))
		return (1);
	else
		return (0);
}
