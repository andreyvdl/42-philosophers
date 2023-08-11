/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:42:01 by adantas-          #+#    #+#             */
/*   Updated: 2023/08/11 12:42:04 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/philosophers_bonus.h"

static void	kill_philos(int16_t nbr_philos, pid_t pids[], int16_t pos)
{
	while (++pos < nbr_philos)
		kill(pids[pos], SIGKILL);
}

static int	wait_for_kill(int16_t nbr_philos, pid_t pids[])
{
	int16_t	i;
	int		status;

	i = -1;
	while (++i < nbr_philos)
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE)
		{
			kill_philos(nbr_philos, pids, i);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

void	start_simulation(t_philo philos[], int16_t nbr_philos)
{
	pid_t	pids[MAX_PHILOS];
	int16_t	i;
	int		status;

	i = -1;
	while (++i < nbr_philos)
	{
		philos[i].starting = get_time_ms();
		philos[i].last_meal = philos[i].starting;
	}
	i = -1;
	while (++i < nbr_philos)
	{
		pids[i] = fork();
		if (pids[i] == 0)
			routine(&philos[i]);
	}
	usleep(100);
	status = wait_for_kill(nbr_philos, pids);
	close_semaphores(philos);
	unlink_semaphores();
	exit(status);
}
