#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
# define ERR 1
# define NOERR 0
# define DIED 1
# define FULL 2
typedef struct s_philo
{
	pthread_t thread;
	int idx;
	pthread_mutex_t *right_fork;
	pthread_mutex_t *left_fork;
	long last_meal;
	long t_start;
}	t_philo;

const int nbr_ph = 2;
const int t_die = 800;
const int t_eat = 200;
const int t_sleep = 200;
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

long get_time(void)
{
	struct timeval s_time;

	gettimeofday(&s_time, NULL);
	return (s_time.tv_sec * 1000L + s_time.tv_usec / 1000L);
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
	//if (state != DIED && state != FULL)
//	{
		ft_putnbr(get_time() - one->t_start);
		ft_putstr("ms idx ");
		ft_putnbr(one->idx);
		ft_putstr(str);
//	}
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
		ph_set[i].last_meal = get_time();
		ph_set[i].t_start = get_time();
		i++;
	}
	return (ph_set);
}
void do_eat(t_philo *one)
{
	long t_target;
	pthread_mutex_lock(one->right_fork);
	pthread_mutex_lock(one->left_fork);
	//one->last_meal = get_time();
	//t_target = get_time() + t_eat;
	print_msg(" has taken a fork\n", one);
	print_msg(" here\n", one);
	//usleep(t_eat);
	print_msg(" dropped a fork\n", one);
	pthread_mutex_unlock(one->left_fork);
	pthread_mutex_unlock(one->right_fork);
}

void *routine(void *arg)
{
	t_philo *one;
	
	one = (t_philo *)arg;
	one->idx % 2 ? 0 : usleep(t_eat);
	//while (state != DIED && state != FULL)
	while (1)
	{
		do_eat(one);
		print_msg(" is sleeping\n", one);
		usleep(t_sleep);
		print_msg(" is thinking\n", one);
	}	
	return (NOERR);
}

int make_threads(t_philo *ph_set)
{
	int	i;

	i = 0;
	while (i < nbr_ph)
	{
		pthread_create(&ph_set[i].thread, NULL, routine, &ph_set[i]);
		usleep(10); //temporaily 10
		i++;
	}
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
