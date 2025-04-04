NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror
#CFLAGS += -fsanitize=address

LIB = -lpthread

SRC =   src/main.c \
		src/utils.c \
		src/ft_atoi.c

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