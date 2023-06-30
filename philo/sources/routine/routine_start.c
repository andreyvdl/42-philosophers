#include "../../include/philosophers.h"

static void	should_eat(t_philo_pub philo[])
{
	pthread_mutex_unlock(philo->state_mutex);
	lunch(philos);
}

static void	should_sleep(t_philo_pub philo[])
{
	pthread_mutex_unlock(philo->state_mutex);
	snooze(philos);
}

static void	should_think(t_philo_pub philo[])
{
	pthread_mutex_unlock(philo->state_mutex);
	think(philos);
}

void	*routine(void *arg)
{
	t_philo_pub	philo[1];

	philo = (t_philo_pub *)arg;
	if (philo->id % 2 == 1)
		usleep(1000);
	pthread_mutex_lock(philo->print_mutex);
	if (philo->private.last_meal < philo->(*start_time) - get_time_ms())
		philo_dead(philo);
	while (philo->private.philo_meals != 0)
	{
		pthread_mutex_lock(philo->state_mutex);
		if (philo->private.state == E_EATING)
			should_eat(philo);
		else if (philo->private.state == E_SLEEPING)
			should_sleep(philo);
		else if (philo->private.state == E_THINKING)
			should_think(philo);
	}
	exit(0);
}
