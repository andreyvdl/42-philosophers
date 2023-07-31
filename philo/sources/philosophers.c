/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:03:18 by adantas-          #+#    #+#             */
/*   Updated: 2023/07/31 13:03:27 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	*memento_mori(void *arg)
{
	time_t	lifetime;

	lifetime = (time_t)arg;
	printf(PHILO_FORK, 0L, 1);
	usleep(lifetime * 1000);
	printf(PHILO_RIP, lifetime, 1);
	return (NIL);
}

static void	accept_your_fate(ssize_t lifetime)
{
	pthread_t	philo;

	pthread_create(&philo, NIL, &memento_mori, (void *)lifetime);
	pthread_join(philo, NIL);
}

static void	select_simulation(int argc, char *argv[])
{
	if (values_are_valid(argv))
	{
		if (ft_atol(*argv) == 1)
			accept_your_fate(ft_atol(argv[1]));
		else if (argc == 4)
			infinite_simulation(argv + 1, ft_atol(*argv));
		else
			finite_simulation(argv + 1, ft_atol(*argv));
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 5 || argc == 6)
		select_simulation(argc - 1, argv + 1);
	else
		argc_error();
	return (0);
}
