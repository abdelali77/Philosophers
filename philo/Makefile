NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g

GREEN=\033[1;32m
YELLOW=\033[1;33m
NC=\033[0m

HEADER = philo.h

SRCS = data_init.c philo.c utils.c routine.c \
	   status.c set_get.c monitor.c \

OBJS = $(SRCS:.c=.o)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)[files compiled]$(NC)"

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@echo "$(YELLOW)[files cleaned]$(NC)"

re: fclean all

.PHONY: all clean fclean re