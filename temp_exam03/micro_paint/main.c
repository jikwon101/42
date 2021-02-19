#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_zone {
	int width;
	int	height;
	char *matrice;
}		t_zone;

typedef struct s_shpae{

	char type;
	float x;
	float y;
	float width;
	float height;
	char color;
}				t_shape;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int	get_info(FILE *file, t_zone *zone)
{
	char *tmp;
	char color;
	int i;

	if (fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &color) == 3)
	{
		if ((zone->width < 1 || zone->width > 300)
			|| (zone->height < 1 || zone->height > 300))
			return (1);
		tmp = (char *)malloc(zone->width * zone->height);
		zone->matrice = tmp;
		if (!tmp)
			return (1);
		i = 0;
		while (i < zone->width * zone->height)
			zone->matrice[i++] = color;
		return (0);
	}
	return (1);
}

int	is_in_rect(float x, float y, t_shape *rect)
{
	if ((x< rect->x || rect->x + rect->width < x)
		|| (y < rect->y || rect->y + rect->height < y))
			return (0);
	if ((x - rect->x < 1.00000000 || rect->x + rect->width - x < 1.00000000)
		|| (y - rect->y < 1.00000000 || rect->y + rect->height - y < 1.00000000))
		return (2);
	return (1);
}
void	execute_one(t_shape *rect, t_zone *zone, int x, int y)
{
	int in;

	in = is_in_rect((float)x, (float)y, rect);
	if (in == 2
		|| (in == 1 && rect->type == 'R'))
		zone->matrice[x + y * zone->width] = rect->color;
	return ;

}
int	apply_op(t_shape *rect, t_zone *zone)
{
	int	i;
	int	j;
	
	if ((rect->width <= 0.00000000 || rect->height <= 0.00000000)
		|| (rect->type != 'R' && rect->type != 'r'))
		return (1);
	i = 0;
	while (i < zone->width)
	{
		j = 0;
		while (j < zone->height)
			execute_one(rect, zone, i, j++);
		i++;
	}
	return (0);
}
void	print_info(t_zone *zone)
{
	int	i;
	
	i = 0;
	while (i < zone->height)
	{
		printf("%.*s\n", zone->width, zone->matrice + i * zone->width);
		i++;
	}
}
int	execute(FILE *file)
{
	int	scan_ret;
	t_shape rect;
	t_zone	zone;

	if (!get_info(file, &zone))
	{
		scan_ret = fscanf(file, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.width, &rect.height, &rect.color);
		while (scan_ret == 6)
		{
				if (apply_op(&rect, &zone))
					return (1);
				scan_ret = fscanf(file, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.width, &rect.height, &rect.color);
		}
		if (scan_ret == -1)
		{
			print_info(&zone);
			return (0);
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	int len;
	FILE *file;

	if (ac == 2)
	{
		file = fopen(av[1], "r");
		if (file && !execute(file))
			return (0);
		len = ft_strlen("Error: Operation file corrupted\n");
		write(1, "Error: Operation file corrupted\n", len);
	}
	else
	{
		len = ft_strlen("Error: argument\n");
		write(1, "Error: argument\n", len);
	}
	return (1);
}
