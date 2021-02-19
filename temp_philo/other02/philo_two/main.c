/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 13:26:58 by kmin              #+#    #+#             */
/*   Updated: 2020/09/09 14:18:14 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000L + time.tv_usec / 1000L);
}

int		messages(const char *str, t_philo *ph)
{
	sem_wait(ph->sems->s_write);
	if (ph->pd->state != DIED && ph->pd->state != FULL)
	{
		ft_putnbr_fd(get_time() - ph->program_start, 1);
		ft_putstr("ms idx ");
		ft_putnbr_fd(ph->philo_idx, 1);
		ft_putstr(str);
	}
	sem_post(ph->sems->s_write);
	return (0);
}

void	*print_do(void *tmp_ph)
{
	t_philo		*ph;
	pthread_t	died;

	ph = (t_philo *)tmp_ph;
	pthread_create(&died, NULL, &is_die, (void *)ph);
	pthread_detach(died);
	while (42 && ph->pd->state != DIED && ph->pd->state != FULL)
	{
		eating(ph);
		messages(" is sleeping\n", ph);
		usleep(ph->pd->time_to_sleep);
		messages(" is thinking\n", ph);
	}
	return (NULL);
}

int		make_threads(t_philo *ph, t_pd *pd)
{
	pthread_t	full;
	int			i;

	i = 0;
	while (i < pd->num_of_philo)
	{
		if (pthread_create(&ph[i].thread, NULL, print_do, &ph[i]) < 0)
		{
			ft_putstr("thread create error\n");
			return (-1);
		}
		usleep(FOR_PHILOS_ORDERING);
		i++;
	}
	pthread_create(&full, NULL, &is_full, (void *)ph);
	pthread_detach(full);
	i = 0;
	while (i < pd->num_of_philo)
		pthread_join(ph[i++].thread, NULL);
	return (0);
}

int		main(int argc, char **argv)
{
	t_philo		*ph;
	t_sem		sems;
	t_pd		pd;

	if (argc < 5)
		ft_putstr("Error! You should enter at least 4 arguments!\n");
	else
	{
		if (input_args(&pd, (const char **)argv) == -1)
			return (0);
		if (init_sems(&sems, &pd) == -1)
			return (0);
		ph = init_threads(&pd, &sems);
		make_threads(ph, &pd);
		finish_semaphores(ph, &sems);
	}
	return (0);
}
