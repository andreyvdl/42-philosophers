/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:03:11 by adantas-          #+#    #+#             */
/*   Updated: 2023/08/01 16:02:07 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

void	value_error(char *arg)
{
	ft_putstr_fd(ERR_INPUT_WRONG, STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(CLOSE_ERR_INPUT, STDERR_FILENO);
}

void	argc_error(void)
{
	ft_putstr_fd(ERR_NBR_ARGS, STDERR_FILENO);
	ft_putstr_fd(EXEMPLE_INPUT, STDERR_FILENO);
}
