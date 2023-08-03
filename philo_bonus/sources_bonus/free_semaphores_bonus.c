#include "../include_bonus/philosophers_bonus.h"

void	free_semaphores(t_philo *philo)
{
	free(philo->sem_fork);
	free(philo->sem_printf);
	free(philo->sem_getter);
	free(philo->sem_time);
	free(philo->sem_meals);
}
