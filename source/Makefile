NAME = so_long.a
SRC = game_init.c 
OBJ = $(SRC:%.c=%.o)


# CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[0;32mObje dosyaları temizlendi.\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;32mTüm derleme dosyaları temizlendi.\033[0m"

re: fclean all

.PHONY: re fclean clean all 
