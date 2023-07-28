#include "../../include/philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	update_time(philo);
	if (philo->id % 2 == 1)
		usleep(100);
	while (has_meals(philo) && nobody_died())
	{
		take_forks(philo);
		eat(philo);
		drop_forks(philo);
		snooze(philo);
		think(philo);
	}
	return (NIL);
}
