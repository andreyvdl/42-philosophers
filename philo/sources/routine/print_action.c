/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:02:03 by adantas-          #+#    #+#             */
/*   Updated: 2023/08/11 12:30:22 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	print_action(t_philo *philo, char *str)
{
	if (nobody_died(philo))
	{
		pthread_mutex_lock(philo->m_print);
		printf(str, get_time_ms() - philo->starting, philo->id);
		pthread_mutex_unlock(philo->m_print);
	}
}
