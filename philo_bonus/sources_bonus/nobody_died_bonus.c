#include "../include_bonus/philosophers_bonus.h"

bool	nobody_died(t_philo *philo)
{
	bool	ret;

	sem_wait(philo->sem_getter);
	if (*get_died())
		ret = false;
	else
		ret = true;
	sem_post(philo->sem_getter);
	return (ret);
}
