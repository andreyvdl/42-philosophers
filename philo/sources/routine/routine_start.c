#include "philosophers.h"

static void	should_eat(t_philo_pub philo[])
{
	pthread_mutex_unlock(philo->state_mutex);
	lunch(philo);
}

static void	should_sleep(t_philo_pub philo[])
{
	pthread_mutex_unlock(philo->state_mutex);
	snooze(philo);
}

static void	should_think(t_philo_pub philo[])
{
	pthread_mutex_unlock(philo->state_mutex);
	think(philo);
}

void	*routine(t_philo_pub *philo)
{
	philo->private.last_meal = get_time_ms();
	if (philo->id % 2 == 1)
		usleep(1000);
	am_i_dead(philo);
	while (philo->private.philo_meals != 0)
	{
		pthread_mutex_lock(philo->state_mutex);
		if (philo->private.state == E_EATING)
			should_eat(philo);
		am_i_dead(philo);
		else if (philo->private.state == E_SLEEPING)
			should_sleep(philo);
		am_i_dead(philo);
		else if (philo->private.state == E_THINKING)
			should_think(philo);
		am_i_dead(philo);
	}
	exit(0);
}
