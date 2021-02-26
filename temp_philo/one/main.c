/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 20:41:30 by jikwon            #+#    #+#             */
/*   Updated: 2021/02/25 22:40:35 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

void	do_eat(t_philo *one)
{
	int64_t target;

	pthread_mutex_lock(one->left_fork);
	pthread_mutex_lock(one->right_fork);
	print_msg("has taken a fork\n", one, get_time());
	one->last_meal = get_time();
	print_msg("is eating\n", one, one->last_meal);
	target = one->last_meal + g_info.t_eat;
	while (get_time() < target)
		usleep(50);
	pthread_mutex_unlock(one->right_fork);
	pthread_mutex_unlock(one->left_fork);
	one->remain > 0 ? one->remain -= 1 : 0;
}

void	*routine(void *arg)
{
	t_philo		*one;
	pthread_t	death;
	pthread_t	full;
	int64_t		target;

	one = (t_philo *)arg;
	pthread_create(&death, NULL, &check_death, one);
	pthread_detach(death);
	one->idx % 2 ? 0 : usleep(g_info.t_eat * 2 / 3);
	while (g_info.state == NORMAL)
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

int		main(int ac, char **av)
{
	t_philo *ph_set;

	if (init_info(ac, av) == ERR)
		return (ERR);
	if (init_mutex() == ERR)
		return (ERR);
	ph_set = init_threads();
	make_threads(ph_set);
	if (g_info.state == DIED)
		printf("Someone is died\n");
	else if (g_info.state == FULL)
		printf("All are full\n");
	finish_threads(ph_set);
	return (NOERR);
}
