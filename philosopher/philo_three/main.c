/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:06:15 by jikwon            #+#    #+#             */
/*   Updated: 2021/03/04 18:00:43 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three.h"

void	do_eat(t_philo *one)
{
	int64_t	target;

	sem_wait(g_info.s_fork);
	sem_wait(g_info.s_fork);
	print_msg("has taken forks\n", one, get_time());
	one->last_meal = get_time();
	print_msg("is eating\n", one, one->last_meal);
	target = one->last_meal + g_info.t_eat;
	while (get_time() < target)
		usleep(50);
	sem_post(g_info.s_fork);
	sem_post(g_info.s_fork);
	one->remain = one->remain > 0 ? one->remain - 1 : one->remain;
}

int		routine(t_philo *one)
{
	pthread_t	death;
	pthread_t	full;
	int64_t		target;

	pthread_create(&death, NULL, &check_death, (void *)one);
	pthread_detach(death);
	pthread_create(&full, NULL, &check_full, (void *)one);
	pthread_detach(full);
	if (one->idx % 2 == 0)
		usleep(g_info.t_eat * CONVERT_FACTOR);
	while (one->state != DIED)
	{
		do_eat(one);
		print_msg("is sleeping\n", one, get_time());
		target = get_time() + g_info.t_sleep;
		while (get_time() < target)
			usleep(50);
		print_msg("is thinking\n", one, get_time());
	}
	return (NOERR);
}

int		make_process(t_philo *ph_set)
{
	int	i;

	i = 0;
	while (i < g_info.nbr_of_philo)
	{
		ph_set[i].pid = fork();
		if (ph_set[i].pid == 0)
		{
			routine(&ph_set[i]);
			exit(0);
		}
		else if (ph_set[i].pid < 0)
			return (ERR);
		usleep(50);
		i++;
	}
	if (make_monitor(ph_set) == ERR)
		return (ERR);
	i = -1;
	while (++i < g_info.nbr_of_philo)
		waitpid(ph_set[i].pid, &ph_set[i].exit_status, 0);
	return (NOERR);
}

int		main(int ac, char **av)
{
	t_philo	*ph_set;

	if ((init_info(ac, av) == ERR) || (init_sema() == ERR))
		return (ERR);
	if ((ph_set = init_philo()) == NULL)
		return (ERR);
	if (make_process(ph_set) == ERR)
		kill_process(ph_set);
	free(ph_set);
	return (clean_sema(NOERR));
}