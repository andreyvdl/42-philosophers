#include "../../include/philosophers.h"

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->m_my_fork);
	pthread_mutex_unlock(philo->m_next_fork);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->m_my_fork);
	print_action(philo, PHILO_FORK);
	pthread_mutex_lock(philo->m_next_fork);
	print_action(philo, PHILO_FORK);
}
