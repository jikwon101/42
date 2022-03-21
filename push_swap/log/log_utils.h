/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:29:22 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/25 02:29:26 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_UTILS_H
# define LOG_UTILS_H

# include "../include/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_history
{
	char				*command;
	struct s_history	*next;
	struct s_history	*prev;
}				t_history;

typedef struct s_log
{
	t_history	*last;
}				t_log;

void		remove_history(t_log *log);
int			isopposite(char *s1, char *s2);
int			ispair(char *s1, char *s2);
void		add_firstlog(t_log *log, char *cmd);
t_history	*make_newhistory(char *cmd);

#endif
