/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 11:34:12 by jikwon            #+#    #+#             */
/*   Updated: 2020/07/31 11:58:30 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_FILE_H
# define READ_FILE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define N 0
# define S 1
# define E 2
# define W 3
# define I 4
# define F 0
# define C 1

typedef struct	s_file
{
	int				x_size;
	int				y_size;
	int				num_sp;
	char			*path[6];
	char			**worldmap;
	unsigned int	color[2];
}				t_file;

t_file			*init_t_file(void);
int				read_file(char *file_name, t_file *f_set);
int				check_elem(char **line, t_file *f_set);
int				last_check(t_file *f_set, char **doc);

int				set_size(t_file *f_set, char **elem);
int				set_path(t_file *tf_set, char **elem, int option);
int				set_color(t_file *f_set, char **elem, int option);
int				set_map(char **doc, t_file *f_set);

char			**check_map(char *doc);
int				is_wrapped(char **t_map);
int				check_wall(char **t_map, int x, int y);
int				is_wall_v(char **t_map, int x, int y);
int				is_wall_p(char **t_map, int x, int y);

int				is_num(char *str);
int				ft_cntchr(char *str, char c);
char			**check_color_elem(char **elem);
int				ft_is_blank(char *line);

int				ft_is_map(char *line);
void			ft_temp_map(char **doc, char *line);
int				ft_lenx(char **t_map);
int				ft_check_sp(char *doc);

void			ft_free_array(char **set);
void			free_t_file(t_file *f_set);
#endif
