/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 11:38:50 by jikwon            #+#    #+#             */
/*   Updated: 2020/06/23 13:41:02 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#define mapWidth 6
#define mapHeight 6
#define screenWidth 640
#define screenHeight 480

int worldMap[mapWidth][mapHeight]
{
	{1, 1, 1, 1, 1, 1},
	{1, 0, 0, 1, 0, 1},
	{1, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1}
};

typedef struct s_info
{
	void *mlx;
	void *win;
	void *img;
	int *data_arr;
}				c_info;
int main(int argc, char **argv)
{
	double posX = 2;
	double posY = 0;
	double dir X = -1;
	double dir Y = 0;
	double planeX = 0
	double planeY = 0.66;
	double time = 0;
	double old:Time = 0;

	c_info *ptr_info;
	ptr_info = (c_info *)malloc((sizeof(c _info)));
	ptr_info->mlx = mlx_init();
	ptr_info->win = mlx_new_window(ptr_info->mlx, screenWidth, screenHeight, "TEST");
	:
	ptr_info->img = mlx_new_image(ptr_info->mlx, screenWidth, screenHeight);
	ptr_info->data_arr = (int *)mlx_get_data_addr(ptr_info->img, 32, screenWidth * 4 , 0);
	while (1)
	{
		for (int x = 0 ; x < w  ; x++)
		{
			double cameraX = 2 * x / (double)w  - 1;
			double ray8DirX = dirX * planeX * cameraX;
			double rayDirY = dirY * planeY * cameraX;
			int mapX = (int)posX;
			int mapY = (int)posY;

			double sideDistX;
			double sideDistY;
			double deltaDistX = fabs(1 / rayDirX);
			double deltaDistY = fabs(1 / rayDirY);
			double perpWallDist;
a
			int stepX;
			int stepY;
			int hit = 0;
			int side;
			if (rayDirX < 0){
				stepX = -1;
				sideDistX = (posX - mapX) * deltaDistX;}
			else{
				stepX = 1;
				sideDistX = (mapX + 1.0 - posX) * deltaDistX;}
			if (rayDirY < 0){
				stepY = -1;
				sideDistY = (posY - mapY) * deltaDistY;}
			else{
				stepY = 1;
				sideDistY = (mapY + 1.0 - posY) * deltaDistY;}
			while (hit == 0){
				if (sideDistX < sideDistY){
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;}
				else{
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;}}
			if (side == 0)
				perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
			else
				perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;
				if (worldMap[mapX][mapY] > 0)
					hit = 1;}
			int lineHeight = (int)(h / perpWallDist);
			int drawStart = -lineHeight / 2 + h / 2;
			if (drawStart < 0)
				drawStart = 0;
			int drawEnd = lineHeight / 2 + h / 2;
			if (drawEnd < 0)
				drawEnd = 0;
		}
	}
}
