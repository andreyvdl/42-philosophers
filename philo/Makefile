# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 21:20:11 by adantas-          #+#    #+#              #
#    Updated: 2023/07/31 12:14:01 by adantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARS ========================================================================
NAME=philo
FLAGS=-Wall -Wextra -Werror -pthread -g3
SRC=infinite_simulation.c \
	set_basic_infinite.c \
	eat.c \
	fork.c \
	print_action.c \
	routine.c \
	snooze.c \
	think.c \
	update_time.c \
	ft_atol.c \
	ft_putstr_fd.c \
	get_time_ms.c \
	getter.c \
	destroy_mutexes.c \
	died.c \
	errors.c \
	has_meals.c \
	philosophers.c \
	set_mutexes.c \
	start_simulation.c \
	validator.c \
	finite_simulation.c \
	set_basic_finite.c
OBJS=${addprefix bin/, ${SRC:.c=.o}}
HEADER=include/philosophers.h
VPATH=sources:sources/infinite:sources/routine:sources/utilities:sources/finite

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
	@cc ${FLAGS} -I include ${OBJS} -o $@
	@printf "${GREEN}${NAME} created!${RESET}\n"
	@exit 0

bin:
	@mkdir -p bin

bin/%.o: %.c
	@printf "${YELLOW}Compiling: ${CYAN}${notdir $<}${RESET}\n"
	@cc ${FLAGS} -I include -c $< -o $@

fclean: clean
	@rm -fr ${NAME}
	@printf "${RED}${NAME} removed!${RESET}\n"

clean:
	@rm -fr bin
	@printf "${YELLOW}Objects removed!${RESET}\n"

re: fclean ${NAME}

.PHONY: all clean fclean re
