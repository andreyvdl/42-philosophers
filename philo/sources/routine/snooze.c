#include "../../include/philosophers.h"

void	snooze(t_philo *philo)
{
	print_action(philo, PHILO_SLEEP);
	usleep(philo->snooze_time * 1000);
}
