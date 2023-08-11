/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:41:11 by adantas-          #+#    #+#             */
/*   Updated: 2023/08/11 12:41:12 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/philosophers_bonus.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (s && *s != '\0')
		write(fd, s++, 1);
}
