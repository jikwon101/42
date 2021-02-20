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
# define CF 1000L

int nbr_ph;
int	t_die;
int t_eat;
int t_sleep;
int must_eat;
int state;

pthread_mutex_t *m_forks;
pthread_mutex_t m_write;
pthread_mutex_t m_state;

typedef struct	s_philo
{
	int				idx;
	pthread_t		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	int				remain;
	long			last_meal;
	long			t_start;
}				t_philo;

//monitor.c
void *check_death(void *arg);
void *check_full(void *arg);

//init.c
int  init_mutex(void);
t_philo *init_threads(void);
int	init_state(int ac, char **av);

//common.c
void ft_putnbr(long long nbr);
void ft_putstr(const char *str);
int	ft_atoi(char *str);

//utils.c
int print_msg(const char *str, t_philo *one);
long get_time(void);

//main.c
void do_eat(t_philo *one);
void *routine(void *arg);

//make_destroy_threads.c
void finish_threads(t_philo *ph_set);
int make_threads(t_philo *ph_set);
#endif
