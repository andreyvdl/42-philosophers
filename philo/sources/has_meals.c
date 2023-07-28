#include "../include/philosophers.h"

bool	has_meals(t_philo *philo)
{
	bool	ret;

	pthread_mutex_lock(philo->m_meals);
	if (philo->meals == 0)
		ret = false;
	else
		ret = true;
	pthread_mutex_unlock(philo->m_meals);
	return (ret);
}
