NAME = so_long.a
SRC = game_init.c \
		player_controller.c 
OBJ = $(SRC:%.c=%.o)


# CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ) : so_long.h

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean