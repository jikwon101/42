/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 22:00:02 by jikwon            #+#    #+#             */
/*   Updated: 2020/07/31 00:34:12 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int				ft_isdigit(int c);
int				ft_atoi(const char *str);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *destination, const void *source, size_t num);
char			*ft_strdup(const char *s);
char			*ft_strchr(const char *str, int c);
size_t			ft_strlen(const char *string);
char			**ft_split(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
int				ft_strcmp(char *s1, char *s2);
int				get_next_line(int fd, char **line);
#endif
