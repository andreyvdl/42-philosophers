#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <stdint.h>
# include <sys/time.h> // gettimeofday

/* Define =================================================================== */

/* Macros ------------------------------------------------------------------- */

# define MAX_PHILOS 200

/* Text --------------------------------------------------------------------- */

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

/* Types ==================================================================== */

/**
 * @brief Philosopher information;
 * 
 * @param id Philosopher number, id is always bigger than 0;
 * @param life_time Time for the philo die;
 * @param eat_time Time that the philo takes to drop the forks eat;
 * @param sleep_time Time that the philo is sleeping;
 * @param meals Number of meals;
 * @param last_meal last time philo ate;
 */
typedef struct s_philo
{
	uint16_t	id;
	time_t		life_time;
	time_t		eat_time;
	time_t		sleep_time;
	uint16_t	meals;
	time_t		last_meal;
}	t_philo;

/**
 * @brief Smaller version of pthread_mutex_t;
 */
typedef pthread_mutex_t	t_pth_tex;

#endif
