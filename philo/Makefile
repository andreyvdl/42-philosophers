# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 21:20:11 by adantas-          #+#    #+#              #
#    Updated: 2023/07/11 13:56:18 by adantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARS ========================================================================
NAME=philo
FLAGS=-Wall -Wextra -Werror -pthread -g3
SRC=${addprefix utilities/, ft_atol.c ft_putstr_fd.c get_time_ms.c} \
	${addprefix sources/routine/, dead.c lunch.c routine_start.c snooze.c think.c \
	change_state.c} \
	${addprefix sources/infinite/, infinite_simulation.c set_philos_infinite.c} \
	${addprefix sources/, errors.c philosophers.c start_simulation.c validator.c}
OBJS=${SRC:.c=.o}
HEADER=include/philosophers.h

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

${NAME}: ${OBJS}
	@printf "${BLUE}All objects created!${RESET}\n"
	@cc ${FLAGS} -I include ${OBJS} -o $@
	@printf "${GREEN}${NAME} created!${RESET}\n"
	@exit 0

%.o: %.c
	@printf "${YELLOW}Compiling: ${CYAN}${notdir $<}${RESET}\n"
	@cc ${FLAGS} -I include -c $< -o $@

fclean: clean
	@rm -fr ${NAME}
	@printf "${RED}${NAME} removed!${RESET}\n"

clean:
	@rm -fr ${OBJS}
	@printf "${YELLOW}Objects removed!${RESET}\n"

re: fclean ${NAME}

.PHONY: all clean fclean re
