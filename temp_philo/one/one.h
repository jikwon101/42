/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikwon <jikwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 20:43:05 by jikwon            #+#    #+#             */
/*   Updated: 2021/02/25 20:46:20 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ONE_H
# define ONE_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

# define ERR 1
# define NOERR 0
# define NORMAL 0
# define DIED 1
# define FULL 2
# define NONDIGIT -1
# define CONVERT_FACTOR 1000L

typedef struct	s_info
{
	int				nbr_of_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				must_eat;
	int				state;
	pthread_mutex_t	*m_forks;
	pthread_mutex_t	m_write;
	pthread_mutex_t	m_state;
}				t_info;

typedef struct	s_philo
{
	int				idx;
	pthread_t		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	int				remain;
	int64_t			last_meal;
	int64_t			t_start;
}				t_philo;

t_info			g_info;

/*
** monitor.c
*/

void			*check_death(void *arg);
void			*check_full(void *arg);

/*
**init.c
*/

int				init_mutex(void);
t_philo			*init_threads(void);
int				init_info(int ac, char **av);

/*
**utils.c
*/

void			print_msg(const char *str, t_philo *one, int64_t time);
int64_t			get_time(void);
int64_t			ft_atoi(char *str);

/*
**main.c
*/

void			do_eat(t_philo *one);
void			*routine(void *arg);

/*
**make_destroy_threads.c
*/

void			finish_threads(t_philo *ph_set);
int				make_threads(t_philo *ph_set);
#endif
