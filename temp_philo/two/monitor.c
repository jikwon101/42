/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:39:50 by jikwon            #+#    #+#             */
/*   Updated: 2021/03/04 13:41:39 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "two.h"

void	*check_death(void *arg)
{
	t_philo	*one;
	int64_t	time;

	one = (t_philo *)arg;
	while (g_info.state != DIED)
	{
		time = get_time();
		if (time - one->last_meal > g_info.t_die)
		{
			print_msg("is died\n", one, time);
			sem_wait(g_info.s_state);
			g_info.state = DIED;
			sem_post(g_info.s_state);
			break ;
		}
	}
	return (NOERR);
}

void	*check_full(void *arg)
{
	t_philo	*ph_set;
	int		i;

	ph_set = (t_philo *)arg;
	if (g_info.must_eat == -1)
		return (NOERR);
	while (g_info.state == NORMAL)
	{
		while (i < g_info.nbr_of_philo)
		{
			if (ph_set[i].remain > 0)
				i = 0;
			else
				i++;
		}
		sem_wait(g_info.s_state);
		g_info.state = FULL;
		sem_post(g_info.s_state);
	}
	return (NOERR);
}
