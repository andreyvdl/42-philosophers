#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <bits/pthreadtypes.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# include <stdint.h>
# include <stdbool.h>

/* Define =================================================================== */

/* Macros ------------------------------------------------------------------- */

# define NIL 0x0
# define TIME_MAX 922337203685477
# define MAX_PHILOS 200
# define SSIZE_MAX_LEN 19
# define SSIZE_MAX_STR "9223372036854775807"

/* Philo text --------------------------------------------------------------- */

# define PHILO_EAT "\e[1;32m %ld %d is eating\n\e[0m"
# define PHILO_RIP "\e[1;31m %ld %d died\n\e[0m"
# define PHILO_FORK "\e[1;33m %ld %d has taken a fork\n\e[0m"
# define PHILO_SLEEP "\e[1;36m %ld %d is sleeping\n\e[0m"
# define PHILO_THINK "\e[1;35m %ld %d is thinking\n\e[0m"

/* Errors ------------------------------------------------------------------- */

# define ERR_MALLOC "\e[1;31mphilo: malloc error\e[0m\n"
# define ERR_NBR_ARGS "\e[1;31mphilo: wrong number of arguments\e[0m\n"
# define EXEMPLE_INPUT "usage: \e[1;32m./philo\e[0m \
\e[1;4;3;31mnumber_of_philosophers\e[0m \e[1;4;3;31mtime_to_die\e[0m \
\e[1;4;3;31mtime_to_eat\e[0m \e[1;4;3;31mtime_to_sleep\e[0m \
[\e[1;4;3;31mnumber_of_times_each_philosopher_must_eat\e[0m]\n\n\
number_of_philosophers: from 0 to 200\n\
"
# define ERR_INPUT_WRONG "\e[1;31mphilo: this input is wrong `"
# define CLOSE_ERR_INPUT "`\e[0m\n"

/* Types ==================================================================== */

typedef struct s_philo
{
	pthread_mutex_t	*m_my_fork;
	pthread_mutex_t	*m_next_fork;
	pthread_mutex_t	*m_print;
	pthread_mutex_t	*m_time;
	pthread_mutex_t	*m_meals;
	
	size_t			meals;
	ssize_t			lifetime;
	ssize_t			lunch_time;
	ssize_t			snooze_time;
	int16_t			id;
}	t_philo;

/* Functions ================================================================ */

ssize_t	ft_atol(const char *str);

time_t	get_time_ms(void);

void	ft_putstr_fd(char *s, int fd);
void	value_error(char *arg);
void	malloc_error(void);
void	argc_error(void);

bool	values_are_valid(char *argv[]);

#endif
