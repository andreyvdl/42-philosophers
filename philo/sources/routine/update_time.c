#include "../../include/philosophers.h"

void	update_time(t_philo *philo)
{
	pthread_mutex_lock(philo->m_time);
	philo->last_meal = get_time_ms();
	pthread_mutex_unlock(philo->m_time);
}
