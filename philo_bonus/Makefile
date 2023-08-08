# VARS ========================================================================
NAME=philo_bonus
FLAGS=-Wall -Wextra -Werror -g3 -pthread
SRC=finite_simulation_bonus.c \
	set_philos_finite_bonus.c \
	infinite_simulation_bonus.c \
	set_philos_infinite_bonus.c \
	forks_bonus.c \
	print_action_bonus.c \
	routine_bonus.c \
	ft_atol_bonus.c \
	ft_putstr_fd_bonus.c \
	get_time_ms_bonus.c \
	getter_bonus.c \
	close_semaphores_bonus.c \
	errors_bonus.c \
	philosophers_bonus.c \
	set_semaphores_bonus.c \
	start_simulation_bonus.c \
	unlink_semaphores_bonus.c \
	validator_bonus.c \
	am_i_alive_bonus.c
OBJS=${addprefix bin/, ${SRC:.c=.o}}
HEADER=include/philosophers.h
VPATH=sources_bonus\
	:sources_bonus/infinite_bonus\
	:sources_bonus/routine_bonus\
	:sources_bonus/utilities_bonus\
	:sources_bonus/finite_bonus

# COLORS ======================================================================
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
MAGENTA=\033[35m
CYAN=\033[36m
RESET=\033[0m

# RULES =======================================================================

all: ${NAME}
	@if [ ${HEADER} -nt ${NAME} ]; then \
		printf "${RED}${HEADER} is newer than ${NAME}! Recompiling${RESET}\n"; \
		make --no-print-directory re; \
	else \
		printf "${GREEN}${NAME} is up to date!${RESET}\n"; \
	fi

${NAME}: bin ${OBJS}
	@printf "${BLUE}All objects created!${RESET}\n"
	@cc ${FLAGS} -I include_bonus ${OBJS} -o $@
	@printf "${GREEN}${NAME} created!${RESET}\n"
	@exit 0

bin:
	@mkdir -p bin

bin/%.o: %.c
	@printf "${YELLOW}Compiling: ${CYAN}${notdir $<}${RESET}\n"
	@cc ${FLAGS} -I include_bonus -c $< -o $@

fclean: clean
	@rm -fr ${NAME}
	@printf "${RED}${NAME} removed!${RESET}\n"

clean:
	@rm -fr bin
	@printf "${YELLOW}Objects removed!${RESET}\n"

re: fclean ${NAME}

.PHONY: all clean fclean re
