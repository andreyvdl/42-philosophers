#include "philosophers.h"

void	memento_mori(t_philo_pub *philo)
{
	pthread_mutex_unlock(philo->state_mutex);
	if (*(philo->start_time) + philo->private.last_meal + *(philo->lifetime) < get_time_ms())
	{
		pthread_mutex_lock(philo->print_mutex);
		printf(PHILO_RIP, get_time_ms() - *(philo->start_time), philo->id);
		change_state(philo, E_DEAD);
		exit(EXIT_SUCCESS);
	}
}
