NAME = solong

SRC = ./src/solong.c ./src/ft_utils.c \


RM = rm -rf

all:
	gcc -Wall -Wextra -Werror $(SRC) -o ${NAME}

