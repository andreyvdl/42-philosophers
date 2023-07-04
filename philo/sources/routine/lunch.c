#include "philosophers.h"

void	lunch(t_philo_pub philo[])
{
	bool	picked_forks;

	picked_forks = false;
	pthread_mutex_lock(philo->forks_mutex);
	if (*(philo->table_forks) >= 2)
	{
		picked_forks = true;
		*(philo->table_forks) -= 2;
		pthread_mutex_unlock(philo->forks_mutex);
		pthread_mutex_lock(philo->print_mutex);
		printf()
	}
	if (picked_forks == false)
		pthread_mutex_unlock(philo->forks_mutex);
}
