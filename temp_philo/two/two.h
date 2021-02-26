/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:49:04 by jikwon            #+#    #+#             */
/*   Updated: 2021/02/25 19:49:29 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWO_H
# define TWO_H

# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <semaphore.h>
# include <unistd.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/stat.h>

# define ERR 1
# define NOERR 0
# define NORMAL 0
# define DIED 1
# define FULL 2
# define NONDIGIT -1
# define CONVERT_FACTOR 1000L

typedef struct	s_info
{
	int		nbr_of_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		must_eat;
	int		state;
	sem_t	*s_write;
	sem_t	*s_eat;
	sem_t	*s_state;
}				t_info;

typedef struct	s_philo
{
	int			idx;
	pthread_t	thread;
	int			remain;
	int64_t		last_meal;
	int64_t		t_start;
}				t_philo;

t_info			g_info;

#endif
