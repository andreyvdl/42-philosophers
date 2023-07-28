#include "../include/philosophers.h"

bool	nobody_died(t_philo *philo)
{
	bool	ret;

	pthread_mutex_lock(philo->m_getter);
	if (*get_died())
		ret = false;
	else
		ret = true;
	pthread_mutex_unlock(philo->m_getter);
	return (ret);
}
