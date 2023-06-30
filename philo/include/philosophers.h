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
# define TIME_MAX 922337203685477
# define MAX_PHILOS 200
# define SSIZE_MAX_LEN 19
# define SSIZE_MAX_STR "9223372036854775807"

/* Philo text --------------------------------------------------------------- */

# define PHILO_EAT "\e[1;32m %d %d is eating\n\e[0m"
# define PHILO_RIP "\e[1;31m %d %d died\n\e[0m"
# define PHILO_FORK "\e[1;33m %d %d has taken a fork\n\e[0m"
# define PHILO_SLEEP "\e[1;36m %d %d is sleeping\n\e[0m"
# define PHILO_THINK "\e[1;35m %d %d is thinking\n\e[0m"

/* Errors ------------------------------------------------------------------- */

# define ERR_MALLOC "\e[1;31mphilo: malloc error\e[0m\n"
# define ERR_NBR_ARGS "\e[1;31mphilo: wrong number of arguments\e[0m\n"
# define EXEMPLE_INPUT "usage: \e[1;32m./philo\e[0m \
\e[1;4;3;31mnumber_of_philosophers\e[0m \e[1;4;3;31mtime_to_die\e[0m \
\e[1;4;3;31mtime_to_eat\e[0m \e[1;4;3;31mtime_to_sleep\e[0m \
[\e[1;4;3;31mnumber_of_times_each_philosopher_must_eat\e[0m]\n"
# define ERR_INPUT_WRONG "\e[1;31mphilo: this input is wrong `"
# define CLOSE_ERR_INPUT "`\e[0m\n"

/* Types ==================================================================== */

/**
 * @brief Smaller version of pthread_mutex_t;
 */
typedef pthread_mutex_t	t_pth_mutex;

/**
 * @brief States that the philosopher can be in;
 * 
 * @param E_DEAD The philosopher is dead;
 * @param E_EATING The philosopher should eat;
 * @param E_SLEEPING The philosopher should sleep;
 * @param E_THINKING The philosopher should think;
 */
typedef enum e_philo_state {
	E_DEAD = -1,
	E_EATING,
	E_SLEEPING,
	E_THINKING
}	t_state;

/**
 * @brief The philosopher's private data;
 * 
 * @param state The philosopher's state;
 * @param philo_forks The number of forks the philosopher has;
 * @param philo_meals The number of meals the philosopher has eaten;
 * @param last_meal The time when the philosopher last ate;
 */
typedef struct s_philo_private {
	t_state	state;
	uint8_t	philo_forks;
	size_t	philo_meals;
	time_t	last_meal;
}	t_philo_prv;

/**
 * @brief The philosopher's public data;
 * 
 * @param *forks_mutex The forks mutex;
 * @param *print_mutex The print mutex;
 * @param *state_mutex The state mutex;
 * @param private The philosopher's private data;
 * @param *lifetime The time the philosopher has to eat;
 * @param *lunch_time The time that the philo has to finish eating;
 * @param *snooze_time The time that the philo has to sleep;
 * @param *start_time The time when the simulation started;
 * @param table_forks The number of forks on the table;
 * @param id The philosopher's id;
 * @param nbr_of_philos The number of philosophers;
 */
typedef struct s_philo_public {
	t_pth_mutex	*forks_mutex;
	t_pth_mutex	*print_mutex;
	t_pth_mutex	*state_mutex;
	t_philo_prv	private;
	ssize_t		*lifetime;
	ssize_t		*lunch_time;
	ssize_t		*snooze_time;
	time_t		*start_time;
	uint8_t		*table_forks;
	uint8_t		id;
	uint8_t		nbr_of_philos;
}	t_philo_pub;

/* Functions ================================================================ */

bool	values_are_valid(char *argv[]);
ssize_t	ft_atol(const char *str);
time_t	get_time_ms(void);

void	start_simulation(t_philo_pub philos[]);
void	ft_putstr_fd(char *s, int fd);
void	infinite_sim(char *argv[]);
void	finite_sim(char *argv[]);
void	value_error(char *arg);
void	malloc_error(void);
void	argc_error(void);

#endif
