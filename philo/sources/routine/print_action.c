#include "../../include/philosophers.h"

void	print_action(t_philo *philo, char *str)
{
	if (nobody_died())
	{
		pthread_mutex_lock(philo->m_print);
		printf(str, get_time_ms() - philo->starting, philo->id);
		pthread_mutex_unlock(philo->m_print);
	}
}
