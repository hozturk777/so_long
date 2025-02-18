NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
		ft_printfutility.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ) : ft_printf.h

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean