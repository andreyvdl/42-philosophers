#include "../../include_bonus/philosophers_bonus.h"

void	am_i_alive(t_philo *philo)
{
	if (get_time_ms() > philo->last_meal + philo->lifetime)
	{
		sem_wait(philo->sem_printf);
		printf(PHILO_RIP, get_time_ms() - philo->starting, philo->id);
		close_semaphores(philo);
		exit(EXIT_FAILURE);
	}
}
