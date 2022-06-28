NAME = solong

SRC = ./src/solong.c ./src/ft_utils.c  ./src/get_and_control_map.c\


RM = rm -rf

all:
	gcc -Wall -Wextra -Werror $(SRC) -o ${NAME}

clean:
	rm -rf
