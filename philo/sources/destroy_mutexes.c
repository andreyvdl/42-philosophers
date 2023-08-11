/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:03:05 by adantas-          #+#    #+#             */
/*   Updated: 2023/08/11 12:30:49 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	destroy_mutexes(t_philo philos[], int16_t nbr_philos)
{
	int16_t	i;

	i = -1;
	while (++i < nbr_philos)
	{
		pthread_mutex_destroy(philos[i].m_my_fork);
		free(philos[i].m_my_fork);
	}
	pthread_mutex_destroy(philos->m_getter);
	free(philos->m_getter);
	pthread_mutex_destroy(philos->m_time);
	free(philos->m_time);
	pthread_mutex_destroy(philos->m_meals);
	free(philos->m_meals);
	pthread_mutex_destroy(philos->m_print);
	free(philos->m_print);
}
