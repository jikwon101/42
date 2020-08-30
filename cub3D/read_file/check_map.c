/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 01:35:58 by jikwon            #+#    #+#             */
/*   Updated: 2020/07/31 11:04:36 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

char	**check_map(char *doc)
{
	char	**result;

	result = ft_split(doc, '\n');
	if (!is_wrapped(result))
	{
		ft_free_array(result);
		return (0);
	}
	return (result);
}

int		is_wrapped(char **t_map)
{
	int	i;
	int	j;

	i = 0;
	while (t_map[i])
	{
		j = 0;
		while (t_map[i][j])
		{
			if (t_map[i][j] != '1' && t_map[i][j] != ' ')
			{
				if (!check_wall(t_map, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		check_wall(char **t_map, int x, int y)
{
	if (x == 0 || y == 0)
		return (0);
	if (!is_wall_v(t_map, x, y))
		return (0);
	if (!is_wall_p(t_map, x, y))
		return (0);
	return (1);
}

int		is_wall_v(char **t_map, int x, int y)
{
	int	i;
	int	j;
	int	x_len;

	i = x;
	x_len = ft_lenx(t_map);
	while (i >= 0 && y < (int)ft_strlen(t_map[i]) &&
			t_map[i][y] != '1' && t_map[i][y] != ' ')
		i--;
	j = x;
	while (j < x_len && y < (int)ft_strlen(t_map[j]) &&
			t_map[j][y] != '1' && t_map[j][y] != ' ')
		j++;
	if (i < 0 || y >= (int)ft_strlen(t_map[i]) ||
					j >= x_len || y >= (int)ft_strlen(t_map[j]))
		return (0);
	if (t_map[i][y] != '1' || t_map[j][y] != '1')
		return (0);
	return (1);
}

int		is_wall_p(char **t_map, int x, int y)
{
	int		i;
	int		j;
	char	*temp;

	i = y - 1;
	temp = t_map[x];
	while (i >= 0 && temp[i] != '1' && temp[i] != ' ')
		i--;
	j = y + 1;
	while (j < (int)ft_strlen(temp) && temp[j] != '1' && temp[j] != ' ')
		j++;
	if (i < 0 || j >= (int)ft_strlen(temp))
		return (0);
	if (temp[i] != '1' || temp[j] != '1')
		return (0);
	return (1);
}
