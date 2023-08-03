#include "../../include_bonus/philosophers_bonus.h"

void	print_action(t_philo *philo, char *str)
{
	if (nobody_died(philo))
	{
		sem_wait(philo->sem_print);
		printf(str, get_time_ms() - philo->starting, philo->id);
		sem_post(philo->sem_print);
	}
}
