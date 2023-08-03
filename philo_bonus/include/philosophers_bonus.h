#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <fcntl.h>

# include <stdint.h>
# include <stdbool.h>

/* Define =================================================================== */
/* Macros ------------------------------------------------------------------- */

# define NIL 0x0
# define TIME_MAX 922337203685477
# define MAX_PHILOS 200
# define SSIZE_MAX_LEN 19
# define SSIZE_MAX_STR "9223372036854775807"
# define RNW 0644

/* Philo text --------------------------------------------------------------- */

# define PHILO_EAT "\e[1;32m%ld %d is eating\n\e[0m"
# define PHILO_RIP "\e[1;31m%ld %d died\n\e[0m"
# define PHILO_FORK "\e[1;33m%ld %d has taken a fork\n\e[0m"
# define PHILO_SLEEP "\e[1;36m%ld %d is sleeping\n\e[0m"
# define PHILO_THINK "\e[1;35m%ld %d is thinking\n\e[0m"

/* Errors ------------------------------------------------------------------- */

# define ERR_NBR_ARGS "\e[1;31mphilo: wrong number of arguments\e[0m\n"
# define EXEMPLE_INPUT "usage: \e[1;32m./philo\e[0m \
\e[1;4;3;31mnumber_of_philosophers\e[0m \e[1;4;3;31mtime_to_die\e[0m \
\e[1;4;3;31mtime_to_eat\e[0m \e[1;4;3;31mtime_to_sleep\e[0m \
[\e[1;4;3;31mnumber_of_times_each_philosopher_must_eat\e[0m]\n\n\
number_of_philosophers: from 1 to 200\n\
time_to_die: bigger than 0\n\
time_to_eat: bigger than 0\n\
time_to_sleep: bigger than 0\n\
number_of_times_each_philosopher_must_eat: bigger than 0\n\n"
# define ERR_INPUT_WRONG "\e[1;31mphilo: this input is wrong `"
# define CLOSE_ERR_INPUT "`\e[0m\n"

/* Types ==================================================================== */

/**
 * @brief Structure of a philosopher
 * 
 * @param *m_my_fork Mutex of the left fork
 * @param *m_next_fork Mutex of the right fork
 * @param *m_print Mutex of the print
 * @param *m_time Mutex of the time
 * @param *m_meals Mutex of the meals
 * @param *m_getter Mutex of the getter
 * @param meals Number of meals
 * @param lifetime Time to die
 * @param lunch_time Time to eat
 * @param snooze_time Time to sleep
 * @param starting Time of the start
 * @param id Id of the philosopher
 */
typedef struct s_philo
{
	pthread_mutex_t	*m_my_fork;
	pthread_mutex_t	*m_next_fork;
	pthread_mutex_t	*m_print;
	pthread_mutex_t	*m_time;
	pthread_mutex_t	*m_meals;
	pthread_mutex_t	*m_getter;
	size_t			meals;
	time_t			lifetime;
	time_t			lunch_time;
	time_t			snooze_time;
	time_t			last_meal;
	time_t			starting;
	int16_t			id;
}	t_philo;

/* Functions ================================================================ */
/* Utilities ---------------------------------------------------------------- */

ssize_t	ft_atol(const char *str);
time_t	get_time_ms(void);
bool	*get_died(void);
void	ft_putstr_fd(char *s, int fd);

/* Infinite ----------------------------------------------------------------- */

void	set_basic_infinite(t_philo philos[], char *argv[], int16_t nbr_philos);
void	infinite_simulation(char *argv[], int16_t nbr_philos);

/* Finite ------------------------------------------------------------------- */

void	set_basic_finite(t_philo philos[], char *argv[], int16_t nbr_philos);
void	finite_simulation(char *argv[], int16_t nbr_philos);

/* Routine ------------------------------------------------------------------ */

bool	has_meals(t_philo *philo);
void	print_action(t_philo *philo, char *str);
void	update_time(t_philo *philo);
void	drop_forks(t_philo *philo);
void	take_forks(t_philo *philo);
void	snooze(t_philo *philo);
void	think(t_philo *philo);
void	eat(t_philo *philo);
void	*routine(void *arg);

/* General ------------------------------------------------------------------ */

bool	values_are_valid(char *argv[]);
bool	nobody_died(t_philo *philo);
void	start_simulation(t_philo philos[], int16_t nbr_philos);
void	destroy_mutexes(t_philo philos[], int16_t nbr_philos);
void	set_mutex(t_philo philos[], int16_t nbr_philos);
void	value_error(char *arg);
void	argc_error(void);

#endif
