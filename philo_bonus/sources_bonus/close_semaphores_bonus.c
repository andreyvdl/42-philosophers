#include "../include_bonus/philosophers_bonus.h"

void	close_semaphores(t_philo *philo)
{
	sem_close(philo->sem_fork);
	sem_close(philo->sem_printf);
	sem_close(philo->sem_getter);
	sem_close(philo->sem_time);
	sem_close(philo->sem_meals);
}
