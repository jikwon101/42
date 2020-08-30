/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 13:09:12 by jikwon            #+#    #+#             */
/*   Updated: 2020/08/30 13:19:22 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define KEY_PRESS 2
# define CLOSE 17
# include <math.h>
# include <stdio.h>
# include "mlx.h"
# include "./read_file/read_file.h"

typedef struct	s_ptr
{
	void			*win;
	void			*mlx;
	int				*tex[6];
	struct s_var	*v;
	struct s_file	*f;
	struct s_sprite	*s;
}				t_ptr;

typedef struct	s_var
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_var;

typedef struct	s_image
{
	void			*img;
	int				bits;
	int				lsize;
	int				ed;
	int				*img_data;
	int				img_width;
	int				img_height;
	unsigned int	color;
	double			*zbuffer;
}				t_image;

typedef struct	s_sprite
{
	double	x;
	double	y;
}				t_sprite;

typedef struct	s_dist
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		x;
}				t_dist;

typedef struct	s_wall
{
	double	perp;
	int		lineheight;
	int		draw_s;
	int		draw_e;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
}				t_wall;

int				key_press(int keycode, t_ptr *set);
int				ft_close(t_ptr *set);
int				init_imageval(t_ptr *set, t_image *i);
void			init_distval(t_ptr *set, t_dist *d, int x);
void			cal_sidedist(t_ptr *set, t_dist *d);
void			move_map(t_dist *d, char **worldmap);
void			init_wallval1(t_ptr *set, t_dist *d, t_wall *wl, int h);
void			init_wallval2(t_ptr *set, t_dist *d, t_wall *wl, int h);
void			draw_buffer(t_ptr *set, t_dist *d, t_wall *wl, t_image *i);
int				draw_sprite(t_ptr *set, t_image *i);
int				save_screen(t_ptr *set, char *option, int w, int h);
int				fill_img_buffer(t_ptr *set, t_image *i);
int				init_sprite(t_ptr *set);
int				init_tex(t_ptr *set);
int				init_loc(t_ptr *set, t_file *file);
void			free_all(t_ptr *set);
#endif
