/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snooze.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:02:11 by adantas-          #+#    #+#             */
/*   Updated: 2023/07/31 13:02:15 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	snooze(t_philo *philo)
{
	print_action(philo, PHILO_SLEEP);
	usleep(philo->snooze_time * 1000);
}
