#include "philosophers.h"

void	am_i_dead(t_philo_pub *philo)
{
	if (philo->private.last_meal + *(philo->lifetime) < get_time_ms())
	{
		pthread_mutex_lock(philo->print_mutex);
		printf(PHILO_RIP, get_time_ms() - *(philo->start_time), philo->id);
		pthread_mutex_lock(philo->state_mutex);
		philo->private.state = E_DEAD;
		pthread_mutex_unlock(philo->state_mutex);
	}
}
