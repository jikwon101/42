/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 14:27:28 by jikwon            #+#    #+#             */
/*   Updated: 2020/07/31 15:28:13 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "../cub3d.h"

# define TEX_W 64
# define TEX_H 64
# define U_DIV 1
# define V_DIV 1
# define VMOVE 0.0

typedef struct	s_spimage
{
	int				*order;
	double			*dist;
	double			sprite_x;
	double			sprite_y;
	double			inv_dev;
	double			trans_x;
	double			trans_y;
	int				sprite_screen_x;
	int				vmove_screen;
	int				sp_height;
	int				draw_start_y;
	int				draw_end_y;
	int				sp_width;
	int				draw_start_x;
	int				draw_end_x;
	int				tex_x;
	int				tex_y;
	unsigned int	color;
}				t_spimage;

typedef struct	s_bmp
{
	char			header[54];
	unsigned int	pixcount;
	unsigned int	bufsize;
	unsigned int	total_size;
	unsigned int	pix_offset;
	unsigned int	header_size;
	int				imagewidth;
	int				imageheight;
	short			color_planes;
	short			bpp;
	int				compression;
	int				total_colors;
}				t_bmp;

void			init_spval1(t_ptr *set, t_spimage *s, int cnt);
void			init_spval2(t_ptr *set, t_spimage *s);
void			init_frawspval(int *d, int y, t_spimage *s, t_ptr *set);
void			draw_spbuffer(t_ptr *set, t_spimage *s, t_image *i);

void			sort_sprites(int *arr_order, double *arr_dist, int amount);
int				init_sparray(t_ptr *set, t_spimage *si);
int				check_color(double raydir_x, double raydir_y, int side);
#endif
