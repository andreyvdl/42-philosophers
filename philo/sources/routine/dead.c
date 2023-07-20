#include "philosophers.h"

void	memento_mori(t_philo_pub *philo)
{
	if (philo->private.last_meal + philo->lifetime < get_time_ms())
	{
		pthread_mutex_lock(philo->print_mutex);
		printf(PHILO_RIP, get_time_ms() - philo->start_time, philo->id);
		pthread_mutex_unlock(philo->print_mutex);
		change_state(philo, E_DEAD);
		philo->private.philo_meals = 0;
	}
}
