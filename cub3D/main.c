/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 16:40:21 by jikwon            #+#    #+#             */
/*   Updated: 2020/08/30 13:18:02 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_init(t_ptr *set)
{
	if (!init_loc(set, set->f))
		return (0);
	if (!init_tex(set))
		return (0);
	if (!init_sprite(set))
		return (0);
	return (1);
}

int		fill_img_buffer(t_ptr *set, t_image *i)
{
	t_wall	wl;
	t_dist	d;
	int		x;

	x = 0;
	if (!init_imageval(set, i))
		return (0);
	while (x < set->f->x_size)
	{
		init_distval(set, &d, x);
		cal_sidedist(set, &d);
		while (d.hit == 0)
			move_map(&d, set->f->worldmap);
		init_wallval1(set, &d, &wl, set->f->y_size);
		init_wallval2(set, &d, &wl, set->f->y_size);
		draw_buffer(set, &d, &wl, i);
		x++;
	}
	if (!draw_sprite(set, i))
		return (0);
	return (1);
}

int		loop_hook(t_ptr *set)
{
	t_image	*i;

	if ((i = (t_image *)malloc(sizeof(t_image) * 1)) == NULL)
		return (0);
	if (!fill_img_buffer(set, i))
		return (0);
	mlx_put_image_to_window(set->mlx, set->win, i->img, 0, 0);
	mlx_destroy_image(set->mlx, i->img);
	if (i->zbuffer != NULL)
		free(i->zbuffer);
	i->zbuffer = NULL;
	free(i);
	return (1);
}

void	init_ptr(t_ptr *set)
{
	int	i;

	i = 0;
	set->mlx = mlx_init();
	set->f = init_t_file();
	set->win = NULL;
	set->v = NULL;
	set->s = NULL;
	while (i < 6)
	{
		set->tex[i] = NULL;
		i++;
	}
	return ;
}

int		main(int argc, char **argv)
{
	t_ptr	set;

	init_ptr(&set);
	if (!read_file(argv[1], set.f))
	{
		perror("Error in cub file");
		free_all(&set);
		return (1);
	}
	set.win = mlx_new_window(set.mlx, set.f->x_size, set.f->y_size, "hello");
	ft_init(&set);
	if (argc == 3)
	{
		save_screen(&set, argv[2], set.f->x_size, set.f->y_size);
		return (1);
	}
	mlx_loop_hook(set.mlx, loop_hook, &set);
	mlx_hook(set.win, KEY_PRESS, 0, key_press, &set);
	mlx_hook(set.win, CLOSE, 0, ft_close, &set);
	mlx_loop(set.mlx);
	return (0);
}
