/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:05:43 by jikwon            #+#    #+#             */
/*   Updated: 2021/03/04 17:39:16 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three.h"

int		clean_sema(int code)
{
	sem_unlink("s_write");
	sem_unlink("s_eat");
	sem_unlink("s_death");
	sem_unlink("s_full");
	return (code);
}
