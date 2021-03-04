/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_destroy_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 20:40:37 by jikwon            #+#    #+#             */
/*   Updated: 2021/03/04 14:06:02 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

void	finish_threads(t_philo *ph_set)
{
	int i;

	i = 0;
	while (i < g_info.nbr_of_philo)
		pthread_mutex_destroy(&g_info.m_forks[i++]);
	pthread_mutex_destroy(&g_info.m_write);
	pthread_mutex_destroy(&g_info.m_state);
	free(ph_set);
	free(g_info.m_forks);
}
