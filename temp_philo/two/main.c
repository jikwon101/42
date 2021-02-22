#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>

# define ERR 1
# define NOERR 0
# define NORMAL 0
# define DIED 1
# define FULL 2
# define CONVERT_FACTOR 1000L

typedef struct s_info
{
	int nbr_of_philo;
	uint64_t t_die;
	uint64_t t_eat;
	uint64_t t_sleep;
	int must_eat;
	int state;
	sem_t *s_write;
	sem_t *s_forks;
	sem_t *s_state;
}		t_info;

typedef struct s_philo
{
	int idx;
	pthread_t thread;
	int remain;
	uint64_t last_meal;
	uint64_t t_start;
	t_info *info;
}	t_philo;

uint64_t get_time(void)
{
	struct timeval s_time;

	gettimeofday(&s_time, NULL);
	return (s_time.tv_sec * CONVERT_FACTOR + s_time.tv_usec / CONVERT_FACTOR);
}
int init_info(t_info *info)
{
	info->nbr_of_philo = 4;
	info->t_die = 410;
	info->t_eat = 200 * 1000L;
	info->t_sleep = 200 * 1000L;
	info->must_eat = -1;
	info->state = NORMAL;
	info->s_write = sem_open("s_write", O_CREAT, 0644, 1);
	info->s_forks = sem_open("s_forks", O_CREAT, 0644, info->nbr_of_philo);
	info->s_state = sem_open("s_state", O_CREAT, 0644, 1);
	return (NOERR);
}

t_philo *init_philo(t_info *info)
{
	t_philo *ph_set;
	int i;

	i = 0;
	ph_set = (t_philo *)malloc(sizeof(t_philo) * info->nbr_of_philo);
	while (i < info->nbr_of_philo)
	{
		ph_set[i].idx = i + 1;
		ph_set[i].remain = info->must_eat;
		ph_set[i].last_meal = get_time();
		ph_set[i].t_start = get_time();
		ph_set[i].info = info;
		i++;
	}
	return (ph_set);

}
void print_msg(const char *str, t_philo *one)
{
	sem_wait(one->info->s_write);
	printf("%llu ms  ", get_time() - one->t_start);
	printf("idx %d : " , one->idx);
	printf("%s", str);
	sem_post(one->info->s_write);
}

int do_eat(t_philo *one)
{
	print_msg("here\n", one);
	sem_wait(one->info->s_forks);
	sem_wait(one->info->s_forks);
	one->last_meal = get_time();
	//usleep(one->info->t_eat);
	print_msg(" has taken forks\n", one);
	print_msg(" is eating\n", one);
	sem_post(one->info->s_forks);
	sem_post(one->info->s_forks);
	return (0);
}
void *check_death(void *arg)
{
	t_philo *one;
	uint64_t gap;
	uint64_t die;


	one = (t_philo *)arg;
	while (one->info->state != DIED)
	{
		gap = get_time() - one->last_meal;
		if (gap > one->info->t_die)
		{
			print_msg(" is died\n", one);
			sem_wait(one->info->s_state);
			one->info->state = DIED;
			sem_post(one->info->s_state);
			break;
		}
	}
	return (0);
}


void *routine(void *arg)
{
	t_philo *one;
	int i;
	pthread_t death;

	i = 0;
	one = (t_philo *)arg;
	//pthread_create(&death, NULL, &check_death, (void *)one);
	//pthread_detach(death);
	//while (one->info->state != DIED)
	if (one->idx % 2 == 0)
		usleep(one->info->t_eat * 2 / 3);
	while (one->info->state != DIED)
	{
		do_eat(one);
		print_msg(" is sleeping\n", one);
		usleep(one->info->t_sleep);
		print_msg(" is thinking\n", one);
	}
	return (NOERR);
}
int make_threads(t_philo *ph_set, t_info info)
{
	int i;


	i = 0;
	while (i < info.nbr_of_philo)
	{
		pthread_create(&ph_set[i].thread, NULL, &routine, &ph_set[i]);
		usleep(50);
		i++;
	}
	i = 0;
	while (i < info.nbr_of_philo)
		pthread_join(ph_set[i++].thread, NULL);
	return (NOERR);
}

int main()
{
	t_info info;
	t_philo *ph_set;

	init_info(&info);
	ph_set = init_philo(&info);
	make_threads(ph_set, info);

}
