/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   died.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:03:08 by adantas-          #+#    #+#             */
/*   Updated: 2023/08/11 12:30:52 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

bool	nobody_died(t_philo *philo)
{
	bool	ret;

	pthread_mutex_lock(philo->m_getter);
	if (*get_died())
		ret = false;
	else
		ret = true;
	pthread_mutex_unlock(philo->m_getter);
	return (ret);
}
