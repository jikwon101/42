#include "one.h"

void do_eat(t_philo *one)
{
	long t_target;

	pthread_mutex_lock(one->right_fork);
	pthread_mutex_lock(one->left_fork);
	one->last_meal = get_time();
	print_msg(" has taken a fork\n", one);
	print_msg(" is eating\n", one);
	if (one->remain > 0)
		one->remain -= 1;
	t_target = one->last_meal + t_eat;
	while (get_time() < t_target)
		usleep(10); //100us = 0.1ms
		pthread_mutex_unlock(one->right_fork);
	pthread_mutex_unlock(one->left_fork);
}

void *routine(void *arg)
{
	t_philo *one;
	pthread_t died;
	pthread_t full;
	long t_target;

	one = (t_philo *)arg;
	pthread_create(&died, NULL, &check_death, one);
	pthread_detach(died);
	if (one->idx % 2 == 0)  
		usleep(t_eat * CF / 2); //usleep = us . t_eat = ms
	while (state != DIED && state != FULL)
	{
		do_eat(one);
		print_msg(" is sleeping\n", one);
		t_target = get_time() + t_sleep;
		while (get_time() < t_target)
			usleep(10);
		print_msg(" is thinking\n", one);
	}
	return (NOERR);
}

int main(int ac, char **av)
{
	t_philo *ph_set;
	
	if (init_state(ac, av) == ERR)
		return (ERR);
	if (init_mutex() == ERR)
		return (ERR);
	ph_set = init_threads();
	make_threads(ph_set);
	finish_threads(ph_set);
	return (0);
}
