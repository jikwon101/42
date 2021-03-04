/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:40:29 by jikwon            #+#    #+#             */
/*   Updated: 2021/03/04 18:05:01 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "two.h"

int		clean_sema(int code)
{
	sem_unlink("s_fork");
	sem_unlink("s_write");
	sem_unlink("s_state");
	sem_close(g_info.s_fork);
	sem_close(g_info.s_write);
	sem_close(g_info.s_state);
	return (code);
}
