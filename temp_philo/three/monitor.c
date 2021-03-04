/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:07:33 by jikwon            #+#    #+#             */
/*   Updated: 2021/03/04 14:08:29 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three.h"

void	*check_death(void *arg)
{
	t_philo	*one;
	int64_t	now;

	one = (t_philo *)arg;
	while (one->state != DIED)
	{
		now = get_time();
		if (now - one->last_meal > g_info.t_die)
		{
			print_msg("is died\n", one, now);
			one->state = DIED;
		}
	}
	sem_post(g_info.s_death);
	return (NOERR);
}

void	*check_full(void *arg)
{
	t_philo	*one;

	one = (t_philo *)arg;
	if (g_info.must_eat == -1)
		return (NOERR);
	while (one->remain != 0)
		usleep(100);
	print_msg("is full\n", one, get_time());
	sem_post(g_info.s_full);
	return (NOERR);
}

int		make_monitor(t_philo *ph_set)
{
	pthread_t	state_death;
	pthread_t	state_full;

	if ((pthread_create(&state_death, NULL,
					read_state_death, (void *)ph_set)) != NOERR)
		return (ERR);
	pthread_detach(state_death);
	if ((pthread_create(&state_full, NULL,
					read_state_full, (void *)ph_set)) != NOERR)
		return (ERR);
	pthread_detach(state_death);
	return (NOERR);
}

void	*read_state_death(void *arg)
{
	t_philo	*ph_set;

	ph_set = (t_philo *)arg;
	sem_wait(g_info.s_death);
	sem_wait(g_info.s_write);
	printf("Someone is died\n");
	sem_post(g_info.s_write);
	kill_process(ph_set);
	return (NOERR);
}

void	*read_state_full(void *arg)
{
	int		full;
	t_philo	*ph_set;

	full = 0;
	ph_set = (t_philo *)arg;
	if (g_info.must_eat == -1)
		return (NOERR);
	while (full != g_info.nbr_of_philo)
	{
		sem_wait(g_info.s_full);
		full++;
	}
	sem_wait(g_info.s_write);
	printf("All are full\n");
	sem_post(g_info.s_write);
	kill_process(ph_set);
	return (NOERR);
}
