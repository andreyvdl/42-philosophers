#include "../../include/philosophers.h"

void	think(t_philo_pub philo[])
{
	pthread_mutex_lock(philo->print_mutex);
	printf(PHILO_THINK, get_time_ms() - *(philo->start_time), philo->id);
	pthread_mutex_unlock(philo->print_mutex);
	usleep(1000);
	pthread_mutex_lock(philo->state_mutex);
	change_state(philo, E_EATING);
	pthread_mutex_unlock(philo->state_mutex);
}
