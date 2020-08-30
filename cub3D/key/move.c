/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycontrol2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 21:19:35 by jikwon            #+#    #+#             */
/*   Updated: 2020/07/29 20:40:23 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keycontrol.h"

void	move_w(t_ptr *set, double speed)
{
	double	move_x;
	double	move_y;
	char	**map;

	move_x = (set->v->dir_x) * speed;
	move_y = (set->v->dir_y) * speed;
	map = set->f->worldmap;
	if (map[(int)(set->v->pos_x + move_x)][(int)(set->v->pos_y)] == '0')
		set->v->pos_x += move_x;
	if (map[(int)(set->v->pos_x)][(int)(set->v->pos_y + move_y)] == '0')
		set->v->pos_y += move_y;
	return ;
}

void	move_s(t_ptr *set, double speed)
{
	double	move_x;
	double	move_y;
	char	**map;

	move_x = (set->v->dir_x) * speed;
	move_y = (set->v->dir_y) * speed;
	map = set->f->worldmap;
	if (map[(int)(set->v->pos_x - move_x)][(int)(set->v->pos_y)] == '0')
		set->v->pos_x -= move_x;
	if (map[(int)(set->v->pos_x)][(int)(set->v->pos_y - move_y)] == '0')
		set->v->pos_y -= move_y;
	return ;
}

void	move_d(t_ptr *set, double speed)
{
	double	dir_x;
	double	dir_y;
	double	move_x;
	double	move_y;
	char	**map;

	dir_x = 0 * set->v->dir_x + (-1) * set->v->dir_y;
	dir_y = 1 * set->v->dir_x + 0 * set->v->dir_y;
	move_x = dir_x * speed;
	move_y = dir_y * speed;
	map = set->f->worldmap;
	if (map[(int)(set->v->pos_x - move_x)][(int)(set->v->pos_y)] == '0')
		set->v->pos_x -= move_x;
	if (map[(int)(set->v->pos_x)][(int)(set->v->pos_y - move_y)] == '0')
		set->v->pos_y -= move_y;
	return ;
}

void	move_a(t_ptr *set, double speed)
{
	double	dir_x;
	double	dir_y;
	double	move_x;
	double	move_y;
	char	**map;

	dir_x = 0 * set->v->dir_x + (-1) * set->v->dir_y;
	dir_y = 1 * set->v->dir_x + 0 * set->v->dir_y;
	move_x = dir_x * speed;
	move_y = dir_y * speed;
	map = set->f->worldmap;
	if (map[(int)(set->v->pos_x + move_x)][(int)(set->v->pos_y)] == '0')
		set->v->pos_x += move_x;
	if (map[(int)(set->v->pos_x)][(int)(set->v->pos_y + move_y)] == '0')
		set->v->pos_y += move_y;
	return ;
}
