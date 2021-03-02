#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

# define ERR 1
# define NOERR 0
# define err_arg "Error: argument\n"
# define err_file "Error: Operation file corrupted\n"
# define BORDER 1
# define INSIDE 2
# define LF 1.00000000
typedef struct s_zone
{
	int w;
	int h;
	char *mat;
}			t_zone;
typedef struct s_shape
{
	char type;
	float	x;
	float y;
	float  w;
	float h;
	char color;
}				t_shape;

int ft_strlen(char  *str)
{
	int len = 0;
	while (str[len])
		len++;
	return (len);
}

int get_info(FILE *file, t_zone *zone)
{
	char *temp;
	int i;
	char color;

	if (fscanf(file, "%d %d %c\n", &zone->w, &zone->h, &color) == 3)
	{
		if (zone->w <= 0 || zone->w > 300 || zone->h <= 0 || zone->h > 300)
			return (ERR);
		temp = (char *)malloc(zone->w * zone->h);
		zone->mat = temp;
		if (!zone->mat)
			return (ERR);
		i = 0;
		while (i < zone->w * zone->h)
			zone->mat[i++] = color;
		return (NOERR);
		
	}
	return (ERR);
}


int	is_in_rect(float x, float y, t_shape *rect)
{
	if (x < rect->x || x > rect->x + rect->w)
		return (0);
	if (y < rect->y || y > rect->y + rect->h)
		return (0);
	if ((x < rect->x + LF || x > rect->x + rect->w -LF)
		|| (y < rect->y + LF || y > rect->y + rect->h -LF))
		return (BORDER);
	return (INSIDE);
}
void execute_one(t_shape *rect, t_zone *zone, int x, int y)
{
	int in;

	in = is_in_rect((float)x, (float)y, rect);
	if (in == BORDER 
		|| (in == INSIDE && rect->type == 'R'))
		zone->mat[x + y * zone->w] = rect->color;
	return ;
}
int	apply_op(t_zone *zone, t_shape *rect)
{
	if (rect->w <= 0.00000000 || rect->h <= 0.00000000)
		return (ERR);
	if (rect->type != 'R' && rect->type != 'r')
		return (ERR);
	int i;
	int j;

	i = 0;
	while (i < zone->w)
	{
		j = 0;
		while (j < zone->h)
			execute_one(rect, zone, i, j++);
		i++;
	}
	return (NOERR);
}
void print_info(t_zone *zone)
{
	int i = 0;
	char *temp;

	temp = zone->mat;
	while (i < zone->h)
	{
		write(1, temp, zone->w);
		write(1, "\n", 1);
		temp = temp + zone->w;
		i++;
	}
	free(zone->mat);
	return ;
}

int execute(FILE *file)
{
	t_zone zone;
	t_shape rect;
	int res;

	if (get_info(file, &zone) == ERR)
		return (ERR);
	res = fscanf(file, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.w, &rect.h, &rect.color);
	while (res == 6)
	{
		if (apply_op(&zone, &rect) == ERR)
			break ;
		res = fscanf(file, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.w, &rect.h, &rect.color);
	}
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
	FILE *file;

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

