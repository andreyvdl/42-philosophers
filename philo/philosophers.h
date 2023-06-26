#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

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
# define MAX_PHILOS 200
# define SSIZE_LIMIT 922337203685477
# define SSIZE_MAX_LEN 19
# define SSIZE_MAX_STR "9223372036854775807"

/* Philo text --------------------------------------------------------------- */

# define PHILO_EAT "\e[1;32m %d %d is eating\n\e[0m"
# define PHILO_RIP "\e[1;31m %d %d died\n\e[0m"
# define PHILO_FORK "\e[1;33m %d %d has taken a fork\n\e[0m"
# define PHILO_SLEEP "\e[1;36m %d %d is sleeping\n\e[0m"
# define PHILO_THINK "\e[1;35m %d %d is thinking\n\e[0m"

/* Errors ------------------------------------------------------------------- */

# define ERR_NBR_ARGS "\e[1;31mphilo: wrong number of arguments\e[0m\n"
# define EXEMPLE_INPUT "usage: \e[1;32m./philo\e[0m \
\e[1;4;31mnumber_of_philosophers\e[0m \e[1;4;31mtime_to_die\e[0m \
\e[1;4;31mtime_to_eat\e[0m \e[1;4;31mtime_to_sleep\e[0m \
[\e[1;3;31mnumber_of_times_each_philosopher_must_eat\e[0m]\n"
# define ERR_INPUT_WRONG "\e[1;31mphilo: this input is wrong `"
# define CLOSE_ERR_INPUT "`\e[0m\n"

/* Types ==================================================================== */

/**
 * @brief Smaller version of pthread_mutex_t;
 */
typedef pthread_mutex_t	t_pth_tex;

typedef struct s_test {
	ssize_t	nbr_philos;
	ssize_t	lifetime;
	ssize_t	launch_time;
	ssize_t	sleep_time;
	ssize_t	meals;
}	t_test;

/* Functions ================================================================ */

ssize_t	ft_atol(const char *str);
bool	values_are_valid(char *argv[]);
void	ft_putstr_fd(char *s, int fd);
void	infinite_sim(char *argv[]);
void	finite_sim(char *argv[]);

#endif
