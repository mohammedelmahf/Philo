NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g 
# CFLAGS += -fsanitize=thread

LIB = -lpthread

SRC =   src/main.c \
		src/utils.c \
		src/init_philo.c \
		src/simulation.c \
		src/observer.c \
		src/threads.c 
OBJ = $(SRC:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) $< -o $@

$(NAME): $(LIBFT) $(SRC)
		$(CC) $(SRC) $(CFLAGS) $(LIB) -o $(NAME)

all: $(NAME)

clean:
		@rm -rf $(OBJ)

fclean: clean
		@rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re