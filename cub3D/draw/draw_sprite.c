/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:01:09 by jikwon            #+#    #+#             */
/*   Updated: 2020/08/04 15:57:31 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	init_spval1(t_ptr *set, t_spimage *s, int cnt)
{
	int		w;
	int		h;
	t_var	*v;

	w = set->f->x_size;
	h = set->f->y_size;
	v = set->v;
	s->sprite_x = (set->s)[(s->order)[cnt]].x - v->pos_x;
	s->sprite_y = (set->s)[(s->order)[cnt]].y - v->pos_y;
	s->inv_dev = 1.0 / (v->plane_x * v->dir_y - v->dir_x * v->plane_y);
	s->trans_x = s->inv_dev * (v->dir_y * s->sprite_x - v->dir_x * s->sprite_y);
	s->trans_y = s->inv_dev *
			(-v->plane_y * s->sprite_x + v->plane_x * s->sprite_y);
	s->sprite_screen_x = (int)((w / 2) * (1 + s->trans_x / s->trans_y));
	s->vmove_screen = (int)(VMOVE / s->trans_y);
	s->sp_height = abs((int)(h / s->trans_y)) / V_DIV;
	return ;
}

void	init_spval2(t_ptr *set, t_spimage *s)
{
	int	w;
	int	h;

	w = set->f->x_size;
	h = set->f->y_size;
	s->draw_start_y = -s->sp_height / 2 + h / 2 + s->vmove_screen;
	if (s->draw_start_y < 0)
		s->draw_start_y = 0;
	s->draw_end_y = s->sp_height / 2 + h / 2 + s->vmove_screen;
	if (s->draw_end_y >= h)
		s->draw_end_y = h - 1;
	s->sp_width = abs((int)(h / s->trans_y)) / U_DIV;
	s->draw_start_x = -s->sp_width / 2 + s->sprite_screen_x;
	if (s->draw_start_x < 0)
		s->draw_start_x = 0;
	s->draw_end_x = s->sp_width / 2 + s->sprite_screen_x;
	if (s->draw_end_x >= w)
		s->draw_end_x = w - 1;
	return ;
}

void	init_drawspval(int *d, int y, t_spimage *s, t_ptr *set)
{
	int	w;
	int	h;

	w = set->f->x_size;
	h = set->f->y_size;
	*d = (y - s->vmove_screen) * 256 - h * 128 + s->sp_height * 128;
	s->tex_y = (((*d) * TEX_H) / s->sp_height) / 256;
	s->color = (set->tex)[I][TEX_W * s->tex_y + s->tex_x];
	return ;
}

void	draw_spbuffer(t_ptr *set, t_spimage *s, t_image *i)
{
	int	x;
	int	y;
	int d;
	int	w;
	int	h;

	w = set->f->x_size;
	h = set->f->y_size;
	x = s->draw_start_x - 1;
	while (++x < s->draw_end_x)
	{
		s->tex_x = (int)(256 * (x - (-s->sp_width / 2 + s->sprite_screen_x))
		* TEX_W / s->sp_width) / 256;
		if (s->trans_y > 0 && x > 0 && x < w && s->trans_y < i->zbuffer[x])
		{
			y = s->draw_start_y - 1;
			while (++y < s->draw_end_y)
			{
				init_drawspval(&d, y, s, set);
				if ((s->color & 0xffffff) != 0)
					i->img_data[x + y * w] = s->color;
			}
		}
	}
	return ;
}

int		draw_sprite(t_ptr *set, t_image *i)
{
	t_spimage	si;
	int			cnt;

	cnt = 0;
	if (!(init_sparray(set, &si)))
		return (0);
	while (cnt < set->f->num_sp)
	{
		init_spval1(set, &si, cnt);
		init_spval2(set, &si);
		draw_spbuffer(set, &si, i);
		cnt++;
	}
	free(si.order);
	free(si.dist);
	return (1);
}
