#include "../include_bonus/philosophers_bonus.h"

void	set_sempahores(t_philo philos[], int16_t nbr_philos)
{
	int16_t	i;

	philos->sem_fork = malloc(sizeof(sem_t));
	philos->sem_fork = sem_open("/fork", O_CREAT, RNW, nbr_philos);
	philos->sem_printf = malloc(sizeof(sem_t));
	philos->sem_printf = sem_open("/printf", O_CREAT, RNW, 1);
	philos->sem_getter = malloc(sizeof(sem_t));
	philos->sem_getter = sem_open("/getter", O_CREAT, RNW, 1);
	philos->sem_time = malloc(sizeof(sem_t));
	philos->sem_time = sem_open("/time", O_CREAT, RNW, 1);
	philos->sem_meals = malloc(sizeof(sem_t));
	philos->sem_meals = sem_open("/meals", O_CREAT, RNW, 1);
	i = 0;
	while (++i < nbr_philos)
	{
		philos[i].sem_fork = philos->sem_fork;
		philos[i].sem_printf = philos->sem_printf;
		philos[i].sem_getter = philos->sem_getter;
		philos[i].sem_time = philos->sem_time;
		philos[i].sem_meals = philos->sem_meals;
	}
}
