NAME = MazeOfKeys
SRC = source/main.c
OBJ = $(SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror
LIB_FLAG = -Llib/ft_printf -l:libftprintf.a -Lsource -l:so_long.a
MLX_FLAG =  -Lmlx -lmlx -Llib/minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz 
all: $(NAME)

$(NAME): $(OBJ)
	# @make -C lib/minilibx-linux
	@make -C source
	@make -C lib/ft_printf
	gcc $(OBJ) $(LIB_FLAG) $(MLX_FLAG)   -o $(NAME)

%.o: %.c
	gcc $(MLX_FLAG)   -c $< -o $@

all: $(NAME)

clean:
	@rm -rf $(OBJ)

	@echo "\033[0;32mObje dosyaları temizlendi.\033[0m"

fclean: clean
	@rm -rf $(NAME)

	@echo "\033[0;32mTüm derleme dosyaları temizlendi.\033[0m"

re: fclean all

.PHONY: re fclean clean all 
