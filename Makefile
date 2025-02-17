NAME = siksok
SRC = source/main.c
OBJ = $(SRC:%.c=%.o)
INCLUDES = -I./lib/minilibx-linux


# CFLAGS = -Wall -Wextra -Werror

MLX_FLAG =  -Lmlx -lmlx -Llib/minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJ)
	@make -C lib/minilibx-linux
	gcc $(OBJ) $(MLX_FLAG) $(INCLUDES)  -o $(NAME)

%.o: %.c
	gcc $(MLX_FLAG) $(INCLUDES)  -c $< -o $@

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

	@echo "\033[0;32mObje dosyaları temizlendi.\033[0m"

fclean: clean
	@rm -rf $(NAME)

	@echo "\033[0;32mTüm derleme dosyaları temizlendi.\033[0m"

re: fclean all

.PHONY: re fclean clean all 
