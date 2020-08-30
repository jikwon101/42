/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:01:09 by jikwon            #+#    #+#             */
/*   Updated: 2020/08/13 15:28:11 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_dir(t_ptr *set, int count)
{
	int		i;
	double	old_dirx;
	double	old_planex;

	i = 0;
	while (i < count)
	{
		old_dirx = set->v->dir_x;
		set->v->dir_x = 0 * set->v->dir_x + (-1) * set->v->dir_y;
		set->v->dir_y = 1 * old_dirx + 0 * set->v->dir_y;
		old_planex = set->v->plane_x;
		set->v->plane_x = 0 * set->v->plane_x + (-1) * set->v->plane_y;
		set->v->plane_y = old_planex + 0 * set->v->plane_y;
		i++;
	}
	return ;
}

void	init_dir(t_ptr *set, char option)
{
	set->v->dir_x = -1;
	set->v->dir_y = 0;
	set->v->plane_x = 0;
	set->v->plane_y = 0.66;
	if (option == 'W')
		rotate_dir(set, 1);
	else if (option == 'S')
		rotate_dir(set, 2);
	else if (option == 'E')
		rotate_dir(set, 3);
	return ;
}

int		init_loc(t_ptr *set, t_file *file)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	if ((set->v = (t_var *)malloc(sizeof(t_var))) == 0)
		return (0);
	while ((file->worldmap)[i])
	{
		j = 0;
		while ((file->worldmap)[i][j])
		{
			temp = (file->worldmap)[i][j];
			if (temp == 'W' || temp == 'S' || temp == 'E' || temp == 'N')
			{
				set->v->pos_x = (double)i + 0.01;
				set->v->pos_y = (double)j + 0.01;
				init_dir(set, temp);
				(file->worldmap)[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		init_tex(t_ptr *set)
{
	t_image	i;
	int		index;
	void	*img[6];

	index = 0;
	while (index < 5)
	{
		img[index] = mlx_xpm_file_to_image(set->mlx,
						(set->f->path)[index], &(i.img_width), &(i.img_height));
		(set->tex)[index] = (int *)mlx_get_data_addr(img[index],
						&(i.bits), &(i.lsize), &(i.ed));
		index++;
	}
	(set->tex)[index] = NULL;
	return (1);
}

int		init_sprite(t_ptr *set)
{
	int	i;
	int	j;
	int	index;

	index = 0;
	if ((set->s =
			(t_sprite *)malloc(sizeof(t_sprite) * (set->f->num_sp))) == NULL)
		return (0);
	i = 0;
	while ((set->f->worldmap)[i])
	{
		j = 0;
		while ((set->f->worldmap)[i][j])
		{
			if ((set->f->worldmap)[i][j] == '2')
			{
				(set->s)[index].x = i;
				(set->s)[index].y = j;
				index++;
			}
			j++;
		}
		i++;
	}
	return (1);
}
