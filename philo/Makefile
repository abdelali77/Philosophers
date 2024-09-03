# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/05 16:40:32 by abmahfou          #+#    #+#              #
#    Updated: 2024/09/03 14:36:08 by abmahfou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC 	   = cc
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread -g

VIVID_RED=\033[38;2;226;3;56m
NC=\033[0m

HEADER = philo.h

SRC = philo.c utils.c data_init.c

OBJ = $(SRC:.c=.o)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: p_philo $(NAME)

p_philo:
	@echo "                                      "
	@echo "$(VIVID_RED) ██▓███   ██░ ██  ██▓ ██▓     ▒█████  "
	@echo "▓██░  ██▒▓██░ ██▒▓██▒▓██▒    ▒██▒  ██▒"
	@echo "▓██░ ██▓▒▒██▀▀██░▒██▒▒██░    ▒██░  ██▒"
	@echo "▒██▄█▓▒ ▒░▓█ ░██ ░██░▒██░    ▒██   ██░"
	@echo "▒██▒ ░  ░░▓█▒░██▓░██░░██████▒░ ████▓▒░"
	@echo "▒▓▒░ ░  ░ ▒ ░░▒░▒░▓  ░ ▒░▓  ░░ ▒░▒░▒░ "
	@echo "░▒ ░      ▒ ░▒░ ░ ▒ ░░ ░ ▒  ░  ░ ▒ ▒░ "
	@echo "░░        ░  ░░ ░ ▒ ░  ░ ░   ░ ░ ░ ▒  "
	@echo "          ░  ░  ░ ░      ░  ░    ░ ░  $(NC)"
	@echo "                                      "

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re