#include "../../include_bonus/philosophers_bonus.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (s && *s != '\0')
		write(fd, s++, 1);
}
