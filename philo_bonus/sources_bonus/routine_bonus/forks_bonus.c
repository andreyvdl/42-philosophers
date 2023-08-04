#include "../../include_bonus/philosophers_bonus.h"

void	take_forks(t_philo *philo)
{
	sem_wait(philo->sem_fork);
	print_action(philo, PHILO_FORK);
	sem_wait(philo->sem_fork);
	print_action(philo, PHILO_FORK);
}

void	drop_forks(t_philo *philo)
{
	sem_post(philo->sem_fork);
	sem_post(philo->sem_fork);
}
