#include "../../include/philosophers.h"

void	think(t_philo *philo)
{
	print_action(philo, PHILO_THINK);
	usleep(100);
}
