#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ERR1 "Error:argument\n"
#define ERR2 "Error:Operation file corrupted\n"

int ft_strlen(char *str)
{
	int i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_perror(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

int	check_boundary(float x, float y, float c_posx, float c_posy, float c_radius)
{
	float dist;
	
	dist = sqrtf(powf(c_posx - x, 2) + powf(c_posy - y, 2));
	if (dist <= c_radius)
	{
		if (c_radius - dist < 1.0000000)
			return (1);		//Border
		return (2);			//inside
	}
	return (0);				//outside
}

int main(int argc, char *argv[])
{
	FILE	*file;
	char	*paper;
	int		bg_width;
	int		bg_height;
	char	bg_ch;

	int		read;
	int		x, y;
	int		pos;

	char	c_type;
	float	c_xpos;
	float	c_ypos;
	float	c_radius;
	char	c_color;

	if (argc != 2)
		return (ft_perror(ERR1));
	if (!(file = fopen(argv[1], "r")) ||
		fscanf(file, "%d %d %c\n", &bg_width, &bg_height, &bg_ch) != 3 ||
		!(bg_width > 0 && bg_width <= 300 && bg_height > 0 && bg_height <= 300) ||
		!(paper = (char *)malloc(sizeof(char) * bg_width * bg_height)))
		return (ft_perror(ERR2));
	memset(paper, bg_ch, bg_width * bg_height);
	while((read = fscanf(file, "%c %f %f %f %c\n", &c_type, &c_xpos, &c_ypos, &c_radius, &c_color)) == 5)
	{
		if(!(c_radius > 0) || !(c_type == 'c' || c_type == 'C'))
			break;
		y = 0;
		while (y < bg_height)
		{
			x = 0;
			while (x < bg_width)
			{
				pos = check_boundary((float)x, (float)y, c_xpos, c_ypos, c_radius);
				if (pos == 1 || (pos == 2 && c_type == 'C'))
					paper[y * bg_width + x] = c_color;
				x++;
			}
			y++;
		}
	}
	if (read != -1)
	{
		printf("break in while loop");
		free(paper);
		return (ft_perror(ERR2));
	}
	y = 0;
	while (y < bg_height)
	{
		write(1, paper + y * bg_width, bg_width);
		write(1, "\n", 1);
		y++;
	}
	free(paper);
	fclose(file);
	return (0);
}
