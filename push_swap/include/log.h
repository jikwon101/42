/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:29:10 by jikwon            #+#    #+#             */
/*   Updated: 2021/07/25 02:29:12 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

# include "log_utils.h"

# define INIT 0
# define ADD 1
# define PRINT 2
# define CLEAR 3
# define NOCMD NULL

void	control_log(int option, char *cmd);

#endif
