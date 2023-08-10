/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:01:59 by adantas-          #+#    #+#             */
/*   Updated: 2023/08/10 11:06:29 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	drop_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->m_next_fork);
		pthread_mutex_unlock(philo->m_my_fork);
		return ;
	}
	pthread_mutex_unlock(philo->m_my_fork);
	pthread_mutex_unlock(philo->m_next_fork);
}

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->m_my_fork);
		print_action(philo, PHILO_FORK);
		pthread_mutex_lock(philo->m_next_fork);
		print_action(philo, PHILO_FORK);
		return ;
	}
	pthread_mutex_lock(philo->m_next_fork);
	print_action(philo, PHILO_FORK);
	pthread_mutex_lock(philo->m_my_fork);
	print_action(philo, PHILO_FORK);
}
