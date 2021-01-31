/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 01:35:49 by jikwon            #+#    #+#             */
/*   Updated: 2020/08/10 13:48:59 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

int		set_size(t_file *f_set, char **elem)
{
	int	cnt;

	cnt = 0;
	while (elem[cnt])
		cnt++;
	if (cnt != 3)
		return (0);
	if (!is_num(elem[1]) || !is_num(elem[2]))
		return (0);
	if (ft_atoi(elem[1]) <= 0 || ft_atoi(elem[2]) <= 0)
		return (0);
	f_set->x_size = ft_atoi(elem[1]) > 2560 ? 2560 : ft_atoi(elem[1]);
	f_set->x_size = ft_atoi(elem[1]) < 640 ? 640 : ft_atoi(elem[1]);
	f_set->y_size = ft_atoi(elem[2]) > 1440 ? 1440 : ft_atoi(elem[2]);
	f_set->y_size = ft_atoi(elem[2]) < 480 ? 480 : ft_atoi(elem[2]);
	return (1);
}

int		set_path(t_file *f_set, char **elem, int option)
{
	int	cnt;
	int	fd;

	cnt = 0;
	while (elem[cnt])
		cnt++;
	if (cnt != 2)
		return (0);
	if (f_set->path[option] != NULL)
		free(f_set->path[option]);
	f_set->path[option] = ft_strdup(elem[1]);
	if ((fd = open(f_set->path[option], O_RDONLY)) == -1)
	{
		free(f_set->path[option]);
		f_set->path[option] = NULL;
		return (0);
	}
	close(fd);
	return (1);
}

int		set_color(t_file *f_set, char **elem, int option)
{
	unsigned int	num;
	char			**tmp;
	int				cnt;

	if ((tmp = check_color_elem(elem)) == NULL)
		return (0);
	num = 0;
	cnt = 0;
	while (tmp[cnt])
	{
		if (!is_num(tmp[cnt]))
		{
			ft_free_array(tmp);
			return (0);
		}
		num = num * 16 * 16 + ft_atoi(tmp[cnt]);
		cnt++;
	}
	f_set->color[option] = num;
	ft_free_array(tmp);
	return (1);
}

int		set_map(char **doc, t_file *f_set)
{
	char	**temp;

	if (ft_cntchr(*doc, 'N') + ft_cntchr(*doc, 'S')
			+ ft_cntchr(*doc, 'W') + ft_cntchr(*doc, 'E') != 1)
	{
		free(*doc);
		return (0);
	}
	f_set->num_sp = ft_check_sp(*doc);
	temp = check_map(*doc);
	free(*doc);
	if (temp == NULL)
		return (0);
	f_set->worldmap = temp;
	return (1);
}
