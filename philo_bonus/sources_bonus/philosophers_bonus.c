/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:03:18 by adantas-          #+#    #+#             */
/*   Updated: 2023/08/03 16:16:30 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/philosophers_bonus.h"

static void	accept_your_fate(ssize_t lifetime)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		printf(PHILO_FORK, 0L, 1);
		usleep(lifetime * 1000);
		printf(PHILO_RIP, lifetime, 1);
		exit(0);
	}
	waitpid(pid, NULL, 0);
}

static void	select_simulation(int argc, char *argv[])
{
	unlink_semaphores();
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
