NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g 
#CFLAGS += -fsanitize=address

LIB = -lpthread

SRC =   src/main.c \
		src/utils.c \
		src/utils/ft_atoi.c\
		src/utils/ft_isdigit.c \
		src/utils/ft_isnumber.c \
		src/utils/ft_strlen.c \
		src/init_philo.c \
		src/simulation.c 
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