/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_destroy_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 20:40:37 by jikwon            #+#    #+#             */
/*   Updated: 2021/02/25 20:41:14 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

int		make_threads(t_philo *ph_set)
{
	int			i;
	pthread_t	full;

	i = 0;
	while (i < g_info.nbr_of_philo)
	{
		ph_set[i].last_meal = get_time();
		ph_set[i].t_start = ph_set[i].last_meal;
		pthread_create(&ph_set[i].thread, NULL, routine, &ph_set[i]);
		usleep(50);
		i++;
	}
	pthread_create(&full, NULL, &check_full, ph_set);
	pthread_detach(full);
	i = 0;
	while (i < g_info.nbr_of_philo)
		pthread_join(ph_set[i++].thread, NULL);
	return (NOERR);
}

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
