/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:01:09 by jikwon            #+#    #+#             */
/*   Updated: 2020/08/05 18:23:15 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	cal_sidedist(t_ptr *set, t_dist *d)
{
	if (d->raydir_x < 0)
	{
		d->step_x = -1;
		d->sidedist_x = (set->v->pos_x - d->map_x) * (d->deltadist_x);
	}
	else
	{
		d->step_x = 1;
		d->sidedist_x = (d->map_x + 1.0 - set->v->pos_x) * (d->deltadist_x);
	}
	if (d->raydir_y < 0)
	{
		d->step_y = -1;
		d->sidedist_y = (set->v->pos_y - d->map_y) * (d->deltadist_y);
	}
	else
	{
		d->step_y = 1;
		d->sidedist_y = (d->map_y + 1.0 - set->v->pos_y) * (d->deltadist_y);
	}
	return ;
}

void	move_map(t_dist *d, char **worldmap)
{
	if (d->sidedist_x < d->sidedist_y)
	{
		d->sidedist_x += d->deltadist_x;
		d->map_x += d->step_x;
		d->side = 0;
	}
	else
	{
		d->sidedist_y += d->deltadist_y;
		d->map_y += d->step_y;
		d->side = 1;
	}
	if (worldmap[d->map_x][d->map_y] == '1')
		d->hit = 1;
	return ;
}

void	init_wallval1(t_ptr *set, t_dist *d, t_wall *wl, int h)
{
	if (d->side == 0)
		wl->perp =
				(d->map_x - set->v->pos_x + (1 - d->step_x) / 2) / d->raydir_x;
	else
		wl->perp =
				(d->map_y - set->v->pos_y + (1 - d->step_y) / 2) / d->raydir_y;
	wl->lineheight = (int)(set->f->y_size / wl->perp);
	wl->draw_s = -(wl->lineheight) / 2 + h / 2;
	if (wl->draw_s < 0)
		wl->draw_s = 0;
	wl->draw_e = (wl->lineheight) / 2 + (set->f->y_size) / 2;
	if (wl->draw_e >= h)
		wl->draw_e = h - 1;
	return ;
}

void	init_wallval2(t_ptr *set, t_dist *d, t_wall *wl, int h)
{
	if (d->side == 0)
		wl->wall_x = set->v->pos_y + wl->perp * d->raydir_y;
	else
		wl->wall_x = set->v->pos_x + wl->perp * d->raydir_x;
	wl->wall_x -= floor(wl->wall_x);
	wl->tex_x = (int)(wl->wall_x * (double)(TEX_W));
	if (d->side == 0 && d->raydir_x > 0)
		wl->tex_x = TEX_W - wl->tex_x - 1;
	if (d->side == 1 && d->raydir_y < 0)
		wl->tex_x = TEX_W - wl->tex_x - 1;
	wl->step = 1.0 * TEX_H / (wl->lineheight);
	wl->tex_pos = (wl->draw_s - h / 2 + wl->lineheight / 2) * (wl->step);
	return ;
}

void	draw_buffer(t_ptr *set, t_dist *d, t_wall *wl, t_image *i)
{
	int	y;
	int	index;

	y = -1;
	while (++y < wl->draw_s)
		(i->img_data)[d->x + y * (set->f->x_size)] = (set->f->color)[C];
	while (y < wl->draw_e)
	{
		wl->tex_y = (int)(wl->tex_pos) & (TEX_H - 1);
		(wl->tex_pos) += wl->step;
		index = check_color(d->raydir_x, d->raydir_y, d->side);
		i->color = (set->tex)[index][TEX_H * wl->tex_y + wl->tex_x];
		if (d->side == 1)
			i->color = (i->color << 1) & 8355711;
		(i->img_data)[d->x + y * (set->f->x_size)] = i->color;
		y++;
	}
	while (y < set->f->y_size)
	{
		(i->img_data)[d->x + y * (set->f->x_size)] = (set->f->color)[F];
		y++;
	}
	(i->zbuffer)[d->x] = wl->perp;
	return ;
}
