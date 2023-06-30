# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 21:20:11 by adantas-          #+#    #+#              #
#    Updated: 2023/06/30 17:16:58 by adantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARS ========================================================================
NAME=philo
FLAGS=-Wall -Wextra -Werror -g3
SRCS=philosophers.c \
	${addprefix sources/, validator.c errors.c get_time_ms.c start_simulation.c} \
	${addprefix sources/infinite/, infinite_simulation.c} \
	${addprefix sources/routine/, routine.c}
	${addprefix utilities/, ft_putstr_fd.c ft_atol.c}
OBJS=${SRCS:.c=.o}
HEADER=philosophers.h
SHELL:=/bin/bash

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
	@cc ${FLAGS} -I. ${OBJS} -o $@
	@printf "${GREEN}${NAME} created!${RESET}\n"
	@exit 0

%.o: %.c
	@printf "${YELLOW}Compiling: ${CYAN}${notdir $<}${RESET}\n"
	@cc ${FLAGS} -I. -c $< -o $@

fclean: clean
	@rm -fr ${NAME}
	@printf "${RED}${NAME} removed!${RESET}\n"

clean:
	@${foreach file, ${OBJS}, \
		if [ -f ${file} ]; then \
			printf "${YELLOW}Removing object file: ${MAGENTA}${notdir ${file}}${RESET}\n"; \
			rm -fr ${file}; \
		fi; \
	}
	@printf "${YELLOW}Objects removed!${RESET}\n"

re: fclean ${NAME}

.PHONY: all clean fclean re
