#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

# define ERR 1
# define NOERR 0
# define DIED 1
# define FULL 2
# define CF 1000L //conversion factor 1ms = 1000us

// thread 마다 must_eat 이 0 이면 full thread 중단. 
//must_eat 0이면 state++하기. state = nbr_ph 면 끝.
//state이 dead면 -1주기. 0 < state < nbr_ph일떄까지만돌리기.

typedef struct s_philo
{
	pthread_t thread;
	int idx;
	pthread_mutex_t *right_fork;
	pthread_mutex_t *left_fork;
	int remain;
	long last_meal;
	long t_start;
}	t_philo;

const int nbr_ph = 2;
const int t_die = 410; //(ms)
const int t_eat = 200; //(ms)
const int t_sleep = 100; //(ms)
const int must_eat = 1;
int state = 0;

pthread_mutex_t *m_forks;
pthread_mutex_t m_write;
pthread_mutex_t m_state;

int init_mutex(void)
{
	int i;

	i = 0;
	m_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nbr_ph);
	if (m_forks == NULL)
		return (ERR);
	while (i < nbr_ph)
		pthread_mutex_init(&m_forks[i++], NULL);
	pthread_mutex_init(&m_write, NULL);
	pthread_mutex_init(&m_state, NULL);
	return (NOERR);
}

//return ms
long get_time(void)
{
	struct timeval s_time;
	long ms;

	gettimeofday(&s_time, NULL);
	ms = s_time.tv_sec * CF + s_time.tv_usec / CF;
	return (ms);
}

void ft_putnbr(long long nbr)
{
	char base[] = "0123456789";
	char c;

	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	c = base[nbr % 10];
	write(1, &c, 1);
	return ;
}

void ft_putstr(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return ;
}

int print_msg(const char *str, t_philo *one)
{
	pthread_mutex_lock(&m_write);
	if (state != DIED && state != FULL)
	{
		ft_putnbr(get_time() - one->t_start);
		ft_putstr("ms idx ");
		ft_putnbr(one->idx);
		ft_putstr(str);
	}
	pthread_mutex_unlock(&m_write);
	return (NOERR);
}	

t_philo *init_threads(void)
{
	t_philo *ph_set;
	int i;

	i = 0;
	ph_set = (t_philo *)malloc(sizeof(t_philo) * nbr_ph);
	while (i < nbr_ph)
	{
		ph_set[i].idx = i + 1;
		ph_set[i].left_fork = &m_forks[i];
		ph_set[i].right_fork = &m_forks[(i + 1) % nbr_ph];
		ph_set[i].remain = 1;
		//ph_set[i].last_meal = get_time();
		//ph_set[i].t_start = get_time();
		i++;
	}
	return (ph_set);
}

void *check_death(void *arg)
{
	t_philo *one;

	one = (t_philo *)arg;
	while (state != DIED)
	{
		if (get_time() - one->last_meal > t_die)
		{
			print_msg(" is died", one);
			pthread_mutex_lock(&m_state);
			state = DIED;
			pthread_mutex_unlock(&m_state);
			break;
		}
	}
	return (NOERR);
}

void do_eat(t_philo *one)
{
	long t_target;

	pthread_mutex_lock(one->right_fork);
	pthread_mutex_lock(one->left_fork);
	one->last_meal = get_time();
	print_msg(" has taken a fork\n", one);
	print_msg(" is eating\n", one);
	t_target = one->last_meal + t_eat;
	one->remain -= 1;
	while (get_time() < t_target)
		usleep(100); //100us = 0.1ms
	pthread_mutex_unlock(one->right_fork);
	pthread_mutex_unlock(one->left_fork);
}

void *routine(void *arg)
{
	t_philo *one;
	pthread_t died;
	
	one = (t_philo *)arg;
	pthread_create(&died, NULL, &check_death, one);
	pthread_detach(died);
	pthread_create(&full, NULL, &check_full, ph_set);
	pthread_detach(full);
	if (one->idx % 2 == 0)  
		usleep(t_eat * CF / 2); //usleep = us . t_eat = ms
	while (state != DIED && state != FULL)
	{
		do_eat(one);
		print_msg(" is sleeping\n", one);
		usleep(t_sleep * CF);
		print_msg(" is thinking\n", one);
	}	
	return (NOERR);
}
void *check_full(void *arg)
{
	t_philo *ph_set;
	int i;
	int res_sum;

	ph_set = (t_philo *)arg;
	while (state != DIED && state != FULL)
	{
		i = 0;
		while (i < nbr_ph)
		{
			res_sum += ph_set[i].remain;
			i++;
		}
		if (res_sum <= 0)
		{
			pthread_mutex_lock(&m_state);
			state = FULL;
			pthread_mutex_unlock(&m_state);
		}
	}
	return (NOERR);
}
int make_threads(t_philo *ph_set)
{
	int	i;

	i = 0;
	while (i < nbr_ph)
	{
		ph_set[i].last_meal = get_time();
		ph_set[i].t_start = get_time();
		pthread_create(&ph_set[i].thread, NULL, routine, &ph_set[i]);
		usleep(1); 
		i++;
	}
	i = 0;
	while (i < nbr_ph)
		pthread_join(ph_set[i++].thread, NULL);
	return (NOERR);
}
void finish_threads(t_philo *ph_set)
{
	int i;

	i = 0;
	while (i < nbr_ph)
		pthread_mutex_destroy(&m_forks[i++]);
	pthread_mutex_destroy(&m_write);
	pthread_mutex_destroy(&m_state);
	free(ph_set);
	free(m_forks);
}
int main()
{
	t_philo *ph_set;

	if (init_mutex() == ERR)
		return (ERR);
	ph_set = init_threads();
	make_threads(ph_set);
	finish_threads(ph_set);
	return (0);
}
