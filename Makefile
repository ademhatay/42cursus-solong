NAME = solong

FLAGS = -Wall -Wextra -Werror
SRC = ./src/solong.c \
	./src/ft_utils.c \
	./src/get_map.c \
	./src/check_arg.c \
	./src/check_map.c \
	./src/write_map.c \
	

RM = rm -rf

all:
	gcc -Wall -Wextra -Werror $(FLAGS) $(SRC)-framework OpenGL -framework AppKit -o $(NAME) "./minilibx/libmlx.a"

clean:
	rm -f $(NAME)
fclean: clean
re: fclean all