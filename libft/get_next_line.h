/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 20:28:27 by jikwon            #+#    #+#             */
/*   Updated: 2020/06/23 22:26:20 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		ft_len(char *str);
void	ft_strlcpy(char *dst, char *src, int size);
char	*ft_strdup(char *str, int size);
char	*ft_strchr(char *str, char target);
char	*ft_strjoin(char *s1, char *s2);
int		to_line(char **line, char *w_nl, char **fd_set, char *temp_buff);
int		get_next_line(int fd, char **line);

#endif
