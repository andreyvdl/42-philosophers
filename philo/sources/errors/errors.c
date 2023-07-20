#include "philosophers.h"

void	value_error(char *arg)
{
	write(STDERR_FILENO, ERR_INPUT_WRONG, sizeof(ERR_INPUT_WRONG));
	ft_putstr_fd(arg, STDERR_FILENO);
	write(STDERR_FILENO, CLOSE_ERR_INPUT, sizeof(CLOSE_ERR_INPUT));
}

void	malloc_error(void)
{
	write(STDERR_FILENO, ERR_MALLOC, sizeof(ERR_MALLOC));
}

void	argc_error(void)
{
	write(STDERR_FILENO, ERR_NBR_ARGS, sizeof(ERR_NBR_ARGS));
	write(STDERR_FILENO, EXEMPLE_INPUT, sizeof(EXEMPLE_INPUT));
}
