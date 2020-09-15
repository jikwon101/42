/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:53:32 by jikwon            #+#    #+#             */
/*   Updated: 2020/09/15 12:12:51 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H
#include <unistd.h>

size_t			ft_strlen(char *str);
char 			*ft_strcpy(char *dst, const char *scr);
int 			ft_strcmp(const char *s1, const char *s2);
ssize_t 		ft_write(int fd, const void *buf, size_t nbyte);
ssize_t 		ft_read(int fd, void *buf, size_t nbyte);
char 			*ft_strdup(const char *s1);

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

int				ft_atoi_base(char *str, char *base);
void			ft_list_push_front(t_list **begin_list, void *data);
int				ft_list_size(t_list *begin_list);
void			ft_list_sort(t_list **begin_list, int (*cmp)());
int				ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

#endif
