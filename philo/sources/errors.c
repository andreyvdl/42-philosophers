#include "../include/philosophers.h"

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
