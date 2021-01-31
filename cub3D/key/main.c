/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 21:19:35 by jikwon            #+#    #+#             */
/*   Updated: 2020/08/11 19:41:44 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keycontrol.h"

int		ft_close(t_ptr *set)
{
	if (set->mlx && set->win)
	{
		mlx_clear_window(set->mlx, set->win);
		mlx_destroy_window(set->mlx, set->win);
		free(set->mlx);
	}
	free_all(set);
	exit(0);
}

void	angle_left(t_ptr *set, double speed)
{
	double	old_dirx;
	double	old_diry;
	double	old_planex;
	double	old_planey;

	old_dirx = set->v->dir_x;
	old_diry = set->v->dir_y;
	old_planex = set->v->plane_x;
	old_planey = set->v->plane_y;
	set->v->dir_x = old_dirx * cos(speed) - old_diry * sin(speed);
	set->v->dir_y = old_dirx * sin(speed) + old_diry * cos(speed);
	set->v->plane_x = old_planex * cos(speed) - old_planey * sin(speed);
	set->v->plane_y = old_planex * sin(speed) + old_planey * cos(speed);
	return ;
}

void	angle_right(t_ptr *set, double speed)
{
	double	old_dirx;
	double	old_diry;
	double	old_planex;
	double	old_planey;

	old_dirx = set->v->dir_x;
	old_diry = set->v->dir_y;
	old_planex = set->v->plane_x;
	old_planey = set->v->plane_y;
	set->v->dir_x = old_dirx * cos(-speed) - old_diry * sin(-speed);
	set->v->dir_y = old_dirx * sin(-speed) + old_diry * cos(-speed);
	set->v->plane_x = old_planex * cos(-speed) - old_planey * sin(-speed);
	set->v->plane_y = old_planex * sin(-speed) + old_planey * cos(-speed);
	return ;
}

int		key_press(int keycode, t_ptr *set)
{
	double	move_speed;
	double	rot_speed;

	move_speed = 5.0 * 0.05;
	rot_speed = 3.0 * 0.05;
	if (keycode == KEY_W)
		move_w(set, move_speed);
	else if (keycode == KEY_S)
		move_s(set, move_speed);
	else if (keycode == KEY_D)
		move_d(set, move_speed);
	else if (keycode == KEY_A)
		move_a(set, move_speed);
	else if (keycode == KEY_RIGHT)
		angle_right(set, rot_speed);
	else if (keycode == KEY_LEFT)
		angle_left(set, rot_speed);
	else if (keycode == ESC)
		ft_close(set);
	return (0);
}
