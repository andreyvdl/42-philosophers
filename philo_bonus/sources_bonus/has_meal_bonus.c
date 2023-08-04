#include "../include_bonus/philosophers_bonus.h"

bool	has_meals(t_philo *philo)
{
	bool	ret;

	sem_wait(philo->sem_meals);
	if (philo->meals == 0)
		ret = false;
	else
		ret = true;
	sem_post(philo->sem_meals);
	return (ret);
}
