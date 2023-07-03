#include "philosophers.h"

ssize_t	ft_atol(const char *str)
{
	ssize_t	result;

	result = 0;
	while ((*str < '0' || *str > '9') && *str != '\0')
		++str;
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + (*str++ - '0');
	return (result);
}
