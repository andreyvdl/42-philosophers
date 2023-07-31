#include "../../include/philosophers.h"

void	ft_putnbr(ssize_t nbr)
{
	char	byte;

	if (nbr > 9)
		ft_putnbr(nbr / 10);
	byte = nbr % 10 - '0';
	write(STDOUT_FILENO, &byte, 1);
}
