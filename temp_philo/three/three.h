/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:27:16 by jikwon            #+#    #+#             */
/*   Updated: 2021/02/25 15:27:45 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREE_H
# define THREE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <pthread.h>
# include <signal.h>

# define NORMAL 0
# define DIED 1
# define CONVERT_FACTOR 1000L
# define ERR 1
# define NOERR 0
# define NONDIGIT -1

typedef struct	s_info
{
	int		nbr_of_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		must_eat;
	sem_t	*s_write;
	sem_t	*s_eat;
	sem_t	*s_death;
	sem_t	*s_full;
}				t_info;

typedef struct	s_philo
{
	int		idx;
	pid_t	pid;
	int		remain;
	int		state;
	int		exit_status;
	int64_t	last_meal;
	int64_t	t_start;
}				t_philo;
#endif
