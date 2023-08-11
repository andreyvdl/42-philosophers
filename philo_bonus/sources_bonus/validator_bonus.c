/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:03:42 by adantas-          #+#    #+#             */
/*   Updated: 2023/08/11 12:42:36 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/philosophers_bonus.h"

static bool	bigger_than_max(char *arg)
{
	size_t	index;

	index = 0;
	while (SSIZE_MAX_STR[index] != '\0')
	{
		if (*arg > SSIZE_MAX_STR[index])
			return (true);
		else if (*arg < SSIZE_MAX_STR[index])
			break ;
		++index;
		++arg;
	}
	return (false);
}

static bool	number_too_big(char **arg)
{
	size_t	size;

	size = 0;
	if (**arg < '0' || **arg > '9')
		return (true);
	while ((*arg)[size] >= '0' && (*arg)[size] <= '9')
		++size;
	if (size > SSIZE_MAX_LEN)
		return (true);
	else if (size == SSIZE_MAX_LEN && bigger_than_max(*arg))
		return (true);
	while (**arg >= '0' && **arg <= '9')
		++(*arg);
	return (false);
}

static bool	found_something_wrong(char *arg)
{
	while (*arg != '\0')
	{
		while (*arg == ' ' || *arg == '\t')
			++arg;
		if (*arg == '-')
			return (true);
		else if (*arg == '+')
			++arg;
		if (number_too_big(&arg))
			return (true);
		if (*arg != '\0' && *arg != ' ' && *arg != '\t')
			return (true);
		while (*arg == ' ' || *arg == '\t')
			++arg;
		if (*arg != '\0')
			return (true);
	}
	return (false);
}

static bool	conversion_error(char *arg)
{
	static bool	first_time = true;
	ssize_t		nbr;

	nbr = ft_atol(arg);
	if (first_time)
	{
		first_time = false;
		if (nbr < 1 || nbr > 200)
			return (true);
	}
	else
	{
		if (nbr < 0 || nbr > TIME_MAX)
			return (true);
	}
	return (false);
}

bool	values_are_valid(char *argv[])
{
	while (*argv != NIL)
	{
		if (found_something_wrong(*argv) || conversion_error(*argv))
		{
			value_error(*argv);
			return (false);
		}
		++argv;
	}
	return (true);
}
