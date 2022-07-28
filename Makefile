NAME = solong

FLAGS = -Wall -Wextra -Werror

SRC = ./src/solong.c \
	./src/ft_utils.c \
	./src/ft_utils2.c \
	./src/get_map.c \
	./src/check_arg.c \
	./src/check_map.c \
	./src/write_map.c \
	./src/game.c \
	./src/key_manager.c \
	./src/free_map.c \
	./src/move.c \
	

RM = rm -rf

all:
	cd ./minilibx && make all
	gcc -Wall -Wextra -Werror $(FLAGS) $(SRC)-framework OpenGL -framework AppKit -o $(NAME) "./minilibx/libmlx.a"

clean:
	$(RM) $(NAME)

cleanmlx:
		cd ./minilibx && make clean

fclean: clean cleanmlx


re: fclean all