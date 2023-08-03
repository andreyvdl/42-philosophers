#include "../../include_bonus/philosophers_bonus.h"

static void	snooze(t_philo *philo)
{
	print_action(philo, PHILO_SLEEP);
	usleep(philo->time_to_sleep * 1000);
}

static void	think(t_philo *philo)
{
	print_action(philo, PHILO_THINK);
	usleep(100);
}

void	routine(t_philo *philo)
{
	if (philo->id % 2 == 1)
		usleep(1000);
	while (has_meals(philo) && nobody_died(philo))
	{
		take_forks(philo);
		eat(philo);
		drop_forks(philo);
		snooze(philo);
		think(philo);
	}
	close_semaphores(philo);
	free_semaphores(philo);
	exit(0);
}
