#include "../../include/philosophers.h"

void	ft_putchar(char byte)
{
	write(STDOUT_FILENO, &byte, 1);
}
