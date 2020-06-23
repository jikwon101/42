/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 16:30:51 by jikwon            #+#    #+#             */
/*   Updated: 2020/06/23 22:54:23 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int set_path(t_info **info_map, char **elem, int option)
{return (1);}

int set_color(t_info **info_map, char **elem, int option)
{return (1);}

void ft_free(char **str)
{
	int i;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
int check_elem(t_info **info_map, char *line)
{
	char **parse_elem;
	int res;

	res = 0;
	parse_elem = ft_split(line, ' ');
	if (!ft_strcmp(parse_elem[0], "NO"))
		res = set_path(info_map, parse_elem, 'N');
	else if (!ft_strcmp(parse_elem[0], "SO"))
		res = set_path(info_map, parse_elem, 'S');
	else if (!ft_strcmp(parse_elem[0], "EA"))
		res = set_path(info_map, parse_elem, 'E');
	else if (!ft_strcmp(parse_elem[0], "WE"))
		res = set_path(info_map, parse_elem, 'W');
	else if (!ft_strcmp(parse_elem[0], "S"))
		res = set_path(info_map, parse_elem, 'I');
	else if (!ft_strcmp(parse_elem[0], "F"))
		res = set_color(info_map, parse_elem, 'F');
	else if (!ft_strcmp(parse_elem[0], "C"))
		res = set_color(info_map, parse_elem, 'C');
	ft_free(parse_elem);
	return ((res == 0) ? 0 : 1);
}
int ft_is_map(char *line)
{
	return (1);
}

int	create_map(int fd, t_info **info_map, char **line)
{
	
	free(*line);
	return (1);
}

t_info *check_map_info(char *file_name)
{
	int fd;
	char *line;
	t_info *info_map;

	if (!(info_map = (t_info *)malloc(sizeof(t_info))))
		return (0);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &line) > 0 && !ft_is_map(line))
	{
		if (!line[0] && !check_elem(&info_map, line))
				return (0);
		free(line);
	}
	if (ft_is_map(line))
		create_map(fd, &info_map, &line);
	else
	{
		free(line);
		return (0);
	}
	close(fd);
	//return (0);
	return (info_map);
}

int quit(void *new)
{
	t_ptr *param;

	param = (t_ptr *)new;
	exit(0);
	return (0);
}

int main(int argc, char **argv)
{
	//t_ptr new;
	t_info *info_map;

	//new.mlx_ptr = mlx_init();
	//new.win_ptr = mlx_new_window(new.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "hello");
	if ((info_map = check_map_info(argv[1])) == NULL)
	{
		perror("ERROR in cub file");
		return (1);
	}
	double posX = 22;
	double posY = 11;
	double dirX = -1;
	double dirY = 0;
	double planeX = 0;
	double planeY = 0.80;
	double time = 0;
	double oldtime = 0;
	//read_file(new);
	//mlx_loop_hook(new.mlx, loop_hook, &new);
	//mlx_hook(new.win_ptr, EV_KEY_PRESS, MS_KEY_PRESS, key_press, &new);
	//mlx_hook(new.win_ptr, EV_KEY_RELEASE, MS_KEY_RELEASE, key_release, &new);
	//mlx_hook(new.win_ptr, 17, 1L, quit, &new);
	//mlx_loop(new.mlx_ptr);
	return (0);
}
