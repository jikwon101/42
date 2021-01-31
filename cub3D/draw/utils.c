/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:01:09 by jikwon            #+#    #+#             */
/*   Updated: 2020/08/11 20:18:18 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	sort_sprites(int *arr_order, double *arr_dist, int amount)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < amount)
	{
		j = 0;
		while (j < amount - 1)
		{
			if (arr_dist[j] < arr_dist[j + 1])
			{
				temp = arr_dist[j];
				arr_dist[j] = arr_dist[j + 1];
				arr_dist[j + 1] = temp;
				temp = arr_order[j];
				arr_order[j] = arr_order[j + 1];
				arr_order[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return ;
}

int		init_sparray(t_ptr *set, t_spimage *si)
{
	int		i;
	int		cnt;
	double	temp;

	i = 0;
	cnt = set->f->num_sp;
	if ((si->order = (int *)malloc(sizeof(int) * cnt)) == NULL)
		return (0);
	if ((si->dist = (double *)malloc(sizeof(double) * cnt)) == NULL)
		return (0);
	while (i < cnt)
	{
		(si->order)[i] = i;
		temp = pow((set->v->pos_x - (set->s)[i].x), 2);
		(si->dist)[i] = temp + pow((set->v->pos_y - (set->s)[i].y), 2);
		i++;
	}
	sort_sprites((si->order), (si->dist), cnt);
	return (1);
}

int		check_color(double raydir_x, double raydir_y, int side)
{
	if (raydir_x < 0 && raydir_y >= 0)
		return ((side == 0) ? N : E);
	else if (raydir_x < 0 && raydir_y < 0)
		return ((side == 0) ? N : W);
	else if (raydir_x >= 0 && raydir_y < 0)
		return ((side == 0) ? S : W);
	return ((side == 0) ? S : E);
}

int		init_imageval(t_ptr *set, t_image *i)
{
	int	w;
	int	h;

	w = set->f->x_size;
	h = set->f->y_size;
	i->img = mlx_new_image(set->mlx, w, h);
	i->img_data =
			(int *)mlx_get_data_addr(i->img, &(i->bits), &(i->lsize), &(i->ed));
	if (((i->zbuffer) = (double *)malloc(sizeof(double) * (w + 1))) == NULL)
		return (0);
	return (1);
}

void	init_distval(t_ptr *set, t_dist *d, int x)
{
	int	w;

	w = set->f->x_size;
	d->camera_x = 2 * x / (double)w - 1;
	d->raydir_x = set->v->dir_x + set->v->plane_x * (d->camera_x);
	d->raydir_y = set->v->dir_y + set->v->plane_y * (d->camera_x);
	d->map_x = (int)(set->v->pos_x);
	d->map_y = (int)(set->v->pos_y);
	if (d->raydir_y == 0)
		d->deltadist_x = 0;
	else
		d->deltadist_x = (d->raydir_x == 0) ? 1 : fabs(1 / d->raydir_x);
	if (d->raydir_x == 0)
		d->deltadist_y = 0;
	else
		d->deltadist_y = (d->raydir_y == 0) ? 1 : fabs(1 / d->raydir_y);
	d->hit = 0;
	d->x = x;
	return ;
}
