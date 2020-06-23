/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:00:46 by jikwon            #+#    #+#             */
/*   Updated: 2020/06/23 22:49:58 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

#define CUB3D_H
#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include "./libft_bonus/libft.h"
#define WIN_WIDTH 800
#define WIN_HEIGHT 600
# define EV_KEY_PRESS 2
# define EV_KET_RELEASE 3
# define EV_MOUSE_PRESS 4
# define EV_MOUSE_RELEASE 5
# define EV_MOUSE_MOVE 6

#define MS_kEY_PRESS 1L<<0
#define MS_KEY_RELEASE 1L<<1
#define MS_MOUSE_PRESS 1L<<2
#define MS_MOUSE_RELEASE 1L<<3
#define MS_MOUSE_MOVE 1L<<6

typedef struct s_ptr
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	void *img_arr;
}				t_ptr;

typedef struct s_info
{
	int x_Rsize;
	int y_Rsize;
	char *path_NO;
	char *path_SO;
	char *path_EA;
	char *path_WE;
	char *path_S;
	int color_F;
	int color_C;

	char **worldmap;
}				t_info;

#endif
