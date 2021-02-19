/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 13:23:09 by kmin              #+#    #+#             */
/*   Updated: 2020/09/09 14:20:39 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

void		finish_semaphores(t_philo *ph, t_sem *sems)
{
	sem_unlink("forks");
	sem_unlink("write");
	sem_unlink("meal");
	sem_close(sems->s_meal);
	sem_close(sems->s_forks);
	sem_close(sems->s_write);
	free(ph);
}
