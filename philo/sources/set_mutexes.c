/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mutexes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:03:33 by adantas-          #+#    #+#             */
/*   Updated: 2023/07/31 13:03:35 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	only_one_for_these(t_philo philos[], int16_t nbr_philos)
{
	pthread_mutex_t	*print;
	pthread_mutex_t	*time;
	pthread_mutex_t	*meals;
	pthread_mutex_t	*getter;
	int16_t			i;

	print = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(print, NULL);
	time = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(time, NULL);
	meals = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(meals, NULL);
	getter = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(getter, NULL);
	i = -1;
	while (++i < nbr_philos)
	{
		philos[i].m_print = print;
		philos[i].m_time = time;
		philos[i].m_meals = meals;
		philos[i].m_getter = getter;
	}
}

void	set_mutex(t_philo philos[], int16_t nbr_philos)
{
	pthread_mutex_t	*one_fork;
	int16_t			i;

	i = -1;
	while (++i < nbr_philos)
	{
		one_fork = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(one_fork, NULL);
		philos[i].m_my_fork = one_fork;
	}
	i = -1;
	--nbr_philos;
	while (++i < nbr_philos)
		philos[i].m_next_fork = philos[i + 1].m_my_fork;
	philos[i].m_next_fork = philos->m_my_fork;
	++nbr_philos;
	only_one_for_these(philos, nbr_philos);
}
