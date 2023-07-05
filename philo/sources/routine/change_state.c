#include "../../include/philosophers.h"

void	change_state(t_philo_pub philo[], t_state state)
{
	pthread_mutex_lock(philo->state_mutex);
	philo->private.state = state;
	pthread_mutex_unlock(philo->state_mutex);
}
