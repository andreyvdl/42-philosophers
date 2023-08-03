#include "../../include_bonus/philosophers_bonus.h"

void	take_forks(t_philo *philo)
{
	sem_wait(philo->forks);
	print_action(philo, PHILO_FORK);
	sem_wait(philo->forks);
	print_action(philo, PHILO_FORK);
}

void	drop_forks(t_philo *philo)
{
	sem_post(philo->forks);
	sem_post(philo->forks);
}
