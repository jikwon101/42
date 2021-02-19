#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

# define ERR 1
# define NOERR 0
# define err_arg "Error: argument\n"
# define err_file "Error: file\n"
# define BORDER 1
# define INSIDE 2

typedef struct s_zone
{
	int w;
	int h;
	char *mat;
} t_zone;

typedef struct s_shape
{
	char type;
	float x;
	float y;
	float r;
	char color;
}	t_shape;

int ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return (len);
}
int	get_info(FILE *file, t_zone *zone)
{
	char *tmp;
	char color;
	int i;

	if (fscanf(file, "%d %d %c\n", &zone->w, &zone->h, &color) != 3)
		return (ERR);
	if (zone->w < 0 || zone->w > 300 || zone->h < 0 || zone->h > 300)
		return (ERR);
	tmp = (char *)malloc(zone->w * zone->h);
	zone->mat = tmp;
	if (!zone->mat)
		return (ERR);
	i = 0;
	while (i < zone->w  * zone->h)
		zone->mat[i++] = color;
	return (NOERR);
}

float sq_dist(float x1, float y1, float x2, float y2)
{
	float dist_x;
	float dist_y;

	dist_x = (x1 - x2) * (x1 - x2);
	dist_y = (y1 - y2) * (y1 - y2);
	return (dist_x + dist_y);
}

int	is_in_circle(float x, float y, t_shape *circle)
{
	float dist;
	float dist_sqrt;

	dist_sqrt = sqrtf(sq_dist(x, y, circle->x, circle->y));
	dist = dist_sqrt - circle->r;
	if (dist <= 0.00000000)
	{
		if (dist <= -1.00000000)
			return (INSIDE);
		return (BORDER);
	}
	return (0);
}
void	execute_one(t_shape *circle, t_zone *zone, int x, int y)
{
	int in;

	in = is_in_circle((float)x, (float)y, circle);
	if (in == BORDER
		|| (in == INSIDE && circle->type == 'C'))
		zone->mat[x + y * zone->w] = circle->color;
	return ;
}
int apply_op(t_shape *circle, t_zone *zone)
{
	if (circle->r <= 0.00000000)
		return (ERR);
	if (circle->type != 'C' && circle->type != 'c')
		return (ERR);
	int i;
	int j;
	i = 0;
	while (i < zone->w)
	{
		j = 0;
		while (j < zone->h)
			execute_one(circle, zone, i, j++);
		i++;
	}
	return (NOERR);
}
void	 print_info(t_zone *zone)
{
	int i = 0;

	while (i < zone->h)
	{
		printf("%.*s\n", zone->w, zone->mat + zone->w * i);
		i++;
	}
	free(zone->mat);
}

int	execute(FILE *file)
{
	t_shape circle;
	t_zone zone;
	int res;

	if (get_info(file, &zone) == ERR)
		return (ERR);
	res = fscanf(file, "%c %f %f %f %c\n",&circle.type, &circle.x, &circle.y, &circle.r, &circle.color );
	while (res == 5)
	{
		if (apply_op(&circle, &zone) == ERR)
			break;
		res = fscanf(file, "%c %f %f %f %c\n",&circle.type, &circle.x, &circle.y, &circle.r, &circle.color );
	}
	fclose(file);
	if (res == -1)
	{
		print_info(&zone);
		return (NOERR);
	}
	if (zone.mat)
		free(zone.mat);
	return (ERR);
}

int main(int ac, char **av)
{
	FILE  *file;
	
	if (ac == 2)
	{
		file = fopen(av[1], "r");
		if (file && execute(file) == NOERR)
			return (NOERR);
		write(1, err_file, ft_strlen(err_file));
	}
	else
		write(1, err_arg, ft_strlen(err_arg));
	return (ERR);
}
