/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:02:23 by adantas-          #+#    #+#             */
/*   Updated: 2023/07/31 13:02:27 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	update_time(t_philo *philo)
{
	pthread_mutex_lock(philo->m_time);
	philo->last_meal = get_time_ms();
	pthread_mutex_unlock(philo->m_time);
}
