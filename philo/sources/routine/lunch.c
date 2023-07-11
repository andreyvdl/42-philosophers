#include "philosophers.h"

static void	print_eat(t_philo_pub philo[])
{
	pthread_mutex_lock(philo->print_mutex);
	printf(PHILO_FORK, get_time_ms() - *(philo->start_time), philo->id);
	printf(PHILO_FORK, get_time_ms() - *(philo->start_time), philo->id);
	printf(PHILO_EAT, get_time_ms() - *(philo->start_time), philo->id);
	pthread_mutex_unlock(philo->print_mutex);
}

static void	check_eat_death(t_philo_pub philo[])
{
	time_t	diff_to_die;

	diff_to_die = (philo->private.last_meal + *(philo->lifetime))
		- (philo->private.last_meal + *(philo->lunch_time));
	if (diff_to_die <= 0)
	{
		pthread_mutex_lock(philo->forks_mutex);
		if (*(philo->table_forks) >= 2)
		{
			*(philo->table_forks) -= 2;
			pthread_mutex_unlock(philo->forks_mutex);
			print_eat(philo);
			philo->private.last_meal = get_time_ms();
			usleep((*(philo->lunch_time) - diff_to_die) * 1000);
			memento_mori(philo);
		}
		else
		{
			pthread_mutex_unlock(philo->forks_mutex);
			usleep((*(philo->lunch_time) - diff_to_die) * 1000);
			memento_mori(philo);
		}
	}
}

void	lunch(t_philo_pub philo[])
{
	check_eat_death(philo);
	pthread_mutex_lock(philo->forks_mutex);
	if (*(philo->table_forks) >= 2)
	{
		*(philo->table_forks) -= 2;
		pthread_mutex_unlock(philo->forks_mutex);
		print_eat(philo);
		philo->private.last_meal = get_time_ms();
		usleep(*(philo->lunch_time) * 1000);
		pthread_mutex_lock(philo->forks_mutex);
		*(philo->table_forks) += 2;
		pthread_mutex_unlock(philo->forks_mutex);
		change_state(philo, E_SLEEPING);
		return ;
	}
	pthread_mutex_unlock(philo->forks_mutex);
}
