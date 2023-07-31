/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_meals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:03:14 by adantas-          #+#    #+#             */
/*   Updated: 2023/07/31 13:03:16 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

bool	has_meals(t_philo *philo)
{
	bool	ret;

	pthread_mutex_lock(philo->m_meals);
	if (philo->meals == 0)
		ret = false;
	else
		ret = true;
	pthread_mutex_unlock(philo->m_meals);
	return (ret);
}
