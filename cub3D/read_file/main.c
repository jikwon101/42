/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 11:00:24 by jikwon            #+#    #+#             */
/*   Updated: 2020/07/31 11:06:38 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

t_file	*init_t_file(void)
{
	t_file	*rst;

	if ((rst = (t_file *)malloc(sizeof(t_file))) == NULL)
		return (0);
	rst->x_size = -1;
	rst->y_size = -1;
	rst->num_sp = -1;
	rst->path[N] = NULL;
	rst->path[S] = NULL;
	rst->path[W] = NULL;
	rst->path[E] = NULL;
	rst->path[I] = NULL;
	rst->color[F] = 0x000000;
	rst->color[C] = 0xffffff;
	rst->worldmap = NULL;
	return (rst);
}

int		read_file(char *file_name, t_file *f_set)
{
	int		fd;
	char	*line;
	char	*doc;

	doc = NULL;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		if (!ft_is_blank(line) && !ft_is_map(line) && !check_elem(&line, f_set))
			return (0);
		else if (!ft_is_blank(line) && ft_is_map(line))
			break ;
		free(line);
	}
	ft_temp_map(&doc, line);
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		ft_temp_map(&doc, line);
		free(line);
	}
	free(line);
	close(fd);
	return ((!last_check(f_set, &doc)) ? 0 : 1);
}

int		check_elem(char **line, t_file *f_set)
{
	char	**parse_elem;
	int		res;

	res = 0;
	parse_elem = ft_split(*line, ' ');
	if (!ft_strcmp(parse_elem[0], "R"))
		res = set_size(f_set, parse_elem);
	else if (!ft_strcmp(parse_elem[0], "NO"))
		res = set_path(f_set, parse_elem, N);
	else if (!ft_strcmp(parse_elem[0], "SO"))
		res = set_path(f_set, parse_elem, S);
	else if (!ft_strcmp(parse_elem[0], "WE"))
		res = set_path(f_set, parse_elem, W);
	else if (!ft_strcmp(parse_elem[0], "EA"))
		res = set_path(f_set, parse_elem, E);
	else if (!ft_strcmp(parse_elem[0], "S"))
		res = set_path(f_set, parse_elem, I);
	else if (!ft_strcmp(parse_elem[0], "F"))
		res = set_color(f_set, parse_elem, F);
	else if (!ft_strcmp(parse_elem[0], "C"))
		res = set_color(f_set, parse_elem, C);
	ft_free_array(parse_elem);
	if (res == 0)
		free(*line);
	return ((res == 0) ? 0 : 1);
}

int		last_check(t_file *f_set, char **doc)
{
	int	i;

	i = -1;
	if (!set_map(doc, f_set))
		return (0);
	if (f_set->x_size == -1 || f_set->y_size == -1)
		return (0);
	if (f_set->num_sp == -1)
		return (0);
	while (++i < 5)
	{
		if ((f_set->path)[i] == NULL)
			return (0);
	}
	return (1);
}
