/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 20:38:31 by jikwon            #+#    #+#             */
/*   Updated: 2021/02/25 22:41:51 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

void	*check_death(void *arg)
{
	t_philo		*one;
	int64_t		time;

	one = (t_philo *)arg;
	while (g_info.state != DIED)
	{
		time = get_time();
		if (time - one->last_meal > g_info.t_die)
		{
			pthread_mutex_lock(&g_info.m_state);
			print_msg("is died\n", one, time);
			g_info.state = DIED;
			pthread_mutex_unlock(&g_info.m_state);
			break ;
		}
	}
	return (NOERR);
}

void	*check_full(void *arg)
{
	t_philo	*ph_set;
	int		i;

	i = 0;
	if (g_info.must_eat == -1)
		return (NOERR);
	ph_set = (t_philo *)arg;
	while (g_info.state == NORMAL)
	{
		while (i < g_info.nbr_of_philo)
		{
			if (ph_set[i].remain > 0)
				i = 0;
			else
				i++;
		}
		pthread_mutex_lock(&g_info.m_state);
		g_info.state = FULL;
		pthread_mutex_unlock(&g_info.m_state);
	}
	return (NOERR);
}
