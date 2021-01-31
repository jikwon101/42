/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveimage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 17:40:18 by jikwon            #+#    #+#             */
/*   Updated: 2020/08/05 15:31:35 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	init_bmpval(t_bmp *bmp, int w, int h)
{
	bmp->pixcount = (unsigned int)(w * h);
	bmp->bufsize = (unsigned int)(w * h * 4);
	bmp->total_size = bmp->bufsize + 54;
	bmp->pix_offset = 54;
	bmp->header_size = 40;
	bmp->imagewidth = w;
	bmp->imageheight = h;
	bmp->color_planes = 1;
	bmp->bpp = 32;
	bmp->total_colors = 0;
	ft_memset(bmp->header, 0, 54);
	return ;
}

void	fill_bmpheader(t_bmp *bmp)
{
	(bmp->header)[0] = 'B';
	(bmp->header)[1] = 'M';
	ft_memcpy(&((bmp->header)[2]), &(bmp->total_size), sizeof(unsigned int));
	ft_memcpy(&((bmp->header)[10]), &(bmp->pix_offset), sizeof(unsigned int));
	ft_memcpy(&((bmp->header)[14]), &(bmp->header_size), sizeof(unsigned int));
	ft_memcpy(&((bmp->header)[18]), &(bmp->imagewidth), sizeof(int));
	ft_memcpy(&((bmp->header)[22]), &(bmp->imageheight), sizeof(int));
	ft_memcpy(&((bmp->header)[26]), &(bmp->color_planes), sizeof(short));
	ft_memcpy(&((bmp->header)[28]), &(bmp->bpp), sizeof(short));
	ft_memcpy(&((bmp->header)[34]), &(bmp->bufsize), sizeof(short));
	ft_memcpy(&((bmp->header)[38]), &(bmp->compression), sizeof(int));
	ft_memcpy(&((bmp->header)[46]), &(bmp->total_colors), sizeof(int));
	return ;
}

void	transform_bmp(int *src, int *new, int w, int h)
{
	int	x;
	int	y;

	x = 0;
	while (x < w)
	{
		y = 0;
		while (y < h)
		{
			new[x + y * w] = src[x + (h - 1 - y) * w];
			y++;
		}
		x++;
	}
	return ;
}

void	write_file(t_bmp bmp, int *result, int w, int h)
{
	int	fd;

	fd = open("./screnshot.bmp", O_RDWR | O_CREAT, 0644);
	write(fd, bmp.header, 54);
	write(fd, result, w * h * 4);
	close(fd);
	return ;
}

int		save_screen(t_ptr *set, char *option, int w, int h)
{
	t_image	*i;
	t_bmp	bmp;
	int		*result;

	if (ft_strcmp(option, "--save") != 0)
		return (0);
	if ((i = (t_image *)malloc(sizeof(t_image) * 1)) == NULL)
		return (0);
	if (!fill_img_buffer(set, i))
		return (0);
	if ((result = (int *)malloc(sizeof(int) * (w * h))) == NULL)
		return (0);
	init_bmpval(&bmp, w, h);
	fill_bmpheader(&bmp);
	transform_bmp(i->img_data, result, w, h);
	write_file(bmp, result, w, h);
	free(i->zbuffer);
	free(i);
	free(result);
	free_all(set);
	return (1);
}
