/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:03:37 by adantas-          #+#    #+#             */
/*   Updated: 2023/08/02 11:49:38 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	set_died(t_philo philos[])
{
	pthread_mutex_lock(philos->m_getter);
	*get_died() = true;
	pthread_mutex_unlock(philos->m_getter);
}

static bool	has_died(t_philo *philos)
{
	bool	ret;

	pthread_mutex_lock(philos->m_time);
	if (philos->lifetime + philos->last_meal < get_time_ms())
	{
		set_died(philos);
		pthread_mutex_lock(philos->m_print);
		printf(PHILO_RIP, get_time_ms() - philos->starting, philos->id);
		pthread_mutex_unlock(philos->m_print);
		ret = true;
	}
	else
		ret = false;
	pthread_mutex_unlock(philos->m_time);
	return (ret);
}

static void	panopticon(t_philo philos[], uint16_t nbr_philos)
{
	uint16_t	i;
	uint16_t	finished;

	finished = 0;
	while (finished != nbr_philos && nobody_died(philos))
	{
		i = -1;
		finished = 0;
		while (++i < nbr_philos)
		{
			if (has_meals(&philos[i]) == false)
				finished++;
			else if (has_died(&philos[i]))
				break ;
		}
		usleep(100);
	}
}

void	start_simulation(t_philo philos[], int16_t nbr_philos)
{
	pthread_t	thread[MAX_PHILOS];
	int16_t		i;

	i = -1;
	while (++i < nbr_philos)
	{
		philos[i].starting = get_time_ms();
		philos[i].last_meal = philos[i].starting;
	}
	i = -1;
	while (++i < nbr_philos)
		pthread_create(&thread[i], NIL, &routine, (void *)&philos[i]);
	usleep(100);
	panopticon(philos, nbr_philos);
	i = -1;
	while (++i < nbr_philos)
		pthread_join(thread[i], NIL);
	destroy_mutexes(philos, nbr_philos);
}
