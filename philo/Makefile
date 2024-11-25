NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread -g

GREEN=\033[1;32m
YELLOW=\033[1;33m
NC=\033[0m

HEADER = philo.h

SRCS = data_init.c philo.c utils.c dinner.c \
	   status.c set_get.c monitor.c \

OBJ_DIR = objs/

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

$(OBJ_DIR)%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)[files compiled]$(NC)"

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)
	@echo "$(YELLOW)[files cleaned]$(NC)"

re: fclean all